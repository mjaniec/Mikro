#ifndef GP_POINT_C
#define GP_POINT_C
#include "../../Include/Base/gp.h"

gpFloat gpPoint_distance(gpPoint*a,gpPoint*b){
	return gpMath_Sqrt(gpPoint_distance2(a,b));
}

gpFloat gpPoint_distance2(gpPoint*a,gpPoint*b){
	gpFloat dx=gpSub(a->x,b->x);
	gpFloat dy=gpSub(a->y,b->y);
	return gpAdd(gpMul(dx,dx),gpMul(dy,dy));
}

gpPoint gpPoint_init(gpFloat x,gpFloat y){
	gpPoint r;
	r.x=x; r.y=y;
	return r;
}

#endif
