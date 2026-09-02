#pragma once

#include <Headers/Settings.hpp>
#include <Headers/Logger.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>
#include <unordered_map>

#include "SDK/GlobalNamespace/PlayerAttributeValue.h"
#include "SDK/GlobalNamespace/StatUI.h"
#include "SDK/GlobalNamespace/StatContent.h"

namespace Features {
    namespace StatsHack {

        inline GlobalNamespace::PlayerAttributeValue* AttackStatPtr = nullptr;
        inline GlobalNamespace::PlayerAttributeValue* AgilityStatPtr = nullptr;
        inline GlobalNamespace::PlayerAttributeValue* HealthStatPtr = nullptr;

        inline std::unordered_map<void*, std::pair<double, double>> defaultValues;

        inline void applyToStat(GlobalNamespace::PlayerAttributeValue* attr, bool enableEdit, int baseValue) {
            if (!attr) return;

            if (enableEdit) {
                attr->set_baseValue((double)baseValue);
                attr->set_valueIncrement(0.0);
            } else {
                auto it = defaultValues.find((void*)attr);
                if (it != defaultValues.end()) {
                    attr->set_baseValue(it->second.first);
                    attr->set_valueIncrement(it->second.second);
                }
            }
        }

        inline void update() {
            if (!Settings::EnableModule) return;
            if (AttackStatPtr) applyToStat(AttackStatPtr, Settings::EditAttackStat, Settings::AttackStatBaseValue);
            if (AgilityStatPtr) applyToStat(AgilityStatPtr, Settings::EditAgilityStat, Settings::AgilityStatBaseValue);
            if (HealthStatPtr) applyToStat(HealthStatPtr, Settings::EditHealthStat, Settings::HealthStatBaseValue);
        }

        inline void init() {
            LOGI("StatsHack: Initialization complete (CustomClass registered)");
        }
    }
}

// Inject into the game's StatUI class to capture pointers automatically
struct StatUI_Capture : GlobalNamespace::StatUI {
    BNM_CustomClass(StatUI_Capture,
                    BNM::CompileTimeClassBuilder("", "StatUI").Build(),
                    BNM::Defaults::Get<BNM::UnityEngine::MonoBehaviour>(), {});

    void LateUpdate() {
        // Optimization: Only capture until we have both stats
        auto content = this->content<GlobalNamespace::StatContent*>();
        if (content) {
            auto valueObj = content->$value<GlobalNamespace::PlayerAttributeValue*>();
            if (valueObj) {
                int statId = valueObj->id();

                // 0 = Damage (Attack)
                if (statId == 0 && !Features::StatsHack::AttackStatPtr) {
                    Features::StatsHack::AttackStatPtr = valueObj;
                    Features::StatsHack::defaultValues[(void*)valueObj] = {valueObj->baseValue(), valueObj->valueIncrement()};
                    LOGI("StatsHack: Attack Stat (ID 0) captured via LateUpdate");
                }
                // 1 = FireRate (Agility/Attack Speed)
                else if (statId == 1 && !Features::StatsHack::AgilityStatPtr) {
                    Features::StatsHack::AgilityStatPtr = valueObj;
                    Features::StatsHack::defaultValues[(void*)valueObj] = {valueObj->baseValue(), valueObj->valueIncrement()};
                    LOGI("StatsHack: Agility Stat (ID 1) captured via LateUpdate");
                }
                // 6 = Health
                else if (statId == 6 && !Features::StatsHack::HealthStatPtr) {
                    Features::StatsHack::HealthStatPtr = valueObj;
                    Features::StatsHack::defaultValues[(void*)valueObj] = {valueObj->baseValue(), valueObj->valueIncrement()};
                    LOGI("StatsHack: Health Stat (ID 6) captured via LateUpdate");
                }
            }
        }

        // Always run the update to apply hacks in real-time
        Features::StatsHack::update();
    }

    BNM_CustomMethod(LateUpdate, false, BNM::Defaults::Get<void>(), "LateUpdate");
};
