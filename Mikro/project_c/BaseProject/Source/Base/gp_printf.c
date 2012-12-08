#ifndef GP_PRINTF_C
#define GP_PRINTF_C

#ifdef __ANDROID

#include <stdio.h>
#include <stdarg.h>
#include "../../Include/Base/gp.h"

gpInt __android_prinf(gpString fmt,...){
	gpChar buffer[4096];
	gpInt ret;
	va_list args;
	va_start (args, fmt);
	ret=vsprintf (buffer,fmt, args);
	__android_log_write(ANDROID_LOG_INFO, "Native", buffer);
	va_end (args);
	return ret;
}

#endif

#endif
