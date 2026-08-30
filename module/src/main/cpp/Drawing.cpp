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

    // Try multiple symbols for input initialization (mangled names vary by Android version)
    const char* inputSymbols[] = {
        "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE",  // A10-A12
        "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageEb", // A13+
        "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageEv", // Fallback 1
        "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPNS_12InputMessageE"    // Fallback 2
    };

    void* inputMethod = nullptr;
    for (const char* sym : inputSymbols) {
        LOGI("Trying to resolve input symbol: %s", sym);
        inputMethod = DobbySymbolResolver("libinput.so", sym);
        if (inputMethod) {
            LOGI("SUCCESS: Found input symbol: %s at %p", sym, inputMethod);
            break;
        }
    }

    if (inputMethod) {
        LOGI("Hooking inputMethod at %p...", inputMethod);
        DobbyHook(inputMethod, (void *)InputHook, (void **)&OriginalInput);
        LOGI("InputHook applied successfully");
    } else {
        LOGE("CRITICAL: Failed to find ANY InputConsumer::initializeMotionEvent symbol in libinput.so");
        LOGI("Falling back to search in libgui.so...");
        inputMethod = DobbySymbolResolver("libgui.so", inputSymbols[0]);
        if (inputMethod) {
             LOGI("Found input symbol in libgui.so at %p", inputMethod);
             DobbyHook(inputMethod, (void *)InputHook, (void **)&OriginalInput);
        } else {
             LOGE("Input initialization hook failed completely.");
        }
    }

    LOGI("Drawing initialization sequence finished");
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
    if (eglQuerySurface(dpy, surf, EGL_WIDTH, &w) && eglQuerySurface(dpy, surf, EGL_HEIGHT, &h)) {
        if (GlWidth != w || GlHeight != h) {
            LOGI("Surface dimensions changed: %dx%d -> %dx%d", GlWidth, GlHeight, w, h);
            GlWidth = w;
            GlHeight = h;
        }
    }

    SetupMenu();
    InternalDrawMenu(w, h);

    return SwapBuffers(dpy, surf);
}

void Drawing::InputHook(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad) {
    // Call original first to let it initialize the MotionEvent object
    if (OriginalInput) {
        ((void (*)(void *, void *, void *, void *))OriginalInput)(thiz, ex_ab, ex_ac, ex_ad);
    } else {
        LOGE("InputHook: OriginalInput is NULL!");
        return;
    }

    if (ex_ab != nullptr && IsInitialized && GlWidth > 0 && GlHeight > 0) {
        // Log touch event occasionally to avoid log flooding
        static int touchCount = 0;
        if (++touchCount % 100 == 0) {
            LOGI("Processing touch event #%d", touchCount);
        }
        ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)ex_ab);
    }
}