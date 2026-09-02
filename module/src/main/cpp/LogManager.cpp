#include <Headers/LogManager.hpp>
#include <cstdio>
#include <cstdarg>
#include <algorithm>
#include <imgui.h>

namespace LogManager {
    std::vector<LogEntry> Logs;
    std::mutex LogMutex;
    bool AutoScroll = true;
    static char Filter[128] = "";

    void AddLog(int level, const char* tag, const char* fmt, ...) {
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, sizeof(buf), fmt, args);
        va_end(args);

        // Still send to Logcat
        __android_log_print(level, tag, "%s", buf);

        std::lock_guard<std::mutex> lock(LogMutex);
        Logs.push_back({level, tag, buf});

        // Cap logs to 500 entries to prevent memory leaks
        if (Logs.size() > 500) {
            Logs.erase(Logs.begin());
        }
    }

    void DrawLogTab() {
        ImGui::InputText("Filter", Filter, IM_ARRAYSIZE(Filter));
        ImGui::SameLine();
        if (ImGui::Button("Clear")) {
            std::lock_guard<std::mutex> lock(LogMutex);
            Logs.clear();
        }
        ImGui::Checkbox("Auto-scroll", &AutoScroll);

        ImGui::Separator();

        ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

        std::lock_guard<std::mutex> lock(LogMutex);

        std::string filterStr = Filter;
        std::transform(filterStr.begin(), filterStr.end(), filterStr.begin(), ::tolower);

        for (const auto& entry : Logs) {
            if (!filterStr.empty()) {
                std::string msgLower = entry.message;
                std::string tagLower = entry.tag;
                std::transform(msgLower.begin(), msgLower.end(), msgLower.begin(), ::tolower);
                std::transform(tagLower.begin(), tagLower.end(), tagLower.begin(), ::tolower);

                if (msgLower.find(filterStr) == std::string::npos &&
                    tagLower.find(filterStr) == std::string::npos) {
                    continue;
                }
            }

            ImVec4 color;
            bool hasColor = false;
            if (entry.level == 6) { color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); hasColor = true; } // Error
            else if (entry.level == 5) { color = ImVec4(1.0f, 0.8f, 0.4f, 1.0f); hasColor = true; } // Warn

            if (hasColor) ImGui::PushStyleColor(ImGuiCol_Text, color);
            ImGui::Text("[%s] %s", entry.tag.c_str(), entry.message.c_str());
            if (hasColor) ImGui::PopStyleColor();
        }

        if (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
            ImGui::SetScrollHereY(1.0f);

        ImGui::EndChild();
    }
}
