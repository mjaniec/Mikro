#include <gp_types.h>

const long GP_FLOAT_BASE=10000;
const gpBool true=1;
const gpBool false=0;
const gpVoid* null=((gpVoid*)0);

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