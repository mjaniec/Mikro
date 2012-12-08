#ifndef GP_TAP_C
#define GP_TAP_C

gpOutputGesture_tap*_gpCheckForTapInVector(gpVector* vec){
	$fun;
	static gpOutputGesture_tap res;

	gpInt size=gpVector_getSize(vec)$r0;
	gpPoint first=*((gpPoint*)gpVector_at(vec,0))$r0;

	gpPoint*current;
	gpFloat maxDistSquare=gpMath_Square(GP_TAP_MAX_MOVE)$r0;
	for(gpInt i=0; i<size; ++i){
		current=(gpPoint*)gpVector_at(vec,i)$r0;
		if(gpPoint_distance2(&first,current)>maxDistSquare)return null;
	}

	res.x=first.x;
	res.y=first.y;
	return &res;
}

gpBool gpTryTap(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;

	if(event->time-context->firstTime>GP_TAP_MAX_TIME)return false;
	gpOutputGesture_tap*tap=_gpCheckForTapInVector(context->finger1);
	if(tap){
	  gp_TapData=*tap;
	  gp_isTap=true;
	  return true;
	}

	return false;
}

gpBool gpTryTwoFingerTap(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;

	if(event->time-context->firstTime>GP_TAP_MAX_TIME)return false;
	gpOutputGesture_tap*one=_gpCheckForTapInVector(context->finger1);
	gpOutputGesture_tap*two=_gpCheckForTapInVector(context->finger1);
	gpFloat max_dist=gpMath_Square(GP_TWO_FINGER_TAP_MAX_DIST);
	if(one && two ){
		if(gpAdd(gpMath_Square(one->x-two->x),gpMath_Square(one->y-two->y))<max_dist)
		gp_isTwoFingerTap=true;
		gp_TwoFingerTapData.x=gpDiv(gpAdd(one->x,two->x),gpMkFloat("2"));
		gp_TwoFingerTapData.y=gpDiv(gpAdd(one->y,two->y),gpMkFloat("2"));
		return true;
	}
	return false;
}

#endif
