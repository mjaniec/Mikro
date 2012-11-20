#ifndef GP_GESTURES_H_
#define GP_GESTURES_H_

#include "../Base/gp_types.h"

struct gpOutputGesture {
	gpInt code;

	union {
		struct {
			gpFloat x;
			gpFloat y;
			gpBool direction;
		} two_finger_scroll ;
		struct {
			gpBool direction;
			gpFloat magnification;
		} zoom;
		struct {
			gpFloat x;
			gpFloat y;
			gpBool direction;
		} scroll;
		struct {
			gpFloat x;
			gpFloat y;
			gpBool direction;
		} flick;
		struct {
			gpBool direction;
			gpFloat angle;
		} rotation;
		struct {
			gpFloat x;
			gpFloat y;
			gpByte direction;
		} move;
		struct {
			gpFloat x;
			gpFloat y;
		} press;
		struct {
			gpFloat x;
			gpFloat y;
		} tap;
	} info;
};

#endif
