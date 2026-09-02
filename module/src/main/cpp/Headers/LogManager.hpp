#pragma once
#include <string>
#include <vector>
#include <mutex>
#include <android/log.h>

namespace LogManager {
    struct LogEntry {
        int level;
        std::string tag;
        std::string message;
    };

    extern std::vector<LogEntry> Logs;
    extern std::mutex LogMutex;
    extern bool AutoScroll;

    void AddLog(int level, const char* tag, const char* fmt, ...);

    // UI function (to be called only when ImGui is available)
    void DrawLogTab();
}
