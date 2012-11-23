#ifndef GP_MOTIONEVENT_H_
#define GP_MOTIONEVENT_H_

#include "../Base/gp_types.h"

typedef struct gpMotionEvent {
	gpInt actionType;
	gpFloat* coordinates;
	gpWord size;
} gpMotionEvent;


#endif
