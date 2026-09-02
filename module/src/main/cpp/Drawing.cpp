//
// Created by Reveny on 1/6/2025.
//
#include <Headers/Drawing.hpp>
#include <Headers/Logger.hpp>
#include <Headers/Utility.hpp>
#include <BNM/BNMIncludes.hpp>

#include "dobby.h"
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_android.h"
#include "backends/android_native_app_glue.h"
#include "KittyMemory.h"
#include "Include/Roboto-Regular.h"
#include <mutex>

namespace Drawing
{
    std::function<void(int, int)> DrawFunction = nullptr;
    EGLBoolean (*SwapBuffers)(EGLDisplay dpy, EGLSurface surf) = nullptr;
    void (*OriginalInput)(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad, void *ex_ae, void *ex_af) = nullptr;
    int32_t (*OriginalConsume)(void *thiz, void *arg1, bool arg2, long arg3, uint32_t *arg4, AInputEvent **input_event) = nullptr;
    bool IsInitialized = false;
    int GlWidth = 0;
    int GlHeight = 0;
    std::mutex ImGuiMutex;

    // Soft Keyboard Helper
    void UpdateSoftKeyboard() {
        static bool lastWantTextInput = false;
        bool wantTextInput = ImGui::GetIO().WantTextInput;

        if (wantTextInput != lastWantTextInput) {
            if (wantTextInput) {
                // Find TouchScreenKeyboard.Open in UnityEngine.CoreModule
                auto image = BNM::Image("UnityEngine.CoreModule.dll");
                auto keyboardClass = BNM::Class("UnityEngine", "TouchScreenKeyboard", image);

                if (keyboardClass.IsValid()) {
                    // Try 8-argument version first (it's very common)
                    auto open8 = keyboardClass.GetMethod("Open", 8);
                    auto emptyStr = BNM::CreateMonoString("");

                    if (open8.IsValid()) {
                        // Open(text, type:0, autocorrect:false, multiline:false, secure:false, alert:false, placeholder:"", charLimit:0)
                        open8.cast<void*>().Call(emptyStr, 0, false, false, false, false, emptyStr, 0);
                        LOGI("Drawing: Opened Keyboard (8-arg)");
                    } else {
                        // Try 5-argument version
                        auto open5 = keyboardClass.GetMethod("Open", 5);
                        if (open5.IsValid()) {
                            open5.cast<void*>().Call(emptyStr, 0, false, false, false);
                            LOGI("Drawing: Opened Keyboard (5-arg)");
                        } else {
                            LOGE("Drawing: Could not find any TouchScreenKeyboard.Open method!");
                        }
                    }
                } else {
                    LOGE("Drawing: Could not find UnityEngine.TouchScreenKeyboard class!");
                }
            }
            lastWantTextInput = wantTextInput;
        }
    }
}

void Drawing::InitMenu(std::function<void(int, int)> drawFunction) {
    DrawFunction = std::move(drawFunction);

    while (!Utility::IsLibraryLoaded("libEGL.so") || !Utility::IsLibraryLoaded("libinput.so")) {
        sleep(1);
    }

    void* eglSwapBuffers = DobbySymbolResolver("libEGL.so", "eglSwapBuffers");
    if (eglSwapBuffers) {
        DobbyHook(eglSwapBuffers, (void *)SwapBuffersHook, (void **)&SwapBuffers);
    }

    const char* consumeSym = "_ZN7android13InputConsumer7consumeEPNS_26InputEventFactoryInterfaceEblPjPPNS_10InputEventE";
    void* consumeMethod = DobbySymbolResolver("libinput.so", consumeSym);

    if (consumeMethod) {
        DobbyHook(consumeMethod, (void *)ConsumeHook, (void **)&OriginalConsume);
    }
}

void Drawing::SetupMenu() {
    if (IsInitialized) return;

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;

    ImGui_ImplOpenGL3_Init("#version 300 es");
    ImGui_ImplAndroid_Init(nullptr);

    IsInitialized = true;
}

void Drawing::InternalDrawMenu(int width, int height) {
    if (!IsInitialized || !DrawFunction) return;

    std::lock_guard<std::mutex> lock(ImGuiMutex);

    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)width, (float)height);

    static bool fontLoaded = false;
    if (!fontLoaded) {
        float systemScale = (float)width / 2220.0f;
        if (systemScale < 1.0f) systemScale = 1.0f;
        io.Fonts->AddFontFromMemoryTTF(Roboto_Regular, sizeof(Roboto_Regular), 30.0f * systemScale);
        fontLoaded = true;
    }

    // Backup GL state
    GLint last_program, last_viewport[4];
    glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
    glGetIntegerv(GL_VIEWPORT, last_viewport);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(width, height);
    ImGui::NewFrame();

    DrawFunction(width, height);

    UpdateSoftKeyboard();

    ImGui::Render();

    glViewport(0, 0, width, height);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Restore state
    glUseProgram(last_program);
    glViewport(last_viewport[0], last_viewport[1], last_viewport[2], last_viewport[3]);
}

EGLBoolean Drawing::SwapBuffersHook(EGLDisplay dpy, EGLSurface surf) {
    if (!SwapBuffers) return EGL_TRUE;

    if (eglGetCurrentContext() == EGL_NO_CONTEXT) {
        return SwapBuffers(dpy, surf);
    }

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    if (viewport[2] > 0 && viewport[3] > 0) {
        SetupMenu();
        InternalDrawMenu(viewport[2], viewport[3]);
    }

    return SwapBuffers(dpy, surf);
}

void Drawing::InputHook(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad, void *ex_ae, void *ex_af) {
    if (OriginalInput) {
        OriginalInput(thiz, ex_ab, ex_ac, ex_ad, ex_ae, ex_af);
    }

    if (ex_ab != nullptr && IsInitialized) {
        std::lock_guard<std::mutex> lock(ImGuiMutex);
        ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)ex_ab);
    }
}

int32_t Drawing::ConsumeHook(void *thiz, void *arg1, bool arg2, long arg3, uint32_t *arg4, AInputEvent **input_event) {
    if (!OriginalConsume) return 0;
    int32_t res = OriginalConsume(thiz, arg1, arg2, arg3, arg4, input_event);

    if (IsInitialized && input_event && *input_event) {
        std::lock_guard<std::mutex> lock(ImGuiMutex);
        ImGui_ImplAndroid_HandleInputEvent(*input_event);
    }

    return res;
}
