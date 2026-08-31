//
// Created by Reveny on 1/6/2025.
//
#include <Headers/ModMenu.hpp>
#include <Headers/Drawing.hpp>
#include <Headers/Utility.hpp>
#include <Headers/Settings.hpp>
#include <Features/DaysBygone.hpp>

#include "imgui.h"
#include "BNM/Loading.hpp"
#include "BNM/Class.hpp"
#include <Internals.hpp>
#include "xdl.h"
#include <dlfcn.h>

#define TARGET_LIBRARY "libil2cpp.so"

static void* MyBNMFinder(const char* name, void* userData) {
    if (!userData) return nullptr;
    void* addr = xdl_sym(userData, name, nullptr);
    if (addr) return addr;
    return xdl_dsym(userData, name, nullptr);
}

void BNMOnLoadedEvent() {
    LOGI("BNM: libil2cpp.so initialization detected!");
    Features::InitAll();
    LOGI("BNM: Initialization sequence finished.");
}

void ModMenu::DrawMenu(int width, int height) {
    // DO NOT call IL2CPP/BNM logic here anymore (Graphics Thread)
    // All hack updates are now handled in the Main Thread hook.

    if (!Settings::ShowMenu) return;

    ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Days Bygone Mod Menu", &Settings::ShowMenu)) {

        if (ImGui::Checkbox("Master Enable", &Settings::EnableModule)) Settings::Save();
        ImGui::Separator();

        ImGui::BeginDisabled(!Settings::EnableModule);

        if (ImGui::CollapsingHeader("Main Features", ImGuiTreeNodeFlags_DefaultOpen)) {
            if (ImGui::Checkbox("No Spell Cooldown", &Settings::NoCooldown)) Settings::Save();
            if (ImGui::Checkbox("Unlimited Mana", &Settings::UnlimitedMana)) Settings::Save();
            if (ImGui::Checkbox("Always Lowest Wave", &Settings::AlwaysLowestWave)) Settings::Save();
            if (ImGui::Checkbox("Unlock All Transmogs", &Settings::UnlockTransmog)) Settings::Save();
        }

        if (ImGui::CollapsingHeader("Multipliers")) {
            if (ImGui::Checkbox("Set Rune Level", &Settings::SetRuneLevel)) Settings::Save();
            if (Settings::SetRuneLevel) {
                if (ImGui::SliderInt("Rune Level", &Settings::RuneLevel, 1, 20)) Settings::Save();
            }

            if (ImGui::Checkbox("Enable Expedition Multiplier", &Settings::EnableExpeditionMultiplier)) Settings::Save();
            if (Settings::EnableExpeditionMultiplier) {
                if (ImGui::SliderInt("Expedition Value", &Settings::ExpeditionMultiplier, 1, 20)) Settings::Save();
            }

            if (ImGui::SliderInt("Speed Hack", &Settings::SpeedHackValue, 1, 25)) Settings::Save();
        }

        if (ImGui::CollapsingHeader("Dangerous Features")) {
            if (ImGui::Checkbox("Free Shopping", &Settings::FreeShopping)) Settings::Save();
            if (ImGui::Checkbox("Set Prices to 0", &Settings::Set0Prices)) Settings::Save();
        }

        ImGui::EndDisabled();

        ImGui::Separator();

        if (ImGui::Button("Save Settings")) Settings::Save();
        ImGui::SameLine();
        if (ImGui::Button("Reload Settings")) Settings::Load();

        ImGui::Separator();
        bool isLoaded = BNM::Internal::states.state;
        ImGui::Text("BNM Status: %s", isLoaded ? "Loaded" : "Waiting...");

        ImGui::End();
    }
}

void ModMenu::HackThread() {
    LOGI("ModMenu: HackThread started");
    Drawing::InitMenu(DrawMenu);

    void* xdlHandle = nullptr;
    while (!xdlHandle) {
        xdlHandle = xdl_open(TARGET_LIBRARY, XDL_DEFAULT);
        if (!xdlHandle) sleep(1);
    }

    LOGI("BNM: %s found at %p", TARGET_LIBRARY, xdlHandle);
    BNM::Loading::AddOnLoadedEvent(BNMOnLoadedEvent);
    BNM::Loading::SetMethodFinder(MyBNMFinder, xdlHandle);

    if (BNM::Loading::TryLoadByUsersFinder()) {
        LOGI("BNM: Successfully hooked il2cpp_init.");
    } else {
        LOGE("BNM: Failed to hook il2cpp_init!");
    }
}
