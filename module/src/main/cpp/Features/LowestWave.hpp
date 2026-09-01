#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>

namespace Features {
    namespace LowestWave {

        int (*orig_WaveCounts)(void *instance, int val);
        int hooked_WaveCounts(void *instance, int val) {
            if (Settings::AlwaysLowestWave) {
                return 1;
            }
            return orig_WaveCounts ? orig_WaveCounts(instance, val) : 1;
        }

        void init() {
            auto clazz = BNM::Class("", "StageGeneratorCampaign");
            if (clazz.IsValid()) {
                // New function name: myp
                auto method = clazz.GetMethod("myp");
                if (method.IsValid()) {
                    DobbyHook((void*)method.GetOffset(), (void*)hooked_WaveCounts, (void**)&orig_WaveCounts);
                    LOGI("LowestWave: Hooked myp successfully");
                } else {
                    // Fallback to old name
                    method = clazz.GetMethod("DHGMIEAOFHE");
                    if (method.IsValid()) {
                        DobbyHook((void*)method.GetOffset(), (void*)hooked_WaveCounts, (void**)&orig_WaveCounts);
                        LOGI("LowestWave: Hooked DHGMIEAOFHE successfully");
                    } else {
                        LOGE("LowestWave: Could not find method myp or DHGMIEAOFHE");
                    }
                }
            }
        }
    }
}
