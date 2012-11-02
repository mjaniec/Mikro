#include "gp_types.h"
const gpBool gpTrue=1;
const gpBool gpFalse=0;

const long GP_FLOAT_BASE=10000;


inline gpFloat gpMul(gpFloat a, gpFloat b){
	long A=a, B=b;
	return A*B/GP_FLOAT_BASE;
}
inline gpFloat gpDiv(gpFloat a, gpFloat b){
	long A=a, B=b;
	return A/B*GP_FLOAT_BASE;
}

inline gpFloat gpSub(gpFloat a, gpFloat b){return a-b;}
inline gpFloat gpAdd(gpFloat a, gpFloat b){return a+b;}
inline gpFloat gpNeg(gpFloat a){return -a;}