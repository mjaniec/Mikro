#ifndef gp_Math_c
#define gp_Math_c

#include "..\..\Include\Math\gp_Math.h"

gpInt gpMath_MinInt(gpInt a, gpInt b)
{
	return a > b ? b : a;
}

gpInt* gpMath_MinIntP(gpInt* a, gpInt* b)
{
	return a > b ? b : a;
}

#endif
