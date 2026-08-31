//
// Created by Reveny on 1/6/2025.
//
#include "Headers/ModMenu.hpp"
#include "Headers/Settings.hpp"
#include "Include/zygisk.hpp"
#include <sys/stat.h>
#include <unistd.h>

#define TARGET_PACKAGE std::string("com.frivolition.daysbygone")

using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

class MyModule : public zygisk::ModuleBase {
public:
    void onLoad(Api *_api, JNIEnv *_env) override {
        this->api = _api;
        this->env = _env;
    }

    void preAppSpecialize(AppSpecializeArgs *args) override {
        auto packageName = env->GetStringUTFChars(args->nice_name, nullptr);

        preSpecialize(packageName);
        env->ReleaseStringUTFChars(args->nice_name, packageName);
    }

    void postAppSpecialize(const AppSpecializeArgs *) override {
        if (!enableHack) {
            api->setOption(zygisk::Option::DLCLOSE_MODULE_LIBRARY);
            return;
        }

        // Load settings before starting thread
        Settings::Load();

        if (!Settings::EnableModule) {
            LOGI("Module disabled via config file. Exiting...");
            api->setOption(zygisk::Option::DLCLOSE_MODULE_LIBRARY);
            return;
        }

        // Run cheat
        std::thread([] {
            ModMenu::HackThread();
        }).detach();
    }
private:
    Api *api{};
    JNIEnv *env{};
    bool enableHack{};

    void preSpecialize(const char *packageName) {
        if (std::string(packageName) != TARGET_PACKAGE) {
            api->setOption(zygisk::Option::DLCLOSE_MODULE_LIBRARY);
            return;
        }

        LOGI("detect game: %s", packageName);

        // Set config path: /sdcard/Android/data/{pkg}/files/config.txt
        std::string filesDir = "/sdcard/Android/data/" + std::string(packageName) + "/files";

        // Ensure directories exist (might fail due to permissions, which is fine)
        mkdir("/sdcard/Android/data", 0777);
        mkdir(("/sdcard/Android/data/" + std::string(packageName)).c_str(), 0777);
        mkdir(filesDir.c_str(), 0777);

        Settings::ConfigPath = filesDir + "/config.txt";

        // Check if primary config exists, if not, attempt to copy from backup
        struct stat st{};
        if (stat(Settings::ConfigPath.c_str(), &st) != 0) {
            if (access(Settings::BackupConfigPath.c_str(), R_OK) == 0) {
                LOGI("Primary config missing. Copying from backup: %s", Settings::BackupConfigPath.c_str());
                std::ifstream src(Settings::BackupConfigPath, std::ios::binary);
                std::ofstream dst(Settings::ConfigPath, std::ios::binary);
                if (src && dst) {
                    dst << src.rdbuf();
                }
            }
        }

        enableHack = true;
    }
};

REGISTER_ZYGISK_MODULE(MyModule)
