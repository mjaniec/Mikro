#ifndef GP_GESTUREDETECTOR_H_
#define GP_GESTUREDETECTOR_H_

#include "../GestureHandler/gp_GestureHandler.h"

typedef struct {
	gpGestureHandler* mhandler;
	gpInt gpListener; // byl jako parametr konstruktora, nie wspieramy tego
	gpInt mTouchSlopSquare;
	gpInt mMinimumFlingVelocity;
    gpInt mMaximumFlingVelocity;
} gpGestureDetector;


#define gpGestureDetector_MINIMUM_FLING_VELOCITY 50
#define gpGestureDetector_MAXIMUM_FLING_VELOCITY 8000
#define gpGestureDetector_TOUCH_SLOP 			 8

gpGestureDetector* gpGestureDetector_createInstance();
#endif
