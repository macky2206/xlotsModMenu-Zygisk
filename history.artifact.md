# Project Modification History

This document tracks all significant changes made to the Zygisk ImGui Mod Menu project, organized by date.

---

## 2026-09-02
### Features (Days Bygone)
- **Stats Hack Fix:** Corrected `STAT` enum IDs for the latest game version.
    - **Attack (Damage)** is now correctly identified as **ID 0**.
    - **Health** is now correctly identified as **ID 6** (previously misidentified as ID 1, which was Agility/FireRate).
- **Discovery Logic:** Improved `StatsHack` to log any unknown Stat IDs encountered during the discovery phase to assist with further research.
- **UI Consistency:** Standardized the `Stats` tab to use `ImGui::DragInt` (matching the Multipliers tab) for easier handling of large values.
- **Cleanup:** Completely removed unstable `SkillsHack` and `FreeShop` initialization paths to ensure maximum game stability.
- **In-Game Log Viewer:** Added a dedicated **"Logs"** tab to the ImGui menu.
    - Captures all `LOGI`, `LOGW`, and `LOGE` calls from the module.
    - Features a real-time text filter (case-insensitive) for searching specific tags or messages.
    - Includes an "Auto-scroll" toggle and a "Clear" button.
    - Capped at 500 entries to maintain performance.

### Core & Infrastructure
- **BNM Loading Fix:** Switched to `BNM::Loading::AllowLateInitHook()` to handle cases where Unity initializes before the Zygisk module. This fixed frequent startup crashes.
- **Configuration System:** Implemented a robust dual-config system:
    - `imgui_hooks.txt`: Managed by KernelSU WebUI for startup/core settings.
    - `features_config.txt`: Managed in-game for volatile cheat toggles.
- **WebUI Robustness:** Fixed the KernelSU WebUI to correctly parse config files with Windows line endings and improved the shell execution logic for saving.
- **Soft Keyboard Support:** Integrated Unity's `UnityEngine.TouchScreenKeyboard` to allow text input (typing numbers) in ImGui when double-tapping `DragInt` widgets.

### UI & UX
- **Auto-Scaling:** Implemented a resolution-aware scaling system that baseline-adjusts for 720p/1080p displays.
- **Menu Constraints:** Added window constraints to prevent the menu from becoming unusable on extreme screen aspect ratios.

---

## 2026-09-01
### Environment Setup
- **Build System:** Upgraded to AGP **7.2.2** and Gradle **7.3.3**.
- **Compiler:** Migrated to **C++20** standard.
- **Integration:** Initial integration of **BNM-Android** and **xDL** for symbol resolution.

### Initial Features
- **Legacy Features:** Ported initial hacks for Lowest Wave, Expedition, and Equipment skins.
- **Rendering:** Implemented stable ImGui loop with full OpenGL state protection.
