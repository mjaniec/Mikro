#ifndef GP_GESTURES_H_
#define GP_GESTURES_H_

#include "../Base/gp_types.h"

typedef struct {
	gpFloat x;
	gpFloat y;
	gpBool direction;
} gpOutputGesture_two_finger_scroll ;

typedef struct {
	gpBool direction;
	gpFloat magnification;
} gpOutputGesture_zoom;

typedef struct {
	gpFloat x;
	gpFloat y;
	gpBool direction;
} gpOutputGesture_scroll;

typedef struct {
	gpFloat x;
	gpFloat y;
	gpBool direction;
} gpOutputGesture_flick;

typedef struct {
	gpBool direction;
	gpFloat angle;
} gpOutputGesture_rotation;

typedef struct {
	gpFloat x;
	gpFloat y;
	gpByte direction;
} gpOutputGesture_move;

typedef struct {
	gpFloat x;
	gpFloat y;
} gpOutputGesture_press;

typedef struct {
	gpFloat x;
	gpFloat y;
} gpOutputGesture_tap;


#endif
