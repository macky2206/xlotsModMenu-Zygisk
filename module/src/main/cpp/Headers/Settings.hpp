#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <Headers/Logger.hpp>
#include <algorithm>

namespace Settings {
    inline bool EnableModule = true;
    inline bool NoCooldown = false;
    inline bool UnlimitedMana = false;
    inline bool AlwaysLowestWave = false;
    inline bool UnlockTransmog = false;
    inline int RuneLevel = 1;
    inline bool SetRuneLevel = false;
    inline int ExpeditionMultiplier = 1;
    inline bool EnableExpeditionMultiplier = false;
    inline int SpeedHackValue = 1;
    inline bool FreeShopping = false;
    inline bool Set0Prices = false;
    inline bool ShowMenu = true;
    inline int MenuSize = 2;

    inline std::string ConfigPath;
    inline std::string BackupConfigPath = "/data/local/tmp/imgui_config.txt";

    inline std::string Trim(std::string s) {
        s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());
        s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
        s.erase(0, s.find_first_not_of(" \t"));
        s.erase(s.find_last_not_of(" \t") + 1);
        return s;
    }

    inline void SaveTo(const std::string& path) {
        if (path.empty()) return;
        std::ofstream file(path);
        if (file.is_open()) {
            file << "EnableModule=" << (EnableModule ? "1" : "0") << "\n";
            file << "NoCooldown=" << (NoCooldown ? "1" : "0") << "\n";
            file << "UnlimitedMana=" << (UnlimitedMana ? "1" : "0") << "\n";
            file << "AlwaysLowestWave=" << (AlwaysLowestWave ? "1" : "0") << "\n";
            file << "UnlockTransmog=" << (UnlockTransmog ? "1" : "0") << "\n";
            file << "RuneLevel=" << RuneLevel << "\n";
            file << "SetRuneLevel=" << (SetRuneLevel ? "1" : "0") << "\n";
            file << "ExpeditionMultiplier=" << ExpeditionMultiplier << "\n";
            file << "EnableExpeditionMultiplier=" << (EnableExpeditionMultiplier ? "1" : "0") << "\n";
            file << "SpeedHackValue=" << SpeedHackValue << "\n";
            file << "FreeShopping=" << (FreeShopping ? "1" : "0") << "\n";
            file << "Set0Prices=" << (Set0Prices ? "1" : "0") << "\n";
            file << "ShowMenu=" << (ShowMenu ? "1" : "0") << "\n";
            file << "MenuSize=" << MenuSize << "\n";
            file.close();
        }
    }

    inline void Save() {
        // Save to BOTH locations to keep them synced
        SaveTo(ConfigPath);
        SaveTo(BackupConfigPath);
        LOGI("Settings saved to both locations.");
    }

    inline bool LoadFrom(const std::string& path) {
        std::ifstream file(path);
        if (!file.is_open()) return false;

        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = Trim(line.substr(0, pos));
                std::string value = Trim(line.substr(pos + 1));

                if (key == "EnableModule") EnableModule = (value == "1");
                else if (key == "NoCooldown") NoCooldown = (value == "1");
                else if (key == "UnlimitedMana") UnlimitedMana = (value == "1");
                else if (key == "AlwaysLowestWave") AlwaysLowestWave = (value == "1");
                else if (key == "UnlockTransmog") UnlockTransmog = (value == "1");
                else if (key == "RuneLevel") { try { RuneLevel = std::stoi(value); } catch(...) {} }
                else if (key == "SetRuneLevel") SetRuneLevel = (value == "1");
                else if (key == "ExpeditionMultiplier") { try { ExpeditionMultiplier = std::stoi(value); } catch(...) {} }
                else if (key == "EnableExpeditionMultiplier") EnableExpeditionMultiplier = (value == "1");
                else if (key == "SpeedHackValue") { try { SpeedHackValue = std::stoi(value); } catch(...) {} }
                else if (key == "FreeShopping") FreeShopping = (value == "1");
                else if (key == "Set0Prices") Set0Prices = (value == "1");
                else if (key == "ShowMenu") ShowMenu = (value == "1");
                else if (key == "MenuSize") { try { MenuSize = std::stoi(value); } catch(...) {} }
            }
        }
        file.close();
        return true;
    }

    inline void Load() {
        // PRIORITIZE the backup path because that's what the WebUI writes to
        if (LoadFrom(BackupConfigPath)) {
            LOGI("Settings loaded from shared path (WebUI synced): %s", BackupConfigPath.c_str());
            // Mirror to primary if possible
            if (!ConfigPath.empty()) SaveTo(ConfigPath);
            return;
        }

        // Fallback to primary if shared doesn't exist
        if (!ConfigPath.empty() && LoadFrom(ConfigPath)) {
            LOGI("Settings loaded from primary: %s", ConfigPath.c_str());
            return;
        }

        LOGI("No config file found, using defaults.");
    }
}
