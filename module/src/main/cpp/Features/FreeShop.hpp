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
                // User specified the new class and method for complete purchase
                auto clazz = BNM::Class("", "StorePurchaseCost");
                if (clazz.IsValid()) {
                    auto completeMethod = clazz.GetMethod("nbk");
                    if (completeMethod.IsValid()) {
                        // We attempt to call it on the current instance
                        // Note: If instance isn't a StorePurchaseCost, this might crash,
                        // but usually these classes are related in the same hierarchy.
                        completeMethod.cast<void>()[instance].Call();
                        LOGI("FreeShop: StorePurchaseCost.nbk (Complete Purchase) called");
                        return;
                    } else {
                        LOGE("FreeShop: Could not find method nbk in StorePurchaseCost");
                    }
                } else {
                    LOGE("FreeShop: Could not find class StorePurchaseCost");
                }
            }
            if (orig_PurchaseItem) orig_PurchaseItem(instance);
        }

        void init() {
            auto clazz = BNM::Class("", "StorePurchase");
            if (clazz.IsValid()) {
                // Hook 'njl' (Purchase UI call) as found by user
                auto method = clazz.GetMethod("njl");
                if (method.IsValid()) {
                    DobbyHook((void*)method.GetOffset(), (void*)hooked_PurchaseItem, (void**)&orig_PurchaseItem);
                    LOGI("FreeShop: Hooked StorePurchase.njl successfully");
                } else {
                    LOGE("FreeShop: Could not find method njl in StorePurchase");
                }
            }
        }
    }
}
