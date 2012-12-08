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
	static gpVector __v;
	static gpPoint  __p;
	if(init){
		init=false;
		context.first=&__p;
		context.gesture=&__v;
		gpVector_init(context.gesture)$r;
	}
	switch(event->actionType){
		case GP_ME_ACTION_DOWN: _gpHandleDown(event,&context)$r; break;
		case GP_ME_ACTION_MOVE: _gpHandleMove(event,&context)$r; break;
		case GP_ME_ACTION_UP:   _gpHandleUp  (event,&context)$r; break;
	}
}

gpVoid _gpHandleDown(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpVector_clean(context->gesture)$r;
	context->firstTime=event->time;
	gp_MoveData.begx=context->first->x=gpMotionEvent_getX(event,0)$r;
	gp_MoveData.begy=context->first->y=gpMotionEvent_getY(event,0)$r;
	gpVector_pushBack(context->gesture,context->first,sizeof(gpPoint))$r;
}
gpVoid _gpHandleMove(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gp_isMove=true;
	gp_MoveData.x=gpMotionEvent_getX(event,0)$r;
	gp_MoveData.y=gpMotionEvent_getY(event,0)$r;

	gpPoint current;
	current.x=gpMotionEvent_getX(event,0)$r;
	current.y=gpMotionEvent_getY(event,0)$r;

	gpVector_pushBack(context->gesture,&current,sizeof(gpPoint))$r;
}
gpVoid _gpHandleUp  (gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	/*gpTryTap(event,context)$r;
	gpTryPress(event,context)$r;
	gpTryScroll(event,context)$r;
	gpTryFlick(event,context)$r;*/
	gpVector_clean(context->gesture);
}


#endif
