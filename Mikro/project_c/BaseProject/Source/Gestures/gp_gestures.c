#ifndef GP_GESTURES_C
#define GP_GESTURES_C

gpVoid printVector(gpVector*vector,gpString name){
	$fun;
	gpInt size=gpVector_getSize(vector)$r;
	printf("%s: size: %d\n",name,size);
	gpPoint*p;
	for(gpInt i=0; i<size; ++i){
		p=gpVector_at(vector,i)$r;
		printf("   %d,%d",gpMath_Int(p->x),gpMath_Int(p->y) );
	}
}


#include "gp_flick.c"
#include "gp_press.c"
#include "gp_rotation.c"
#include "gp_scroll.c"
#include "gp_tap.c"
#include "gp_zoom.c"

#endif//GP_GESTURES_C
