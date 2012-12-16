#ifndef GP_TAP_C
#define GP_TAP_C

gpOutputGesture_tap*_gpCheckForTapInVector(gpVector* vec){
	$fun;

	gpInt size=gpVector_getSize(vec)$r0;
	if(!size)return null;
	gpPoint*first=((gpPoint*)gpVector_at(vec,0))$r0;

	gpPoint*current;
	gpFloat maxDistSquare=gpMath_Square(GP_TAP_MAX_MOVE)$r0;
	for(gpInt i=0; i<size; ++i){
		current=(gpPoint*)gpVector_at(vec,i)$r0;
		if(gpPoint_distance2(first,current)>maxDistSquare)return null;
	}

	gpOutputGesture_tap* res=gpAlloc_alloc(sizeof(gpOutputGesture_tap))$r0;
	res->x=first->x;
	res->y=first->y;
	return res;
}

gpBool gpTryTap(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;

	if(event->time-context->firstTime>GP_TAP_MAX_TIME)return false;
	gpOutputGesture_tap*tap=_gpCheckForTapInVector(context->finger1)$r0;
	if(tap){
	  gp_TapData=*tap;
	  gp_isTap=true;
	  gpAlloc_free(tap);
	  return true;
	}

	return false;
}

gpBool gpTryTwoFingerTap(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpBool res=false;
	if(event->time-context->firstTime>GP_TAP_MAX_TIME)return false;
	gpOutputGesture_tap*one=_gpCheckForTapInVector(context->finger1);
	gpOutputGesture_tap*two=_gpCheckForTapInVector(context->finger2);
	if(one && two ){
		gp_isTwoFingerTap=true;
		gp_TwoFingerTapData.x=gpDiv(gpAdd(one->x,two->x),gpMkFloat("2"));
		gp_TwoFingerTapData.y=gpDiv(gpAdd(one->y,two->y),gpMkFloat("2"));
		res=true;
	}
	gpAlloc_free(one)$r0;
	gpAlloc_free(two)$r0;
	return res;
}

#endif
