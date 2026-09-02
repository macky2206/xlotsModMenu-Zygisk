//
// Created by Reveny on 1/6/2025.
//
#include <Headers/ModMenu.hpp>
#include <Headers/Drawing.hpp>
#include <Headers/Utility.hpp>
#include <Headers/Settings.hpp>
#include <Headers/LogManager.hpp>
#include <Features/DaysBygone.hpp>
#include <Features/StatsHack.hpp>

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
    LOGI("BNM: libil2cpp.so initialization detected! Unity is ready.");
    Features::InitAll();
}

void ApplyMenuScale(int width, int height) {
    float screenRatio = (float)height / 1080.0f;
    if (screenRatio < 0.5f) screenRatio = 0.5f;

    float multiplier = 1.0f;
    switch (Settings::MenuSize) {
        case 0: multiplier = 0.5f; break;
        case 1: multiplier = 0.75f; break;
        case 2: multiplier = 1.0f; break;
        case 3: multiplier = 1.3f; break;
        case 4: multiplier = 1.6f; break;
        default: multiplier = 1.0f; break;
    }

    float scale = 2.2f * screenRatio * multiplier;

    ImGuiStyle& style = ImGui::GetStyle();
    static bool firstInit = true;
    static ImGuiStyle defaultStyle;
    if (firstInit) {
        defaultStyle = style;
        firstInit = false;
    }
    style = defaultStyle;

    style.ScaleAllSizes(scale);
    ImGui::GetIO().FontGlobalScale = scale;
}

void ModMenu::DrawMenu(int width, int height) {
    if (!Settings::ShowMenu) return;

    static int lastMenuSize = -1;
    static int lastHeight = -1;
    if (lastMenuSize != Settings::MenuSize || lastHeight != height) {
        ApplyMenuScale(width, height);
        lastMenuSize = Settings::MenuSize;
        lastHeight = height;
    }

    ImGui::SetNextWindowSizeConstraints(ImVec2((float)width * 0.3f, (float)height * 0.4f), ImVec2((float)width * 0.95f, (float)height * 0.95f));
    ImGui::SetNextWindowSize(ImVec2((float)width * 0.5f, (float)height * 0.8f), ImGuiCond_FirstUseEver);

    if (ImGui::Begin("Mod Menu")) {
        if (ImGui::BeginTabBar("##tabs")) {

            if (ImGui::BeginTabItem("Main")) {
                if (ImGui::Checkbox("Always Lowest Wave", &Settings::AlwaysLowestWave)) Settings::SaveFeatures();
                if (ImGui::Checkbox("Unlock All Transmogs", &Settings::UnlockTransmog)) Settings::SaveFeatures();
                if (ImGui::Checkbox("Set Prices to 0", &Settings::Set0Prices)) Settings::SaveFeatures();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Stats")) {
                ImGui::TextDisabled("Open stat panel to capture pointers");
                ImGui::Separator();

                if (Features::StatsHack::AttackStatPtr) {
                    if (ImGui::Checkbox("Edit Attack (Dmg)", &Settings::EditAttackStat)) Settings::SaveFeatures();
                    if (Settings::EditAttackStat) {
                        if (ImGui::DragInt("Attack Value", &Settings::AttackStatBaseValue, 1.0f, 1, 100000000)) Settings::SaveFeatures();
                    }
                }

                if (Features::StatsHack::AgilityStatPtr) {
                    if (ImGui::Checkbox("Edit Agility (Atk Spd)", &Settings::EditAgilityStat)) Settings::SaveFeatures();
                    if (Settings::EditAgilityStat) {
                        if (ImGui::DragInt("Agility Value", &Settings::AgilityStatBaseValue, 1.0f, 1, 100000000)) Settings::SaveFeatures();
                    }
                }

                if (Features::StatsHack::HealthStatPtr) {
                    if (ImGui::Checkbox("Edit Health", &Settings::EditHealthStat)) Settings::SaveFeatures();
                    if (Settings::EditHealthStat) {
                        if (ImGui::DragInt("Health Value", &Settings::HealthStatBaseValue, 1.0f, 1, 100000000)) Settings::SaveFeatures();
                    }
                }

                if (!Features::StatsHack::AttackStatPtr && !Features::StatsHack::AgilityStatPtr && !Features::StatsHack::HealthStatPtr) {
                    ImGui::TextColored(ImVec4(1,0,0,1), "No stats captured yet!");
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Skills")) {
                if (ImGui::Checkbox("No Spell Cooldown", &Settings::NoCooldown)) Settings::SaveFeatures();
                if (ImGui::Checkbox("Unlimited Mana", &Settings::UnlimitedMana)) Settings::SaveFeatures();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Multipliers")) {
                ImGui::TextDisabled("Drag left/right to change");
                ImGui::Separator();

                if (ImGui::Checkbox("Set Rune Level", &Settings::SetRuneLevel)) Settings::SaveFeatures();
                if (Settings::SetRuneLevel) {
                    if (ImGui::DragInt("Rune Level", &Settings::RuneLevel, 0.5f, 1, 10000)) Settings::SaveFeatures();
                }

                ImGui::Separator();

                if (ImGui::Checkbox("Enable Expedition Multiplier", &Settings::EnableExpeditionMultiplier)) Settings::SaveFeatures();
                if (Settings::EnableExpeditionMultiplier) {
                    if (ImGui::DragInt("Expedition Value", &Settings::ExpeditionMultiplier, 1.0f, 1, 100000)) Settings::SaveFeatures();
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Logs")) {
                LogManager::DrawLogTab();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Settings")) {
                ImGui::Text("Hook Configuration (KernelSU)");
                ImGui::Separator();

                const char* sizeOptions[] = { "Smallest", "Smaller", "Default", "Bigger", "Biggest" };
                if (ImGui::Combo("UI Scale", &Settings::MenuSize, sizeOptions, IM_ARRAYSIZE(sizeOptions))) {
                    Settings::SaveHooks();
                }

                ImGui::Separator();

                if (ImGui::Button("Reload Hooks", ImVec2(-1, 0))) Settings::LoadHooks();
                if (ImGui::Button("Reload Features", ImVec2(-1, 0))) Settings::LoadFeatures();

                ImGui::Separator();
                bool isLoaded = BNM::Internal::states.state;
                ImGui::Text("BNM Status: %s", isLoaded ? "Ready" : "Initializing...");
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }
    }
    ImGui::End();
}

void ModMenu::HackThread() {
    LOGI("ModMenu: HackThread starting...");
    Drawing::InitMenu(DrawMenu);

    void* xdlHandle = nullptr;
    while (!xdlHandle) {
        xdlHandle = xdl_open(TARGET_LIBRARY, XDL_DEFAULT);
        if (!xdlHandle) sleep(1);
    }

    LOGI("ModMenu: %s found at %p. Initializing BNM...", TARGET_LIBRARY, xdlHandle);

    // Official BNM loading sequence
    BNM::Loading::AddOnLoadedEvent(BNMOnLoadedEvent);
    BNM::Loading::SetMethodFinder(MyBNMFinder, xdlHandle);

    // Allow BNM to hook deeper if the game is already in a late state
    BNM::Loading::AllowLateInitHook();

    if (BNM::Loading::TryLoadByUsersFinder()) {
        LOGI("ModMenu: BNM hooked successfully.");
    } else {
        LOGE("ModMenu: Failed to hook BNM!");
    }
}
