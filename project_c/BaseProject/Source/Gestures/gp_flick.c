#ifndef GP_FLICK_C
#define GP_FLICK_C

gpVoid gpTryFlick(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpPoint last;
	last.x=gpMotionEvent_getX(event,0)$r;
	last.y=gpMotionEvent_getY(event,0)$r;
	gpFloat dx=last.x-context->first1->x;
	gpFloat dy=last.y-context->first1->y;

	if(gpMath_Abs(dx)<GP_FLICK_MIN_LEN)return;
	if(gpMath_Abs(gpMul(gpMkFloat("3"),dy))>gpMath_Abs(dx))return;


	gpBool dir=dx>gpMath_0;
	gpInt size=gpVector_getSize(context->finger1)$r;
	gpInt bounds=2;
	if(size<2*bounds+2)return;
	size-=bounds;
    gpPoint*current;
    gpPoint*prevoius=gpVector_at(context->finger1,bounds-1);

    for(gpInt i=bounds; i<=size; ++i){
	   current=(gpPoint*)gpVector_at(context->finger1,i)$r;
	   dx=current->x-prevoius->x;
	   dy=current->y-prevoius->y;
	   if(gpMath_Abs(dx)<gpMath_Abs(dy))return;
	   if((dir&&dx<gpMath_0) || (!dir&&dx>gpMath_0))return;
	   prevoius=current;
	}


	//FLICK
	gp_isFlick=true;
	gp_FlickData.direction=dir;
	gp_FlickData.x=last.x;
	gp_FlickData.y=last.y;
}

#endif
