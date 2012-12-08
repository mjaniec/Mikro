
#ifndef GP_POINT_H_
#define GP_POINT_H_
#include "gp.h"
typedef struct{
	gpFloat x;
	gpFloat y;
}gpPoint;

gpFloat gpPoint_distance(gpPoint*a,gpPoint*b);
gpFloat gpPoint_distance2(gpPoint*a,gpPoint*b);

#endif /* GP_POINT_H_ */
