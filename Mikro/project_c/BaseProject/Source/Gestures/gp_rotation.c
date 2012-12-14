#ifndef GP_ROTATION_C
#define GP_ROTATION_C

gpBool _gp_rotation_checkDistance(gpPoint point, gpVector* points)
{
	gpInt size = points->size;
	gpFloat baseDistance = gpPoint_distance(&point, gpVector_at(points, 0));
	for(gpInt i = 1; i < size; i++)
	{
		if(gpMath_Abs(gpSub(gpPoint_distance(&point, gpVector_at(points, i)), baseDistance)) > gpMul(GP_ROTATION_MAX_MOVE, gpMath_2))
		{
			return false;
		}
	}

	return true;
}

gpFloat _gp_rotation_calculateAngle(gpVector* points, gpPoint base)
{
	gpFloat angle = gpMath_0;
	gpInt size = points->size;

	for(gpInt i = 0; i < size - 1; i++)
	{
		gpPoint* previous = gpVector_at(points, i);
		gpPoint* next = gpVector_at(points, i + 1);

		gpFloat anglePrevious = gpMath_AngleToAzimut_ByRotationGuy(*previous, base);
		gpFloat angleNext = gpMath_AngleToAzimut_ByRotationGuy(*next, base);

		gpFloat diff = gpSub(angleNext, anglePrevious);

		if(diff > gpMath_PI)
		{
			diff = gpNeg(gpSub(gpMath_2PI, diff));
		}
		else if(diff < gpNeg(gpMath_PI))
		{
			diff = gpAdd(gpMath_2PI, diff);
		}

		angle = gpAdd(angle, diff);
	}

	while(angle > gpMath_2PI)
	{
		angle = gpSub(angle, gpMath_2PI);
	}

	while(angle < gpNeg(gpMath_2PI))
	{
		angle = gpAdd(angle, gpMath_2PI);
	}

	return gpDiv(gpMul(angle, gpMkFloat("180")), gpMath_PI);
}


gpBool gpTryRotation(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	if(context->finger1->size <= 0 || context->finger2->size <= 0)
	{
		return false;
	}
	gpInt size1=gpVector_getSize(context->finger1)$r0;
	gpInt size2=gpVector_getSize(context->finger2)$r0;

	gpPoint last1 = (*(gpPoint*)gpVector_at(context->finger1, size1-1))$r0;
	gpPoint first1 = (*(gpPoint*)gpVector_at(context->finger1, 0))$r0;
	gpPoint last2 = (*(gpPoint*)gpVector_at(context->finger2, size2-1))$r0;
	gpPoint first2 = (*(gpPoint*)gpVector_at(context->finger2, 0))$r0;
	gpFloat dist1 = gpPoint_distance(&first1, &last1)$r0;
	gpFloat dist2 = gpPoint_distance(&first2, &last2)$r0;
	gpFloat angle;
	if(dist1 > GP_ROTATION_MAX_MOVE && dist2 > GP_ROTATION_MAX_MOVE)
	{
		return false;
	}
	else if(dist1 < GP_ROTATION_MAX_MOVE)
	{
		if(!_gp_rotation_checkDistance(first1, context->finger2))
		{
			return false;
		}

		angle = _gp_rotation_calculateAngle(context->finger2, first1);
	}
	else
	{
		if(!_gp_rotation_checkDistance(first2, context->finger1))
		{
			return false;
		}

		angle = _gp_rotation_calculateAngle(context->finger1, first2);
	}

	gp_isRotation = true;
	gp_RotationData.angle = angle;
	gp_RotationData.direction = angle > 0;

	return true;
}

#endif//GP_ROTATION_C
