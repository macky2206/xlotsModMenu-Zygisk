#pragma once

#include <Headers/Logger.hpp>
#include <Headers/Settings.hpp>
#include <BNM/BNMIncludes.hpp>
#include <dobby.h>
#include <vector>

#include "Set0Prices.hpp"
#include "EquipmentTransmog.hpp"
#include "Expedition.hpp"
#include "LowestWave.hpp"
#include "RuneLevel.hpp"
#include "StatsHack.hpp"

namespace Features {

    #define HOOK(target, hook, original) DobbyHook((void*)target, (void*)hook, (void**)&original)

    void InitAll() {
        LOGI("DaysBygone: Initializing hooks based on configuration...");

        if (Settings::InitLowestWave) {
            LowestWave::init();
        } else {
            LOGI("DaysBygone: LowestWave hook disabled by config");
        }

        if (Settings::InitExpedition) {
            Expedition::init();
        } else {
            LOGI("DaysBygone: Expedition hook disabled by config");
        }

        if (Settings::InitEquipment) {
            Equipment::init();
        } else {
            LOGI("DaysBygone: Equipment hook disabled by config");
        }

        if (Settings::InitSet0Prices) {
            set0Prices::init();
        } else {
            LOGI("DaysBygone: set0Prices hook disabled by config");
        }

        if (Settings::InitRuneLevel) {
            RuneLevel::init();
        } else {
            LOGI("DaysBygone: RuneLevel hook disabled by config");
        }

        if (Settings::InitStatsHack) {
            StatsHack::init();
        } else {
            LOGI("DaysBygone: StatsHack hook disabled by config");
        }

        LOGI("DaysBygone: Hook initialization sequence finished");
    }
}
