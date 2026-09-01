#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>

namespace Features {
    namespace RuneLevel {

        int (*orig_GetRuneLevel)(void *instance, void* RuneContent, int param1, bool param2);
        int hook_GetRuneLevel(void *instance, void* RuneContent, int param1, bool param2 = true) {
            if (Settings::SetRuneLevel) {
                return Settings::RuneLevel;
            }
            return orig_GetRuneLevel ? orig_GetRuneLevel(instance, RuneContent, param1, param2) : 1;
        }

        void init() {
            auto clazz = BNM::Class("", "RuneData");
            if (clazz.IsValid()) {
                // New function name: fpl
                auto method = clazz.GetMethod("fpl");
                if (method.IsValid()) {
                    DobbyHook((void*)method.GetOffset(), (void*)hook_GetRuneLevel, (void**)&orig_GetRuneLevel);
                    LOGI("RuneLevel: Hooked fpl successfully");
                } else {
                    // Fallback to old name
                    method = clazz.GetMethod("PDCGPOMMPJH");
                    if (method.IsValid()) {
                        DobbyHook((void*)method.GetOffset(), (void*)hook_GetRuneLevel, (void**)&orig_GetRuneLevel);
                        LOGI("RuneLevel: Hooked PDCGPOMMPJH successfully");
                    } else {
                        LOGE("RuneLevel: Could not find method fpl or PDCGPOMMPJH");
                    }
                }
            }
        }
    }
}
