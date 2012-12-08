#ifndef GP_MATH_H
#define GP_MATH_H
#include "../Base/gp.h"


gpInt gpMath_MinInt(gpInt, gpInt);
gpInt* gpMath_MinIntP(gpInt*, gpInt*);


gpFloat gpMath_Abs(gpFloat a);
gpFloat gpMath_Square(gpFloat a);
gpFloat gpMath_Sqrt(gpFloat a);
gpFloat gpMath_Exp(gpFloat a);
gpFloat gpMath_PowI(gpFloat base, gpInt exp);
gpFloat gpMath_Sin(gpFloat x);
gpFloat gpMath_Cos(gpFloat x);
gpFloat gpMath_Tan(gpFloat x);
gpFloat gpMath_ASin(gpFloat x);
gpFloat gpMath_ACos(gpFloat x);
gpFloat gpMath_ATan(gpFloat x);
gpBool  gpMath_Equals(gpFloat a, gpFloat b);
gpInt   gpMath_Int(gpFloat a);
gpFloat gpMath_FloatI(gpInt a);

gpFloat gpMul(gpFloat a, gpFloat b);
gpFloat gpDiv(gpFloat a, gpFloat b);
gpFloat gpSub(gpFloat a, gpFloat b);
gpFloat gpAdd(gpFloat a, gpFloat b);
gpFloat gpNeg(gpFloat a);


gpFloat gpMkFloat(gpString x);

//it should be constants, but C does not has good constants.
#define GP_FLOAT_BASE 10000
#define GP_FLOAT_HALF 100
#define gpMath_EPSILION 10
#define gpMath_PI  31416
#define gpMath_2PI 62832
#define gpMath_PI2 15708
#define gpMath_PI4  7854
#define gpMath_PI6  5236
#define gpMath_E 27183
#define gpMath_1 10000
#define gpMath_0 0



#endif
