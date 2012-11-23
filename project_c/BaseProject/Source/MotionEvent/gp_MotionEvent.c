#include "../../Include/MotionEvent/gp_MotionEvent.h"
#include "../../Include/Base/gp.h"

gpFloat gpMotionEvent_getX(gpMotionEvent* event, gpInt index)
{
	if(index >= event->size)
	{

	#ifdef DEBUG
		gp_errno = GP_EINDEX;
	#endif

		return 0;
	}
	return event->coordinates[index * 2];
}

gpFloat gpMotionEvent_getY(gpMotionEvent* event, gpInt index)
{
	if(index >= event->size)
	{

	#ifdef DEBUG
		gp_errno = GP_EINDEX;
	#endif

		return 0;
	}
	return event->coordinates[index * 2 + 1];
}
