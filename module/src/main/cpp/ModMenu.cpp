//
// Created by Reveny on 1/6/2025.
//
#include <Headers/ModMenu.hpp>
#include <Headers/Drawing.hpp>
#include <Headers/Utility.hpp>

#include "imgui.h"
#include "BNM/Loading.hpp"
#include "BNM/Class.hpp"
#include "xdl.h"
#include <dlfcn.h>

#define TARGET_LIBRARY "libil2cpp.so"

// Custom finder for BNM using xDL
// This allows BNM to find symbols even when dlopen() fails due to linker namespaces
static void* MyBNMFinder(const char* name, void* userData) {
    if (!userData) return nullptr;

    // First try dynamic symbols
    void* addr = xdl_sym(userData, name, nullptr);
    if (addr) return addr;

    // Then try all symbols (symbol table)
    return xdl_dsym(userData, name, nullptr);
}

void BNMOnLoadedEvent() {
    LOGI("BNM: libil2cpp.so initialization detected! BNM is now active.");

    // Example: Verification
    // auto clazz = BNM::Class("UnityEngine", "GameObject");
    // if (clazz) {
    //     LOGI("BNM: Found UnityEngine.GameObject at %p", clazz.GetIl2CppClass());
    // }

    LOGI("BNM: Initialization sequence finished. You can now apply BNM hooks.");
}

void ModMenu::DrawMenu(int width, int height) {
    ImGui::ShowDemoWindow();
}

void ModMenu::HackThread() {
    LOGI("ModMenu: HackThread started");

    // Initialize the drawing system
    Drawing::InitMenu(DrawMenu);

    LOGI("BNM: Waiting for %s in memory...", TARGET_LIBRARY);

    void* xdlHandle = nullptr;
    int waitCount = 0;
    while (!xdlHandle) {
        // XDL_DEFAULT only searches already loaded libraries
        xdlHandle = xdl_open(TARGET_LIBRARY, XDL_DEFAULT);
        if (!xdlHandle) {
            if (waitCount % 10 == 0) {
                LOGI("BNM: Still searching for %s... (%ds)", TARGET_LIBRARY, waitCount);
            }
            sleep(1);
            waitCount++;
        }
    }

    LOGI("BNM: %s found at %p after %ds", TARGET_LIBRARY, xdlHandle, waitCount);

    // Register the callback for when Unity finishes initialization
    BNM::Loading::AddOnLoadedEvent(BNMOnLoadedEvent);

    // Setup BNM to use our custom xDL-based symbol finder
    LOGI("BNM: Setting up custom symbol finder...");
    BNM::Loading::SetMethodFinder(MyBNMFinder, xdlHandle);

    // Tell BNM to use the finder to hook il2cpp_init
    if (BNM::Loading::TryLoadByUsersFinder()) {
        LOGI("BNM: Successfully hooked il2cpp_init via custom finder.");
    } else {
        LOGE("BNM: Failed to hook il2cpp_init using custom finder!");

        // Final fallback: try JNI load if everything else fails
        // This is a "hail mary" for Android 16
        // BNM::Loading::TryLoadByJNI(env);
    }

    LOGI("ModMenu: HackThread setup sequence complete.");

    // We don't close xdlHandle because MyBNMFinder uses it continuously
    // until il2cpp_init is called and BNM finishes its internal setup.
}
