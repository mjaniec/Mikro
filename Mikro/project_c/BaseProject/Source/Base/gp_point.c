#ifndef GP_POINT_C
#define GP_POINT_C
#include "../../Include/Base/gp_point.h"

gpFloat gpPoint_distance(gpPoint*a,gpPoint*b){
	//TODO implement sqrt;
	return gpMkFloat("-1");
}

gpFloat gpPoint_distance2(gpPoint*a,gpPoint*b){
	gpFloat dx=gpSub(a->x,b->x);
	gpFloat dy=gpSub(a->y,b->y);
	return gpAdd(gpMul(dx,dx),gpMul(dy,dy));
}

#endif
