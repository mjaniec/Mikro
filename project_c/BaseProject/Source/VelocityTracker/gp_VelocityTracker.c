#ifndef GP_VELOCITYTRACKER_C_
#define GP_VELOCITYTRACKER_C_

#include "../../Include/VelocityTracker/gp_VelocityTracker.h"

gpVelocityTracker* gpVelocityTracker_createInstance()
{
	gpVelocityTracker* velocityTracker = gpAlloc_alloc(sizeof(gpVelocityTracker));
	velocityTracker->head = null;
	velocityTracker->end = null;
	return velocityTracker;
}

gpVoid gpVelocityTracker_addMovement(gpVelocityTracker* velocityTracker, gpMotionEvent* motionEvent)
{
	if(velocityTracker->head == null)
	{
		velocityTracker->head =_gpVelocityTracker_gpVelocityNode_createInstance(motionEvent);
		velocityTracker->end = velocityTracker->head;
	}
	else
	{
		_gpVelocityNode* previous_last_node = velocityTracker->end;
		_gpVelocityNode* new_node = _gpVelocityTracker_gpVelocityNode_createInstance(motionEvent);
		previous_last_node->next = new_node;
		new_node->previous = previous_last_node;
		velocityTracker->end = new_node;
	}
}

_gpVelocityNode* _gpVelocityTracker_gpVelocityNode_createInstance(gpMotionEvent* motionEvent) {
	_gpVelocityNode* node = gpAlloc_alloc(sizeof(_gpVelocityNode));
	node->event = motionEvent;
	node->next = null;
	node->previous = null;
	return node;
}

#endif