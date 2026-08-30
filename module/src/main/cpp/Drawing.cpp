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
    void (*OriginalInput)(void *thiz, void *ex_ab, void *ex_ac) = nullptr;
    bool IsInitialized = false;
    int GlWidth = 0;
    int GlHeight = 0;
}

void Drawing::InitMenu(std::function<void(int, int)> drawFunction) {
    DrawFunction = std::move(drawFunction);

    LOGI("Waiting for libEGL.so and libinput.so...");
    while (!Utility::IsLibraryLoaded("libEGL.so") || !Utility::IsLibraryLoaded("libinput.so")) {
        sleep(1);
    }

    void* eglSwapBuffers = DobbySymbolResolver("libEGL.so", "eglSwapBuffers");
    if (eglSwapBuffers) {
        DobbyHook(eglSwapBuffers, (void *)SwapBuffersHook, (void **)&SwapBuffers);
        LOGI("eglSwapBuffers hooked");
    }

    // Try multiple symbols for input initialization
    const char* inputSymbols[] = {
        "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE",
        "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageEb"
    };

    void* inputMethod = nullptr;
    for (const char* sym : inputSymbols) {
        inputMethod = DobbySymbolResolver("libinput.so", sym);
        if (inputMethod) {
            LOGI("Found input symbol: %s", sym);
            break;
        }
    }

    if (inputMethod) {
        DobbyHook(inputMethod, (void *)InputHook, (void **)&OriginalInput);
        LOGI("InputHook applied");
    } else {
        LOGE("Failed to find InputConsumer::initializeMotionEvent");
    }

    LOGI("Drawing initialized");
}

void Drawing::SetupMenu() {
    if (IsInitialized) return;

    auto ctx = ImGui::CreateContext();
    if (!ctx) {
        LOGI("Failed to create context");
        return;
    }

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;

    // Setup Platform/Renderer backends
    ImGui_ImplAndroid_Init(nullptr);
    ImGui_ImplOpenGL3_Init("#version 300 es");

    ImGui::GetStyle().ScaleAllSizes(2.0f);

    IsInitialized = true;
    LOGI("ImGUI Setup done.");
}

void Drawing::InternalDrawMenu(int width, int height) {
    if (!IsInitialized) return;

    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)width, (float)height);

    // Initial font loading if not done
    static bool fontLoaded = false;
    if (!fontLoaded) {
        float systemScale = (float)width / 2220.0f;
        if (systemScale < 1.0f) systemScale = 1.0f;
        io.Fonts->AddFontFromMemoryTTF(Roboto_Regular, sizeof(Roboto_Regular), 30.0f * systemScale);
        fontLoaded = true;
    }

    // Backup GL state
    GLint last_program, last_vertex_array, last_array_buffer, last_element_array_buffer;
    glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &last_vertex_array);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &last_array_buffer);
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &last_element_array_buffer);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(width, height);
    ImGui::NewFrame();

    DrawFunction(width, height);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Restore GL state
    glUseProgram(last_program);
    glBindVertexArray(last_vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, last_array_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, last_element_array_buffer);
}

EGLBoolean Drawing::SwapBuffersHook(EGLDisplay dpy, EGLSurface surf) {
    EGLint w, h;
    eglQuerySurface(dpy, surf, EGL_WIDTH, &w);
    eglQuerySurface(dpy, surf, EGL_HEIGHT, &h);
    GlWidth = w;
    GlHeight = h;

    SetupMenu();
    InternalDrawMenu(w, h);

    return SwapBuffers(dpy, surf);
}

void Drawing::InputHook(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad) {
    // Call original first to let it initialize the MotionEvent object
    if (OriginalInput) {
        ((void (*)(void *, void *, void *, void *))OriginalInput)(thiz, ex_ab, ex_ac, ex_ad);
    }

    if (ex_ab != nullptr && IsInitialized && GlWidth > 0 && GlHeight > 0) {
        ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)ex_ab);
    }
}