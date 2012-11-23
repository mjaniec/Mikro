LOCAL_PATH := $(call my-dir)
LOCAL_C_INCLUDES := $(call my-dir)/include
LOCAL_LDLIBS := -L.

include $(CLEAR_VARS)


LOCAL_MODULE := 	com_example_mikro_MainActivity
LOCAL_SRC_FILES := 	com_example_mikro_MainActivity.c


include $(BUILD_SHARED_LIBRARY)