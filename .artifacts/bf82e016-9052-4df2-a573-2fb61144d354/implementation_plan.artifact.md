# Update Android Gradle Plugin and Gradle Versions

The project is currently using an incompatible version of the Android Gradle Plugin (AGP 4.2.2) and Gradle (7.2). This plan outlines the steps to upgrade to the minimum supported versions (AGP 7.2.2 and Gradle 7.3.3) to ensure compatibility with modern Android Studio versions.

## User Review Required

> [!IMPORTANT]
> This upgrade requires JDK 11 or higher. Please ensure your IDE is configured to use JDK 11+ for Gradle builds.
> The paths to some build intermediates (like native libraries) might have changed between AGP 4.2 and 7.2. I will verify these after the initial update.

## Proposed Changes

### Build Configuration

#### [MODIFY] [gradle-wrapper.properties](file:///D:/Android/StudioProjects/Zygisk-ImGui-Mod-Menu/gradle/wrapper/gradle-wrapper.properties)
- Update `distributionUrl` to use Gradle 7.3.3.

#### [MODIFY] [build.gradle](file:///D:/Android/StudioProjects/Zygisk-ImGui-Mod-Menu/build.gradle)
- Update the `com.android.tools.build:gradle` dependency to `7.2.2`.

#### [MODIFY] [module/build.gradle](file:///D:/Android/StudioProjects/Zygisk-ImGui-Mod-Menu/module/build.gradle)
- Minor adjustments if necessary to handle changes in AGP behavior, specifically related to native library intermediate paths.

## Verification Plan

### Automated Tests
- Run `./gradlew clean assembleDebug` to verify the build process.
- Run `gradle_sync` to ensure Android Studio recognizes the new configuration.

### Manual Verification
- Verify that the Magisk module zip is correctly generated in the `out/` directory.
- Check that native libraries are correctly placed in the `zygisk/` folder within the zip.
