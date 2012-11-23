#ifndef GP_MOTIONEVENT_H_
#define GP_MOTIONEVENT_H_

#include "../Base/gp_types.h"

typedef struct gpMotionEvent {
	gpInt actionType;
	gpFloat* coordinates;
	gpWord size;
	gpWord time;
} gpMotionEvent;

gpFloat gpMotionEvent_getX(gpMotionEvent*, gpInt index);
gpFloat gpMotionEvent_getY(gpMotionEvent*, gpInt index);

#endif