#ifndef GP_GESTURES_H_
#define GP_GESTURES_H_

#include "../Base/gp_types.h"

struct {
	gpFloat x;
	gpFloat y;
	gpBool direction;
} gpOutputGesture_two_finger_scroll ;

struct {
	gpBool direction;
	gpFloat magnification;
} gpOutputGesture_zoom;

struct {
	gpFloat x;
	gpFloat y;
	gpBool direction;
} gpOutputGesture_scroll;

struct {
	gpFloat x;
	gpFloat y;
	gpBool direction;
} gpOutputGesture_flick;

struct {
	gpBool direction;
	gpFloat angle;
} gpOutputGesture_rotation;

struct {
	gpFloat x;
	gpFloat y;
	gpByte direction;
} gpOutputGesture_move;

struct {
	gpFloat x;
	gpFloat y;
} gpOutputGesture_press;

struct {
	gpFloat x;
	gpFloat y;
} gpOutputGesture_tap;

#endif
