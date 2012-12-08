#ifndef __GP_VECTOR
#define __GP_VECOTR

#include "gp.h"

typedef struct{
	gpVoid**data;
	gpInt capacity;
	gpInt size;
}gpVector;

gpVoid gpVector_init(gpVector*self);
gpVoid gpVector_destroy(gpVector*self);
gpInt  gpVector_getSize(gpVector*self);
gpVoid*gpVector_at(gpVector*self,gpInt index);
gpVoid gpVector_clean(gpVector *sefl);
gpVoid gpVector_pushBack(gpVector *self, gpVoid*what, gpInt size);
gpVoid gpVector_popBack(gpVector *self, gpVoid*where, gpInt size);
#endif
