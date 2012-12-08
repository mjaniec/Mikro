#ifndef GP_MOTIONEVENT_H_
#define GP_MOTIONEVENT_H_

#include "../Base/gp_types.h"

#define gpMotionEvent_ACTION_MASK  				0xff
#define gpMotionEvent_ACTION_POINTER_DOWN		   5
#define gpMotionEvent_ACTION_POINTER_UP            6

typedef struct gpMotionEvent {
	gpInt actionType;
	gpFloat* coordinates;
	gpWord size;
	gpWord time;
} gpMotionEvent;

gpFloat gpMotionEvent_getX(gpMotionEvent*, gpInt index);
gpFloat gpMotionEvent_getY(gpMotionEvent*, gpInt index);

#endif
