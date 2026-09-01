#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>
#include <vector>
#include <unordered_map>

#include "SDK/GlobalNamespace/GameDirectory.h"
#include "SDK/GlobalNamespace/SkillDirectory.h"
#include "SDK/GlobalNamespace/SkillAttribute.h"
#include "SDK/GlobalNamespace/SkillUI.h"
#include "SkillEnum.hpp"

namespace Features {
    namespace SkillsHack {

        inline std::vector<GlobalNamespace::SkillAttribute*> capturedSkills;
        inline std::unordered_map<void*, std::pair<double, double>> defaultValues; // id -> (base, inc)

        void (*orig_GameDir_Awake)(GlobalNamespace::GameDirectory* instance);
        void hooked_GameDir_Awake(GlobalNamespace::GameDirectory* instance) {
            if (orig_GameDir_Awake) orig_GameDir_Awake(instance);

            LOGI("SkillsHack: GameDirectory.Awake called, capturing skills...");

            auto skillDir = instance->skillDirectory<GlobalNamespace::SkillDirectory*>();
            if (skillDir) {
                capturedSkills.clear();
                // 28 is the expected skill count from reference
                for (int i = 0; i < 28; i++) {
                    auto attr = skillDir->gdq<GlobalNamespace::SkillAttribute*>(i);
                    if (attr) {
                        capturedSkills.push_back(attr);
                        // Save defaults if not already saved
                        if (defaultValues.find((void*)attr) == defaultValues.end()) {
                            defaultValues[(void*)attr] = {attr->baseValue(), attr->valueIncrement()};
                        }
                    }
                }
                LOGI("SkillsHack: Captured %zu skills", capturedSkills.size());
            }
        }

        void update() {
            if (!Settings::EnableModule) return;

            for (auto attr : capturedSkills) {
                int skillId = attr->id();

                if (skillId == (int)GlobalNamespace::SKILL::Spell_Cooldown_Reduction) {
                    if (Settings::NoCooldown) {
                        attr->set_baseValue(100.0);
                        attr->set_valueIncrement(0.0);
                    } else {
                        auto it = defaultValues.find((void*)attr);
                        if (it != defaultValues.end()) {
                            attr->set_baseValue(it->second.first);
                            attr->set_valueIncrement(it->second.second);
                        }
                    }
                }

                if (skillId == (int)GlobalNamespace::SKILL::Mana_Regen) {
                    if (Settings::UnlimitedMana) {
                        attr->set_baseValue(100000.0);
                        attr->set_valueIncrement(0.0);
                    } else {
                        auto it = defaultValues.find((void*)attr);
                        if (it != defaultValues.end()) {
                            attr->set_baseValue(it->second.first);
                            attr->set_valueIncrement(it->second.second);
                        }
                    }
                }
            }
        }

        void (*orig_SkillUI_LateUpdate)(GlobalNamespace::SkillUI* instance);
        void hooked_SkillUI_LateUpdate(GlobalNamespace::SkillUI* instance) {
            if (orig_SkillUI_LateUpdate) orig_SkillUI_LateUpdate(instance);
            update();
        }

        void init() {
            auto gameDir = BNM::Class("", "GameDirectory");
            if (gameDir.IsValid()) {
                auto m = gameDir.GetMethod("Awake");
                if (m.IsValid()) {
                    BNM::InvokeHook(m, (void*)hooked_GameDir_Awake, (void**)&orig_GameDir_Awake);
                }
            }

            auto skillUI = BNM::Class("", "SkillUI");
            if (skillUI.IsValid()) {
                // Hooking LateUpdate for continuous application
                auto m = skillUI.GetMethod("LateUpdate");
                if (m.IsValid()) {
                    BNM::InvokeHook(m, (void*)hooked_SkillUI_LateUpdate, (void**)&orig_SkillUI_LateUpdate);
                }
            }

            LOGI("SkillsHack: Initialized");
        }
    }
}
