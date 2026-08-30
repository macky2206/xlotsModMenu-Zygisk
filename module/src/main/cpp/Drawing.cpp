//
// Created by Reveny on 1/6/2025.
//
#include <Headers/Drawing.hpp>
#include <Headers/Logger.hpp>
#include <Headers/Utility.hpp>

#include "dobby.h"
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_android.h"
#include "backends/android_native_app_glue.h"
#include "KittyMemory.h"
#include "Include/Roboto-Regular.h"

namespace Drawing
{
    std::function<void(int, int)> DrawFunction = nullptr;
    EGLBoolean (*SwapBuffers)(EGLDisplay dpy, EGLSurface surf) = nullptr;
    void (*OriginalInput)(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad, void *ex_ae, void *ex_af) = nullptr;
    int32_t (*OriginalConsume)(void *thiz, void *arg1, bool arg2, long arg3, uint32_t *arg4, AInputEvent **input_event) = nullptr;
    bool IsInitialized = false;
    int GlWidth = 0;
    int GlHeight = 0;
}

void Drawing::InitMenu(std::function<void(int, int)> drawFunction) {
    LOGI("InitMenu started");
    DrawFunction = std::move(drawFunction);

    LOGI("Waiting for libEGL.so and libinput.so...");
    while (!Utility::IsLibraryLoaded("libEGL.so") || !Utility::IsLibraryLoaded("libinput.so")) {
        sleep(1);
    }
    LOGI("Libraries loaded. libEGL: 0x%lx, libinput: 0x%lx",
         Utility::GetBaseAddress("libEGL.so"), Utility::GetBaseAddress("libinput.so"));

    void* eglSwapBuffers = DobbySymbolResolver("libEGL.so", "eglSwapBuffers");
    if (eglSwapBuffers) {
        LOGI("Found eglSwapBuffers at %p, hooking...", eglSwapBuffers);
        DobbyHook(eglSwapBuffers, (void *)SwapBuffersHook, (void **)&SwapBuffers);
        LOGI("eglSwapBuffers hooked successfully");
    } else {
        LOGE("Failed to find eglSwapBuffers in libEGL.so");
    }

    // Prioritize Consume hook from ZygiskUnityMod
    const char* consumeSym = "_ZN7android13InputConsumer7consumeEPNS_26InputEventFactoryInterfaceEblPjPPNS_10InputEventE";
    void* consumeMethod = DobbySymbolResolver("libinput.so", consumeSym);

    if (consumeMethod) {
        LOGI("SUCCESS: Found InputConsumer::consume at %p, hooking...", consumeMethod);
        DobbyHook(consumeMethod, (void *)ConsumeHook, (void **)&OriginalConsume);
        LOGI("ConsumeHook applied successfully");
    } else {
        LOGI("Falling back to initializeMotionEvent candidates...");
        const char* inputLibs[] = {"libinput.so", "libgui.so", "libui.so"};
        const char* inputSymbols[] = {
            "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE",   // A10-A12
            "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageEb",  // A13
            "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageEbb", // A14+
            "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageEbbb",// A16+
            "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPNS_12InputMessageE"
        };

        void* inputMethod = nullptr;
        for (const char* lib : inputLibs) {
            if (!Utility::IsLibraryLoaded(lib)) continue;
            for (const char* sym : inputSymbols) {
                inputMethod = DobbySymbolResolver(lib, sym);
                if (inputMethod) {
                    LOGI("SUCCESS: Found %s in %s at %p", sym, lib, inputMethod);
                    DobbyHook(inputMethod, (void *)InputHook, (void **)&OriginalInput);
                    LOGI("InputHook applied successfully");
                    break;
                }
            }
            if (inputMethod) break;
        }

        if (!inputMethod) {
            LOGE("CRITICAL: All input hooking methods failed.");
        }
    }

    LOGI("Drawing initialization sequence finished");
}

void Drawing::SetupMenu() {
    if (IsInitialized) return;

    if (ImGui::GetCurrentContext() != nullptr) {
        ImGui::DestroyContext();
    }

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;

    // Setup Platform/Renderer backends
    ImGui_ImplOpenGL3_Init("#version 300 es");
    ImGui_ImplAndroid_Init(nullptr);

    ImGui::GetStyle().ScaleAllSizes(2.0f);

    IsInitialized = true;
    LOGI("ImGUI Setup done.");
}

void Drawing::InternalDrawMenu(int width, int height) {
    if (!IsInitialized) return;

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
    GLint last_program, last_vertex_array, last_array_buffer, last_element_array_buffer, last_viewport[4];
    glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &last_vertex_array);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &last_array_buffer);
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &last_element_array_buffer);
    glGetIntegerv(GL_VIEWPORT, last_viewport);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(width, height);
    ImGui::NewFrame();

    DrawFunction(width, height);

    ImGui::Render();

    // Set full viewport for ImGui
    glViewport(0, 0, width, height);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Restore GL state
    glUseProgram(last_program);
    glBindVertexArray(last_vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, last_array_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, last_element_array_buffer);
    glViewport(last_viewport[0], last_viewport[1], last_viewport[2], last_viewport[3]);
}

EGLBoolean Drawing::SwapBuffersHook(EGLDisplay dpy, EGLSurface surf) {
    if (eglGetCurrentContext() == EGL_NO_CONTEXT) {
        return SwapBuffers(dpy, surf);
    }

    // Use GL viewport for stability in Unity
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    int w = viewport[2];
    int h = viewport[3];

    if (w > 0 && h > 0) {
        if (GlWidth != w || GlHeight != h) {
            LOGI("Surface dimensions changed: %dx%d -> %dx%d", GlWidth, GlHeight, w, h);
            GlWidth = w;
            GlHeight = h;
        }

        SetupMenu();
        InternalDrawMenu(w, h);
    }

    return SwapBuffers(dpy, surf);
}

void Drawing::InputHook(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad, void *ex_ae, void *ex_af) {
    if (OriginalInput) {
        OriginalInput(thiz, ex_ab, ex_ac, ex_ad, ex_ae, ex_af);
    }

    if (ex_ab != nullptr && IsInitialized) {
        ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)ex_ab);
    }
}

int32_t Drawing::ConsumeHook(void *thiz, void *arg1, bool arg2, long arg3, uint32_t *arg4, AInputEvent **input_event) {
    int32_t res = OriginalConsume(thiz, arg1, arg2, arg3, arg4, input_event);

    if (IsInitialized && input_event && *input_event) {
        ImGui_ImplAndroid_HandleInputEvent(*input_event);
    }

    return res;
}
