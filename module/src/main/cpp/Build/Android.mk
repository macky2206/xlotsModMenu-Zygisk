LOCAL_PATH := $(call my-dir)

# --- BNM Module ---
MY_SAVED_LOCAL_PATH := $(LOCAL_PATH)
include $(LOCAL_PATH)/../BNM-Android/Android.mk
LOCAL_PATH := $(MY_SAVED_LOCAL_PATH)

# --- External Libraries ---
include $(LOCAL_PATH)/../External/Android.mk

# --- Main modmenu Module ---
include $(CLEAR_VARS)

LOCAL_MODULE := xLots

# Include directories
LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
                    $(LOCAL_PATH)/../Headers \
                    $(LOCAL_PATH)/../Include \
                    $(LOCAL_PATH)/../External/ImGui \
                    $(LOCAL_PATH)/../External/KittyMemory \
                    $(LOCAL_PATH)/../External/Dobby \
                    $(LOCAL_PATH)/../xdl/include \
                    $(LOCAL_PATH)/../BNM-Android/include \
                    $(LOCAL_PATH)/../BNM-Android/external/include \
                    $(LOCAL_PATH)/../BNM-Android/src/private

# Source files
LOCAL_SRC_FILES := ../Main.cpp \
                   ../ModMenu.cpp \
                   ../Drawing.cpp \
                   ../Utility.cpp \
                   ../LogManager.cpp \
                   ../xdl/xdl.c \
                   ../xdl/xdl_iterate.c \
                   ../xdl/xdl_linker.c \
                   ../xdl/xdl_lzma.c \
                   ../xdl/xdl_util.c

LOCAL_STATIC_LIBRARIES := libimgui libkitty libdobby BNM
LOCAL_LDLIBS := -llog -lGLESv3 -lEGL -landroid -lz

LOCAL_CPPFLAGS := -std=c++20

include $(BUILD_SHARED_LIBRARY)
