#ifndef GP_VELOCITYTRACKER_H_
#define GP_VELOCITYTRACKER_H_

#include "../MotionEvent/gp_MotionEvent.h"

typedef struct _gpVelocityNode {
	gpMotionEvent* event;
	struct _gpVelocityNode* next;
	struct _gpVelocityNode* previous;
} _gpVelocityNode;


typedef struct {
	_gpVelocityNode* head;
	_gpVelocityNode* end;
} gpVelocityTracker;


gpVoid gpVelocityTracker_addMovement(gpVelocityTracker*, gpMotionEvent*);
gpVelocityTracker* gpVelocityTracker_createInstance();
_gpVelocityNode* _gpVelocityTracker_gpVelocityNode_createInstance(gpMotionEvent*);

#endif