//
// Created by Reveny on 1/6/2025.
//
#pragma once

#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <android/input.h>
#include <functional>
#include <utility>
#include <unistd.h>
#include <mutex>

namespace Drawing
{
    extern std::function<void(int, int)> DrawFunction;
    extern EGLBoolean (*SwapBuffers)(EGLDisplay dpy, EGLSurface surf);
    extern void (*OriginalInput)(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad, void *ex_ae, void *ex_af);
    extern int32_t (*OriginalConsume)(void *thiz, void *arg1, bool arg2, long arg3, uint32_t *arg4, AInputEvent **input_event);
    extern bool IsInitialized;
    extern int GlWidth;
    extern int GlHeight;
    extern std::mutex ImGuiMutex;

    void InitMenu(std::function<void(int, int)> drawFunction);
    void SetupMenu();
    void InternalDrawMenu(int width, int height);

    // Hooks
    void InputHook(void *thiz, void *ex_ab, void *ex_ac, void *ex_ad, void *ex_ae, void *ex_af);
    int32_t ConsumeHook(void *thiz, void *arg1, bool arg2, long arg3, uint32_t *arg4, AInputEvent **input_event);
    EGLBoolean SwapBuffersHook(EGLDisplay dpy, EGLSurface surf);
}
