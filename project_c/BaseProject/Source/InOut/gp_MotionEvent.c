#ifndef __gp_MotionEvent_c
#define __gp_MotionEvent_c

#include "../../Include/InOut/gp_MotionEvent.h"
#include "../../Include/Base/gp.h"



gpFloat gpMotionEvent_getX(gpMotionEvent* event, gpInt index)
{
	$fun;
	$assert0(index<event->size,GP_EINDEX);
	return event->coordinates[index * 2];
}

gpFloat gpMotionEvent_getY(gpMotionEvent* event, gpInt index)
{
	$fun;
	$assert0(index<event->size,GP_EINDEX);
	return event->coordinates[index * 2 + 1];
}

#endif
