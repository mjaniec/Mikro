#ifndef GP_POINT_C
#define GP_POINT_C
#include "../../Include/Base/gp.h"

gpFloat gpPoint_distance(gpPoint*a,gpPoint*b){
	return gpMath_Sqrt(gpPoint_distance2(a,b));
}

gpFloat gpPoint_distance2(gpPoint*a,gpPoint*b){
	gpFloat dx=gpSub(a->x,b->x);
	gpFloat dy=gpSub(a->y,b->y);
	gpFloat res=gpAdd(gpMul(dx,dx),gpMul(dy,dy));
	if(res<gpMath_0){
		res=gpMath_FLOAT_MAX;
	}
	return res;
}

gpPoint gpPoint_init(gpFloat x,gpFloat y){
	gpPoint r;
	r.x=x; r.y=y;
	return r;
}

#endif
