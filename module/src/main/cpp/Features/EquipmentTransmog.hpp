#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>

namespace Features {
    namespace Equipment {

        bool (*orig_Transmog)(void *instance, int val);
        bool hooked_Transmog(void *instance, int val) {
            if (Settings::UnlockTransmog) {
                return true;
            }
            return orig_Transmog != nullptr && orig_Transmog(instance, val);
        }

        void init() {
            auto clazz = BNM::Class("", "EquipmentsData");
            if (clazz.IsValid()) {
                // User mentioned the new function name is 'fbx'
                auto method = clazz.GetMethod("fbx");
                if (method.IsValid()) {
                    DobbyHook((void*)method.GetOffset(), (void*)hooked_Transmog, (void**)&orig_Transmog);
                    LOGI("EquipmentTransmog: Hooked fbx successfully");
                } else {
                    // Fallback to old name just in case
                    method = clazz.GetMethod("JKPPALMJPPO");
                    if (method.IsValid()) {
                        DobbyHook((void*)method.GetOffset(), (void*)hooked_Transmog, (void**)&orig_Transmog);
                        LOGI("EquipmentTransmog: Hooked JKPPALMJPPO successfully");
                    } else {
                        LOGE("EquipmentTransmog: Could not find method fbx or JKPPALMJPPO");
                    }
                }
            }
        }
    }
}
