#include <gp_Math.h>

gpInt gpMinInt(gpInt a, gpInt b)
{
	return a > b ? b : a;
}

gpInt* gpMinIntP(gpInt* a, gpInt* b)
{
	return a > b ? b : a;
}