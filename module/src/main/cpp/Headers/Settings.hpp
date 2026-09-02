#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <Headers/Logger.hpp>
#include <algorithm>

namespace Settings {
    // --- HOOK CONFIG (Managed by WebUI and Startup) ---
    inline bool EnableModule = true;
    inline int MenuSize = 2;
    inline bool InitLowestWave = true;
    inline bool InitExpedition = true;
    inline bool InitEquipment = true;
    inline bool InitSet0Prices = true;
    inline bool InitRuneLevel = true;
    inline bool InitStatsHack = true;

    // --- FEATURE CONFIG (Auto-saved In-Game) ---
    inline bool EditAttackStat = false;
    inline int AttackStatBaseValue = 1000;
    inline bool EditAgilityStat = false;
    inline int AgilityStatBaseValue = 1000;
    inline bool EditHealthStat = false;
    inline int HealthStatBaseValue = 10000;

    inline bool NoCooldown = false;
    inline bool UnlimitedMana = false;

    inline bool AlwaysLowestWave = false;
    inline bool UnlockTransmog = false;
    inline int RuneLevel = 1;
    inline bool SetRuneLevel = false;
    inline int ExpeditionMultiplier = 1;
    inline bool EnableExpeditionMultiplier = false;
    inline int SpeedHackValue = 1;
    inline bool Set0Prices = false;
    inline bool ShowMenu = true;

    // Paths
    inline std::string HookConfigPath = "/data/local/tmp/imgui_hooks.txt";
    inline std::string FeaturesConfigPath;

    inline std::string Trim(std::string s) {
        s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());
        s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
        s.erase(0, s.find_first_not_of(" \t"));
        s.erase(s.find_last_not_of(" \t") + 1);
        return s;
    }

    // --- HOOK SAVING/LOADING ---
    inline void SaveHooks() {
        std::ofstream file(HookConfigPath);
        if (file.is_open()) {
            file << "EnableModule=" << (EnableModule ? "1" : "0") << "\n";
            file << "MenuSize=" << MenuSize << "\n";
            file << "InitLowestWave=" << (InitLowestWave ? "1" : "0") << "\n";
            file << "InitExpedition=" << (InitExpedition ? "1" : "0") << "\n";
            file << "InitEquipment=" << (InitEquipment ? "1" : "0") << "\n";
            file << "InitSet0Prices=" << (InitSet0Prices ? "1" : "0") << "\n";
            file << "InitRuneLevel=" << (InitRuneLevel ? "1" : "0") << "\n";
            file << "InitStatsHack=" << (InitStatsHack ? "1" : "0") << "\n";
            file.close();
            LOGI("Hooks config saved to %s", HookConfigPath.c_str());
        }
    }

    inline void LoadHooks() {
        std::ifstream file(HookConfigPath);
        if (!file.is_open()) return;
        LOGI("Loading hooks config from %s", HookConfigPath.c_str());
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = Trim(line.substr(0, pos));
                std::string value = Trim(line.substr(pos + 1));
                if (key == "EnableModule") EnableModule = (value == "1");
                else if (key == "MenuSize") { try { MenuSize = std::stoi(value); } catch(...) {} }
                else if (key == "InitLowestWave") InitLowestWave = (value == "1");
                else if (key == "InitExpedition") InitExpedition = (value == "1");
                else if (key == "InitEquipment") InitEquipment = (value == "1");
                else if (key == "InitSet0Prices") InitSet0Prices = (value == "1");
                else if (key == "InitRuneLevel") InitRuneLevel = (value == "1");
                else if (key == "InitStatsHack") InitStatsHack = (value == "1");
            }
        }
    }

    // --- FEATURE SAVING/LOADING ---
    inline void SaveFeatures() {
        if (FeaturesConfigPath.empty()) return;
        std::ofstream file(FeaturesConfigPath);
        if (file.is_open()) {
            file << "EditAttackStat=" << (EditAttackStat ? "1" : "0") << "\n";
            file << "AttackStatBaseValue=" << AttackStatBaseValue << "\n";
            file << "EditAgilityStat=" << (EditAgilityStat ? "1" : "0") << "\n";
            file << "AgilityStatBaseValue=" << AgilityStatBaseValue << "\n";
            file << "EditHealthStat=" << (EditHealthStat ? "1" : "0") << "\n";
            file << "HealthStatBaseValue=" << HealthStatBaseValue << "\n";
            file << "NoCooldown=" << (NoCooldown ? "1" : "0") << "\n";
            file << "UnlimitedMana=" << (UnlimitedMana ? "1" : "0") << "\n";
            file << "AlwaysLowestWave=" << (AlwaysLowestWave ? "1" : "0") << "\n";
            file << "UnlockTransmog=" << (UnlockTransmog ? "1" : "0") << "\n";
            file << "RuneLevel=" << RuneLevel << "\n";
            file << "SetRuneLevel=" << (SetRuneLevel ? "1" : "0") << "\n";
            file << "ExpeditionMultiplier=" << ExpeditionMultiplier << "\n";
            file << "EnableExpeditionMultiplier=" << (EnableExpeditionMultiplier ? "1" : "0") << "\n";
            file << "Set0Prices=" << (Set0Prices ? "1" : "0") << "\n";
            file << "ShowMenu=" << (ShowMenu ? "1" : "0") << "\n";
            file.close();
            LOGI("Features auto-saved.");
        }
    }

    inline void LoadFeatures() {
        if (FeaturesConfigPath.empty()) return;
        std::ifstream file(FeaturesConfigPath);
        if (!file.is_open()) return;
        LOGI("Loading features config from %s", FeaturesConfigPath.c_str());
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = Trim(line.substr(0, pos));
                std::string value = Trim(line.substr(pos + 1));
                if (key == "EditAttackStat") EditAttackStat = (value == "1");
                else if (key == "AttackStatBaseValue") { try { AttackStatBaseValue = std::stoi(value); } catch(...) {} }
                else if (key == "EditAgilityStat") EditAgilityStat = (value == "1");
                else if (key == "AgilityStatBaseValue") { try { AgilityStatBaseValue = std::stoi(value); } catch(...) {} }
                else if (key == "EditHealthStat") EditHealthStat = (value == "1");
                else if (key == "HealthStatBaseValue") { try { HealthStatBaseValue = std::stoi(value); } catch(...) {} }
                else if (key == "NoCooldown") NoCooldown = (value == "1");
                else if (key == "UnlimitedMana") UnlimitedMana = (value == "1");
                else if (key == "AlwaysLowestWave") AlwaysLowestWave = (value == "1");
                else if (key == "UnlockTransmog") UnlockTransmog = (value == "1");
                else if (key == "RuneLevel") { try { RuneLevel = std::stoi(value); } catch(...) {} }
                else if (key == "SetRuneLevel") SetRuneLevel = (value == "1");
                else if (key == "ExpeditionMultiplier") { try { ExpeditionMultiplier = std::stoi(value); } catch(...) {} }
                else if (key == "EnableExpeditionMultiplier") EnableExpeditionMultiplier = (value == "1");
                else if (key == "Set0Prices") Set0Prices = (value == "1");
                else if (key == "ShowMenu") ShowMenu = (value == "1");
            }
        }
    }
}
