LOCAL_PATH := $(call my-dir)
LOCAL_C_INCLUDES := $(call my-dir)/include


include $(CLEAR_VARS)

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog 
LOCAL_CFLAGS +=     -std=c99
LOCAL_MODULE := 	gp_Delegator
LOCAL_SRC_FILES := 	gp_Delegator.c


include $(BUILD_SHARED_LIBRARY)