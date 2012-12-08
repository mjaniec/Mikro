/*
 * gp_printf.h
 *
 *  Created on: Dec 1, 2012
 *      Author: Janiec
 */

#ifndef GP_PRINTF_H_
#define GP_PRINTF_H_

#ifdef __ANDROID
gpInt __android_prinf(gpString fmt,...);
#define printf __android_prinf
#endif

#endif /* GP_PRINTF_H_ */
