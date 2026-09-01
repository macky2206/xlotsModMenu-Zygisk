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
}

void ApplyMenuScale() {
    float scale = 3.0f;
    switch (Settings::MenuSize) {
        case 0: scale = 1.5f; break;
        case 1: scale = 2.2f; break;
        case 2: scale = 3.0f; break;
        case 3: scale = 4.0f; break;
        case 4: scale = 5.0f; break;
        default: scale = 3.0f; break;
    }

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
    if (lastMenuSize != Settings::MenuSize) {
        ApplyMenuScale();
        lastMenuSize = Settings::MenuSize;
    }

    float windowScale = 0.7f;
    if (Settings::MenuSize == 0) windowScale = 0.4f;
    else if (Settings::MenuSize == 1) windowScale = 0.55f;
    else if (Settings::MenuSize == 3) windowScale = 0.85f;
    else if (Settings::MenuSize == 4) windowScale = 0.95f;

    ImGui::SetNextWindowSize(ImVec2((float)width * windowScale, (float)height * windowScale), ImGuiCond_FirstUseEver);

    if (ImGui::Begin("Mod Menu")) {
        if (ImGui::BeginTabBar("##tabs")) {

            if (ImGui::BeginTabItem("Main")) {
                if (ImGui::Checkbox("Always Lowest Wave", &Settings::AlwaysLowestWave)) Settings::Save();
                if (ImGui::Checkbox("Unlock All Transmogs", &Settings::UnlockTransmog)) Settings::Save();
                if (ImGui::Checkbox("Free Shopping", &Settings::FreeShopping)) Settings::Save();
                if (ImGui::Checkbox("Set Prices to 0", &Settings::Set0Prices)) Settings::Save();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Skills")) {
                if (ImGui::Checkbox("No Spell Cooldown", &Settings::NoCooldown)) Settings::Save();
                if (ImGui::Checkbox("Unlimited Mana", &Settings::UnlimitedMana)) Settings::Save();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Multipliers")) {
                ImGui::TextDisabled("Drag to change, Double-tap to type");
                ImGui::Separator();

                if (ImGui::Checkbox("Set Rune Level", &Settings::SetRuneLevel)) Settings::Save();
                if (Settings::SetRuneLevel) {
                    // DragInt allows for much larger ranges and fast increments
                    if (ImGui::DragInt("Rune Level", &Settings::RuneLevel, 0.5f, 1, 10000, "%d")) Settings::Save();
                }

                ImGui::Separator();

                if (ImGui::Checkbox("Enable Expedition Multiplier", &Settings::EnableExpeditionMultiplier)) Settings::Save();
                if (Settings::EnableExpeditionMultiplier) {
                    if (ImGui::DragInt("Expedition Value", &Settings::ExpeditionMultiplier, 1.0f, 1, 100000, "%d")) Settings::Save();
                }

                ImGui::Separator();
                ImGui::Text("Speed Hack (Disabled)");
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Settings")) {
                if (ImGui::Checkbox("Master Enable", &Settings::EnableModule)) Settings::Save();

                ImGui::Separator();

                const char* sizeOptions[] = { "Smallest", "Smaller", "Default", "Bigger", "Biggest" };
                if (ImGui::Combo("Menu Size", &Settings::MenuSize, sizeOptions, IM_ARRAYSIZE(sizeOptions))) {
                    Settings::Save();
                }

                ImGui::Separator();

                if (ImGui::Button("Save Settings", ImVec2(-1, 0))) Settings::Save();
                if (ImGui::Button("Reload Settings", ImVec2(-1, 0))) Settings::Load();

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
    Drawing::InitMenu(DrawMenu);

    void* xdlHandle = nullptr;
    while (!xdlHandle) {
        xdlHandle = xdl_open(TARGET_LIBRARY, XDL_DEFAULT);
        if (!xdlHandle) sleep(1);
    }

    LOGI("ModMenu: %s found at %p", TARGET_LIBRARY, xdlHandle);
    BNM::Loading::AddOnLoadedEvent(BNMOnLoadedEvent);
    BNM::Loading::SetMethodFinder(MyBNMFinder, xdlHandle);

    if (BNM::Loading::TryLoadByUsersFinder()) {
        LOGI("ModMenu: Successfully initialized BNM.");
    } else {
        LOGE("ModMenu: Failed to initialize BNM!");
    }
}
