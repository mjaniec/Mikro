#ifndef GP_ZOOM_C
#define GP_ZOOM_C


gpBool _gpCheckNonMonotonicity(gpPoint*first1,gpPoint*last1,gpPoint*first2,gpPoint*last2, gpBool dir_in){
	$fun;
	if(dir_in){
		if(gpPoint_distance(first1, last1) > GP_TAP_MAX_MOVE)
		{
			if(gpPoint_distance2(first1,first2)<gpPoint_distance2(last1,first2))return false;
		}
		if(gpPoint_distance(first2, last2) > GP_TAP_MAX_MOVE)
		{
			if(gpPoint_distance2(first2,first1)<gpPoint_distance2(last2,first1))return false;
		}
	}else{
		if(gpPoint_distance(first1, last1) > GP_TAP_MAX_MOVE)
		{
			if(gpPoint_distance2(first1,first2)>gpPoint_distance2(last1,first2))return false;
		}
		if(gpPoint_distance(first2, last2) > GP_TAP_MAX_MOVE)
		{
			if(gpPoint_distance2(first2,first1)>gpPoint_distance2(last2,first1))return false;
		}
	}
	return true;
}

gpBool _gpCheckFingerForZoom(gpVector*vec,gpPoint *target,gpPoint*azimut,gpBool dir_in,gpInt bounce){
	gpInt size=(gpVector_getSize(vec)-bounce)$r0;
	gpPoint*current;
	gpPoint*previous=gpVector_at(vec,bounce);
	gpFloat currentDist;
	gpFloat previousDist=gpPoint_distance2(previous,target);
	gpFloat angle, baseAngle;
	gpPoint _0;
	_0.x = gpMath_0;
	_0.y = gpMath_0;
	baseAngle=gpMath_AngleToAzimut(_0,*azimut);
	gpInt wrongPoints = 0;
	for(gpInt i=bounce+1; i<size; ++i){
		current=(gpPoint*)gpVector_at(vec,i)$r0;
		currentDist=gpPoint_distance2(current,target);
		if(dir_in)
		{
			angle=gpMath_AngleToAzimut(*previous, *current);
		}
		else
		{
			angle = gpMath_AngleToAzimut(*current, *previous);
		}

		gpFloat diff = gpSub(angle, baseAngle);
		if(diff > gpMath_PI)
		{
			diff = gpNeg(gpSub(gpMath_2PI, diff));
		}
		else if(diff < gpNeg(gpMath_PI))
		{
			diff = gpAdd(gpMath_2PI, diff);
		}

		if(gpMath_Abs(diff)>gpMath_PI4) wrongPoints++;
		if(dir_in && currentDist>previousDist)
			{
			wrongPoints++;
			}
		if(!dir_in&& currentDist<previousDist){
			wrongPoints++;
		}

	    previous=current;
	    previousDist=currentDist;
	}

	if(wrongPoints > size / 4)
	{
		return false;
	}

	return true;
}



gpBool gpTryZoom (gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpInt bounce=1;
	gpInt size1=gpVector_getSize(context->finger1)$r0;
	gpInt size2=gpVector_getSize(context->finger2)$r0;
	if(size1<2*bounce+2 || size2<2*bounce+2)return false;

	gpPoint last1 = (*(gpPoint*)gpVector_at(context->finger1,size1-1))$r0;
	gpPoint first1 = (*(gpPoint*)gpVector_at(context->finger1,0      ))$r0;
	gpPoint last2 = (*(gpPoint*)gpVector_at(context->finger2,size2-1))$r0;
	gpPoint first2 = (*(gpPoint*)gpVector_at(context->finger2,0      ))$r0;
	gpFloat dist1=gpPoint_distance(&first1, &first2)$r0;
	gpFloat dist2=gpPoint_distance(&last1, &last2)$r0;
	if(gpMath_Abs(dist1-dist2)<GP_ZOOM_MIN_CHANGE)return false;
	gpBool dir_in = dist1 > dist2;
	if(!_gpCheckNonMonotonicity(&first1, &last1, &first2, &last2, dir_in))return false;
	gpPoint direction = gpPoint_init(gpSub(first2.x,first1.x), gpSub(first2.y,first1.y));

	if(gpPoint_distance(&first1, &last1) > GP_TAP_MAX_MOVE)
	{
		if(!_gpCheckFingerForZoom(context->finger1,&first2,&direction,dir_in,bounce)) return false;
	}
	direction = gpPoint_init(gpSub(first1.x,first2.x), gpSub(first1.y,first2.y));

	if(gpPoint_distance(&first2, &last2) > GP_TAP_MAX_MOVE)
	{
		if(!_gpCheckFingerForZoom(context->finger2,&first1,&direction,dir_in,bounce)) return false;
	}
	gp_isZoom=true;
	gp_ZoomData.direction=dir_in;
	gp_ZoomData.magnification=(gpDiv(dist1,dist2));

	return true;
}

#endif//GP_ZOOM_C

