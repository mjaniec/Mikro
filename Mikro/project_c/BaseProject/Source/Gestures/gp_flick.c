#ifndef GP_FLICK_C
#define GP_FLICK_C

gpVoid gpTryFlick(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpPoint last;
	last.x=gpMotionEvent_getX(event,0)$r;
	last.y=gpMotionEvent_getY(event,0)$r;
	gpFloat dx=last.x-context->first->x;
	gpFloat dy=last.y-context->first->y;

	if(gpMath_Abs(dx)<GP_FLICK_MIN_LEN)return;
	if(gpMath_Abs(gpMul(gpMkFloat("4"),dy))>gpMath_Abs(dx))return;

	gpBool dir=dx>gpMkFloat(0);

	gpInt size=gpVector_getSize(context->gesture)$r;
	gpPoint*current;
	gpPoint*prevoius=context->first;
	for(gpInt i=1; i<size; ++i){
	   current=(gpPoint*)gpVector_at(context->gesture,i)$r;
	   dx=current->x-prevoius->x;
	   dy=current->y-prevoius->y;
	   if(gpMath_Abs(dx)<gpMath_Abs(dy))return;
	   if((dir&&dx<gpMkFloat(0)) || (!dir&&dx>gpMkFloat(0)))return;
	   prevoius=current;
	}

	//FLICK
	gp_isFlick=true;
	gp_FlickData.direction=dir;
	gp_FlickData.x=last.x;
	gp_FlickData.y=last.y;
}

#endif
