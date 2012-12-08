#ifndef GP_FLICK_C
#define GP_FLICK_C

gpBool gpTryFlick(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;

	gpInt size=gpVector_getSize(context->finger1)$r0;
	gpInt bounds=2;
	if(size<2*bounds+2)return false;
	gpPoint last=*((gpPoint*)gpVector_at(context->finger1,size-1))$r0;
	gpPoint first=*((gpPoint*)gpVector_at(context->finger1,0))$r0;
	gpFloat dx=last.x-first.x;
	gpFloat dy=last.y-first.y;


	if(gpMath_Abs(dx)<GP_FLICK_MIN_LEN)return false;
	if(gpMath_Abs(gpMul(gpMkFloat("3"),dy))>gpMath_Abs(dx))return false;
	gpBool dir=dx>gpMath_0;

	size-=bounds;
	gpPoint*current;
	gpPoint*prevoius=gpVector_at(context->finger1,bounds-1);

	for(gpInt i=bounds; i<=size; ++i){
		if(i<size){ current=(gpPoint*)gpVector_at(context->finger1,i)$r0;}
		else current=&last;
	   dx=current->x-prevoius->x;
	   dy=current->y-prevoius->y;
	   if(gpMath_Abs(dy)>gpMath_Abs(dx))return false;
	   if((dir&&dx<gpMath_0) || (!dir&&dx>gpMath_0))return false;
	   prevoius=current;
	}
	//FLICK
	gp_isFlick=true;
	gp_FlickData.direction=dir;
	gp_FlickData.x=last.x;
	gp_FlickData.y=last.y;
	return true;
}

#endif
