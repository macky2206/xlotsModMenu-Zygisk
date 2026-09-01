#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>

namespace Features {
    namespace Expedition {

        int (*orig_expTime)(void *instance);
        int hooked_expTime(void *instance) {
            if (Settings::EnableExpeditionMultiplier) {
                return Settings::ExpeditionMultiplier;
            }
            return orig_expTime ? orig_expTime(instance) : 0;
        }

        void init() {
            auto clazz = BNM::Class("", "ExpeditionManager");
            if (clazz.IsValid()) {
                // New function name: dvm
                auto method = clazz.GetMethod("dvm");
                if (method.IsValid()) {
                    DobbyHook((void*)method.GetOffset(), (void*)hooked_expTime, (void**)&orig_expTime);
                    LOGI("Expedition: Hooked dvm successfully");
                } else {
                    // Fallback to old name
                    method = clazz.GetMethod("LCCGPGCHLGK");
                    if (method.IsValid()) {
                        DobbyHook((void*)method.GetOffset(), (void*)hooked_expTime, (void**)&orig_expTime);
                        LOGI("Expedition: Hooked LCCGPGCHLGK successfully");
                    } else {
                        LOGE("Expedition: Could not find method dvm or LCCGPGCHLGK");
                    }
                }
            }
        }
    }
}
