LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

TARGET_ARCH=arm
LOCAL_CFLAGS    := -std=c99 -Wno-main -Wall ${DEBUGINFO} ${MODE}
LOCAL_MODULE    := gpMain
LOCAL_SRC_FILES := gp_Main.c

include $(BUILD_SHARED_LIBRARY)
