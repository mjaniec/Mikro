#ifndef GP_GESTUREHANDLER_C_
#define GP_GESTUREHANDLER_C_

#include "../../Include/GestureHandler/gp_GestureHandler.h"

gpGestureHandler* gpGestureHandler_createInstance()
{
	return gpAlloc_alloc(sizeof(gpGestureHandler));
}


#endif