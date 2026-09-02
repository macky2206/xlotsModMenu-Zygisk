#pragma once

#include <android/log.h>
#include "LogManager.hpp"

#define TAG "ModMenu"

// Log to both Logcat and in-game menu
#define LOGE(...) LogManager::AddLog(6, TAG, __VA_ARGS__)
#define LOGW(...) LogManager::AddLog(5, TAG, __VA_ARGS__)
#define LOGI(...) LogManager::AddLog(4, TAG, __VA_ARGS__)
#define LOGD(...) LogManager::AddLog(3, TAG, __VA_ARGS__)
