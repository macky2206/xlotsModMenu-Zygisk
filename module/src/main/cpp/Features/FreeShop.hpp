#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>

namespace Features {
    namespace FreeShop {

        void (*orig_PurchaseItem)(void *instance);
        void hooked_PurchaseItem(void *instance) {
            if (Settings::FreeShopping) {
                auto clazz = BNM::Class("", "StorePurchase");
                if (clazz.IsValid()) {
                    // User guessed 'njm' for complete purchase
                    auto completeMethod = clazz.GetMethod("njm");
                    if (completeMethod.IsValid()) {
                        completeMethod.cast<void>()[instance].Call();
                        LOGI("FreeShop: njm (Complete Purchase) called automatically");
                        return;
                    } else {
                        LOGE("FreeShop: Could not find method njm");
                    }
                }
            }
            if (orig_PurchaseItem) orig_PurchaseItem(instance);
        }

        void init() {
            auto clazz = BNM::Class("", "StorePurchase");
            if (clazz.IsValid()) {
                // User found 'njl' for Purchase UI call
                auto method = clazz.GetMethod("njl");
                if (method.IsValid()) {
                    DobbyHook((void*)method.GetOffset(), (void*)hooked_PurchaseItem, (void**)&orig_PurchaseItem);
                    LOGI("FreeShop: Hooked njl successfully");
                } else {
                    LOGE("FreeShop: Could not find method njl");
                }
            }
        }
    }
}
