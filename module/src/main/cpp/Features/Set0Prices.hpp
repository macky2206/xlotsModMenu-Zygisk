#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>
#include <unordered_map>
#include <vector>

#include "SDK/GlobalNamespace/CostAttribute.h"
#include "SDK/GlobalNamespace/SkillAttribute.h"
#include "SDK/GlobalNamespace/SkillContent.h"
#include "SDK/GlobalNamespace/SkillUI.h"
#include "SDK/GlobalNamespace/StatContent.h"
#include "SDK/GlobalNamespace/StatUI.h"
#include "SDK/UnityEngine/Object.h"

namespace Features {
    namespace set0Prices {

        struct DefaultCost {
            double baseValue;
            double valueIncrement;
        };

        inline std::unordered_map<void*, DefaultCost> defaultValues;

        // Rune Fusion Hooks
        int (*orig_RuneFusionCosts_1)(void *instance, int p1, int p2);
        int hook_RuneFusionCosts_1(void *instance, int p1, int p2) {
            return Settings::Set0Prices ? 0 : (orig_RuneFusionCosts_1 ? orig_RuneFusionCosts_1(instance, p1, p2) : 0);
        }

        int (*orig_RuneFusionCosts_2)(void *instance, int p1, int p2);
        int hook_RuneFusionCosts_2(void *instance, int p1, int p2) {
            return Settings::Set0Prices ? 0 : (orig_RuneFusionCosts_2 ? orig_RuneFusionCosts_2(instance, p1, p2) : 0);
        }

        double (*orig_RuneCloneCosts)(void* instance, int p1);
        double hook_RuneCloneCosts(void* instance, int p1) {
            return Settings::Set0Prices ? 0.0 : (orig_RuneCloneCosts ? orig_RuneCloneCosts(instance, p1) : 0.0);
        }

        // Hero Ascension Hooks
        int (*orig_HeroAscensionCosts)(void *instance, int p1, int p2);
        int hook_HeroAscensionCosts(void *instance, int p1, int p2) {
            return Settings::Set0Prices ? 0 : (orig_HeroAscensionCosts ? orig_HeroAscensionCosts(instance, p1, p2) : 0);
        }

        void init() {
            auto runeDir = BNM::Class("", "RuneDirectory");
            if (runeDir.IsValid()) {
                auto m1 = runeDir.GetMethod("GKMCFIBOLDE");
                if (m1.IsValid()) DobbyHook((void*)m1.GetOffset(), (void*)hook_RuneFusionCosts_1, (void**)&orig_RuneFusionCosts_1);

                auto m2 = runeDir.GetMethod("BPLFGPOHEBN");
                if (m2.IsValid()) DobbyHook((void*)m2.GetOffset(), (void*)hook_RuneFusionCosts_2, (void**)&orig_RuneFusionCosts_2);

                auto m3 = runeDir.GetMethod("KNOFHCMOIMF");
                if (m3.IsValid()) DobbyHook((void*)m3.GetOffset(), (void*)hook_RuneCloneCosts, (void**)&orig_RuneCloneCosts);
            }

            auto heroDir = BNM::Class("", "HeroDirectory");
            if (heroDir.IsValid()) {
                auto m = heroDir.GetMethod("PIICFHCDDOA");
                if (m.IsValid()) DobbyHook((void*)m.GetOffset(), (void*)hook_HeroAscensionCosts, (void**)&orig_HeroAscensionCosts);
            }

            LOGI("Set0Prices: Hooks initialized");
        }
    }
}

// Custom classes to handle UI updates using NEW SDK fields
struct StatUI_Hook : GlobalNamespace::StatUI {
    BNM_CustomClass(StatUI_Hook,
                    BNM::CompileTimeClassBuilder("", "StatUI").Build(),
                    BNM::Defaults::Get<BNM::UnityEngine::MonoBehaviour>(), {});

    void LateUpdate() {
        // Use 'content()' from new SDK
        auto content = this->content<GlobalNamespace::StatContent*>();
        if (content != nullptr) {
            // Use 'cost()' from new SDK
            auto cost = content->cost<GlobalNamespace::CostAttribute*>();
            if (cost != nullptr) {
                if (Features::set0Prices::defaultValues.find((void*)cost) == Features::set0Prices::defaultValues.end()) {
                    Features::set0Prices::defaultValues[(void*)cost] = {
                            cost->baseValue(),
                            cost->valueIncrement()};
                }

                if (Settings::Set0Prices) {
                    cost->set_baseValue(0.0);
                    cost->set_valueIncrement(0.0);
                } else {
                    auto it = Features::set0Prices::defaultValues.find((void*)cost);
                    if (it != Features::set0Prices::defaultValues.end()) {
                        cost->set_baseValue(it->second.baseValue);
                        cost->set_valueIncrement(it->second.valueIncrement);
                    }
                }
            }
        }
    }

    BNM_CustomMethod(LateUpdate, false, BNM::Defaults::Get<void>(), "LateUpdate");
};

struct SkillUI_Hook : GlobalNamespace::SkillUI {
    BNM_CustomClass(SkillUI_Hook,
                    BNM::CompileTimeClassBuilder("", "SkillUI").Build(),
                    BNM::Defaults::Get<BNM::UnityEngine::MonoBehaviour>(), {});

    void LateUpdate() {
        // Use 'content()' from new SDK
        auto content = this->content<GlobalNamespace::SkillContent*>();
        if (content != nullptr) {
            // Use 'cost()' from new SDK
            auto cost = content->cost<GlobalNamespace::CostAttribute*>();
            if (cost != nullptr) {
                if (Features::set0Prices::defaultValues.find((void*)cost) == Features::set0Prices::defaultValues.end()) {
                    Features::set0Prices::defaultValues[(void*)cost] = {
                            cost->baseValue(),
                            cost->valueIncrement()};
                }

                if (Settings::Set0Prices) {
                    cost->set_baseValue(0.0);
                    cost->set_valueIncrement(0.0);
                } else {
                    auto it = Features::set0Prices::defaultValues.find((void*)cost);
                    if (it != Features::set0Prices::defaultValues.end()) {
                        cost->set_baseValue(it->second.baseValue);
                        cost->set_valueIncrement(it->second.valueIncrement);
                    }
                }
            }
        }
    }

    BNM_CustomMethod(LateUpdate, false, BNM::Defaults::Get<void>(), "LateUpdate");
};
