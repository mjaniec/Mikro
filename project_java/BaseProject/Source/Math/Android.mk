LOCAL_PATH := $(call my-dir)
LOCAL_C_INCLUDES := $(call my-dir)/include

include $(CLEAR_VARS)

LOCAL_MODULE := 	gp_Math
LOCAL_SRC_FILES := 	gp_Math.c

include $(BUILD_SHARED_LIBRARY)