#pragma once

#include <Headers/Logger.hpp>
#include <Headers/Settings.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>
#include <vector>

#include "Set0Prices.hpp"

namespace Features {

    #define HOOK(target, hook, original) DobbyHook((void*)target, (void*)hook, (void**)&original)

    namespace SpeedHack {
        void (*orig_AntiSpeedhack_ctor)(void* instance);
        void hooked_AntiSpeedhack_ctor(void* instance) { }

        void init() {
            auto clazz = BNM::Class("", "AntiSpeedhack");
            if (clazz.IsValid()) {
                auto ctor = clazz.GetMethod(".ctor");
                if (ctor.IsValid()) HOOK(ctor.GetOffset(), hooked_AntiSpeedhack_ctor, orig_AntiSpeedhack_ctor);
            }
        }

        void update() {
            static auto timeClass = BNM::Class("UnityEngine", "Time");
            static auto set_timeScale = timeClass.GetMethod("set_timeScale");
            if (set_timeScale.IsValid()) {
                float target = (float)Settings::SpeedHackValue;
                set_timeScale.cast<void>().Call(target);
            }
        }
    }

    namespace FreeShop {
        void (*orig_PurchaseItem)(void *instance);
        void hooked_PurchaseItem(void *instance) {
            if (Settings::FreeShopping) {
                auto complete = BNM::Class("", "StorePurchase").GetMethod("FJKEDCNLOAK");
                if (complete.IsValid()) {
                    complete.cast<void>()[instance].Call();
                    return;
                }
            }
            if (orig_PurchaseItem) orig_PurchaseItem(instance);
        }

        void init() {
            auto method = BNM::Class("", "StorePurchase").GetMethod("FBCOAEGAFIB");
            if (method.IsValid()) HOOK(method.GetOffset(), hooked_PurchaseItem, orig_PurchaseItem);
        }
    }

    namespace LowestWave {
        int (*orig_WaveCounts)(void *instance, int val);
        int hooked_WaveCounts(void *instance, int val) {
            return Settings::AlwaysLowestWave ? 1 : orig_WaveCounts(instance, val);
        }

        void init() {
            auto method = BNM::Class("", "StageGeneratorCampaign").GetMethod("DHGMIEAOFHE");
            if (method.IsValid()) HOOK(method.GetOffset(), hooked_WaveCounts, orig_WaveCounts);
        }
    }

    namespace Expedition {
        int (*orig_expTime)(void *instance);
        int hooked_expTime(void *instance) {
            return Settings::EnableExpeditionMultiplier ? Settings::ExpeditionMultiplier : orig_expTime(instance);
        }

        void init() {
            auto method = BNM::Class("", "ExpeditionManager").GetMethod("LCCGPGCHLGK");
            if (method.IsValid()) HOOK(method.GetOffset(), hooked_expTime, orig_expTime);
        }
    }

    namespace Equipment {
        bool (*orig_Transmog)(void *instance, int val);
        bool hooked_Transmog(void *instance, int val) {
            return Settings::UnlockTransmog ? true : orig_Transmog(instance, val);
        }

        void init() {
            auto method = BNM::Class("", "EquipmentsData").GetMethod("JKPPALMJPPO");
            if (method.IsValid()) HOOK(method.GetOffset(), hooked_Transmog, orig_Transmog);
        }
    }

    // --- Main Thread Logic ---

    void UpdateAll() {
        if (!Settings::EnableModule) return;
        SpeedHack::update();
    }

    void (*orig_Canvas_Update)();
    void hooked_Canvas_Update() {
        if (orig_Canvas_Update) orig_Canvas_Update();
        UpdateAll();
    }

    void InitAll() {
        LOGI("DaysBygone: Initializing hooks...");
        SpeedHack::init();
        FreeShop::init();
        LowestWave::init();
        Expedition::init();
        Equipment::init();

        // Separated feature
        set0Prices::init();

        // Hook a main thread method for continuous updates
        auto updateMethod = BNM::Class("UnityEngine", "Canvas").GetMethod("SendWillRenderCanvases");
        if (updateMethod.IsValid()) {
            BNM::InvokeHook(updateMethod, (void*)hooked_Canvas_Update, (void**)&orig_Canvas_Update);
            LOGI("DaysBygone: Main thread hook applied to Canvas.SendWillRenderCanvases");
        } else {
            LOGE("DaysBygone: Failed to find main thread hook point!");
        }
    }
}
