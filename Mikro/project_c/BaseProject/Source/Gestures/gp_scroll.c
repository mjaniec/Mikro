#ifndef GP_SCROLL_C
#define GP_SCROLL_C


gpOutputGesture_scroll* _gpCheckForScrollInVector(gpVector*vec){
	$fun;
	gpInt size=gpVector_getSize(vec)$r0;
	gpInt bounds=2;
	if(size<2*bounds+2)return false;
	gpPoint last=*((gpPoint*)gpVector_at(vec,size-1))$r0;
	gpPoint first=*((gpPoint*)gpVector_at(vec,0))$r0;
	gpFloat dx=last.x-first.x;
	gpFloat dy=last.y-first.y;


	if(gpMath_Abs(dy)<GP_SCROLL_MIN_LEN)return false;
	if(gpMath_Abs(gpMul(gpMkFloat("3"),dx))>gpMath_Abs(dy))return false;
	gpBool dir=dy>gpMath_0;

	size-=bounds;
	gpPoint*current;
	gpPoint*prevoius=gpVector_at(vec,bounds-1);

	for(gpInt i=bounds; i<=size; ++i){
		if(i<size){ current=(gpPoint*)gpVector_at(vec,i)$r0;}
		else current=&last;
	   dx=current->x-prevoius->x;
	   dy=current->y-prevoius->y;
	   if(gpMath_Abs(dx)>gpMath_Abs(dy))return false;
	   if((dir&&dy<gpMath_0) || (!dir&&dy>gpMath_0))return false;
	   prevoius=current;
	}
	static gpOutputGesture_scroll out;
    out.direction=dir;
    out.x=last.x;
    out.y=last.y;

	return &out;
}

gpBool gpTryScroll(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpOutputGesture_scroll* x=_gpCheckForScrollInVector(context->finger1)$r0;
	if(x){
	    gp_isScroll=true;
	    gp_ScrollData=*x;
	    return true;
	}
    return false;
}


gpBool gpTryTwoFingerScroll	(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpOutputGesture_scroll* firstFinger=_gpCheckForScrollInVector(context->finger1)$r0;
	gpOutputGesture_scroll* secondFinger=_gpCheckForScrollInVector(context->finger2)$r0;

	if(firstFinger && secondFinger && firstFinger->direction==secondFinger->direction){
		gp_isTwoFingerScroll=true;
		gp_TwoFingerScrollData.direction=firstFinger->direction;
		gp_TwoFingerScrollData.x=gpDiv(gpAdd(firstFinger->x,secondFinger->x),gpMkFloat("2"));
		gp_TwoFingerScrollData.y=gpDiv(gpAdd(firstFinger->y,secondFinger->y),gpMkFloat("2"));
		return true;
	}
	return false;
}
#endif
