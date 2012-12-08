#ifndef GP_MOTIONEVENT_H_
#define GP_MOTIONEVENT_H_

#include "../Base/gp_types.h"

#define GP_ME_ACTION_CANCEL 3
#define GP_ME_ACTION_DOWN 0
#define GP_ME_ACTION_HOVER_ENTER 9
#define GP_ME_ACTION_HOVER_EXIT 10
#define GP_ME_ACTION_HOVER_MOVE 7
#define GP_ME_ACTION_MOVE 2
#define GP_ME_ACTION_POINTER_1_DOWN 5
#define GP_ME_ACTION_POINTER_1_UP 6
#define GP_ME_ACTION_POINTER_2_DOWN 261
#define GP_ME_ACTION_POINTER_2_UP 262
#define GP_ME_ACTION_POINTER_DOWN 5
#define GP_ME_ACTION_POINTER_UP 6
#define GP_ME_ACTION_SCROLL 8
#define GP_ME_ACTION_UP 1

typedef struct gpMotionEvent {
	gpInt actionType;
	gpFloat* coordinates;
	gpWord size;
	gpWord time;
} gpMotionEvent;


gpFloat gpMotionEvent_getX(gpMotionEvent*, gpInt index);
gpFloat gpMotionEvent_getY(gpMotionEvent*, gpInt index);

#endif
