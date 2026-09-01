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
#include "FreeShop.hpp"
#include "SkillsHack.hpp"

namespace Features {

    #define HOOK(target, hook, original) DobbyHook((void*)target, (void*)hook, (void**)&original)

    void InitAll() {
        LOGI("DaysBygone: Initializing hooks...");

        FreeShop::init();
        LowestWave::init();
        Expedition::init();
        Equipment::init();
        set0Prices::init();
        RuneLevel::init();
        SkillsHack::init();
    }
}
