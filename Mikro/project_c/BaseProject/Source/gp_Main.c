#ifndef gp_Main_c
#define gp_Main_c

#include "../Include/gp_Main.h"
#include "Base\gp.c"
#include "Alloc\gp_Alloc.c"
#include "Math\gp_Math.c"
#include "Gestures\gp_gestures.c"
#include "InOut\gp_MotionEvent.c"

gpVoid _gpHandleDown(gpMotionEvent*event,gpRecognizeContext*contex);
gpVoid _gpHandleMove(gpMotionEvent*event,gpRecognizeContext*contex);
gpVoid _gpHandleUp  (gpMotionEvent*event,gpRecognizeContext*contex);


gpVoid gpRecognize(gpMotionEvent*event){
	$fun;

	static gpBool init=true;
	static gpRecognizeContext context;
	static gpVector __v1, __v2;

	if(init){
		init=false;
		context.fingers=0;
		context.finger1=&__v1;
		context.finger2=&__v2;
		gpVector_init(context.finger1)$r;
		gpVector_init(context.finger2)$r;
	}
	switch(event->actionType){
		case GP_ME_ACTION_DOWN: _gpHandleDown(event,&context)$r; context.fingers = 1; break;
		case GP_ME_ACTION_MOVE: _gpHandleMove(event,&context)$r; break;
		case GP_ME_ACTION_POINTER_1_DOWN: break;
		case GP_ME_ACTION_POINTER_1_UP: break;
		case GP_ME_ACTION_POINTER_2_DOWN: context.fingers = 2; break;
		case GP_ME_ACTION_POINTER_2_UP: break;
		case GP_ME_ACTION_UP:   _gpHandleUp  (event,&context)$r; context.fingers = 0; break;
	}
}

gpVoid _gpHandleDown(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	context->firstTime=event->time;
}
gpVoid _gpHandleMove(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	if(event->size == 1 && context->fingers == 1 &&  gpVector_getSize(context->finger1) > 0)
	{
		gp_isMove=true;
		gp_MoveData.x = gpMotionEvent_getX(event,0)$r;
		gp_MoveData.y = gpMotionEvent_getY(event,0)$r;
		gpPoint* previousPoint = gpVector_at(context->finger1, gpVector_getSize(context->finger1) - 1)$r;
		gp_MoveData.begx = previousPoint->x;
		gp_MoveData.begy = previousPoint->y;
	}

	gpPoint current1;
	gpPoint current2;

	current1.x=gpMotionEvent_getX(event,0)$r;
	current1.y=gpMotionEvent_getY(event,0)$r;

	gpVector_pushBack(context->finger1,&current1,sizeof(gpPoint))$r;

	if(event->size==2){
		current2.x=gpMotionEvent_getX(event,1)$r;
		current2.y=gpMotionEvent_getY(event,1)$r;
		gpVector_pushBack(context->finger2,&current2,sizeof(gpPoint))$r;
	}
}
gpVoid _gpHandleUp  (gpMotionEvent*event,gpRecognizeContext*context){
	$fun;

	gpTryScroll(event,context)$r;
	gpTryTwoFingerScroll(event,context)$r;
	gpTryTap(event,context)$r;
	gpTryPress(event,context)$r;
	gpTryFlick(event,context)$r;
	gpTryRotation(event,context)$r;
	gpTryTwoFingerTap(event,context)$r;
	gpTryZoom(event,context)$r;
	gpVector_clean(context->finger1)$r;
	gpVector_clean(context->finger2)$r;
}


#endif
