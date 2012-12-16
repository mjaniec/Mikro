#ifndef GP_MATH_H
#define GP_MATH_H
#include "../Base/gp.h"

gpFloat gpMul(gpFloat a, gpFloat b);
gpFloat gpDiv(gpFloat a, gpFloat b);
gpFloat gpSub(gpFloat a, gpFloat b);
gpFloat gpAdd(gpFloat a, gpFloat b);
gpFloat gpNeg(gpFloat a);

gpInt gpMath_MinInt(gpInt, gpInt);

gpByte gpMath_Sign(gpFloat x);
gpFloat gpMath_Abs(gpFloat a);
gpFloat gpMath_Square(gpFloat a);
gpFloat gpMath_Sqrt(gpFloat a);
gpFloat gpMath_Exp(gpFloat a);
gpFloat gpMath_PowI(gpFloat base, gpInt exp);
gpFloat gpMath_Sin(gpFloat x);
gpFloat gpMath_Cos(gpFloat x);
gpFloat gpMath_Tan(gpFloat x);
gpFloat gpMath_ATan2(gpFloat x, gpFloat y);
gpFloat gpMath_ASin(gpFloat x);
gpFloat gpMath_ACos(gpFloat x);
gpFloat gpMath_ATan(gpFloat x);
gpFloat gpMath_MinFloat(gpFloat a, gpFloat b);
gpFloat gpMath_MaxFloat(gpFloat a, gpFloat b);

gpBool  gpMath_Equals(gpFloat a, gpFloat b);

gpInt   gpMath_Int(gpFloat a);
gpFloat gpMath_FloatI(gpInt a);


gpFloat gpMath_AngleToAzimut(gpPoint a,gpPoint b);

gpFloat gpMkFloat(gpString x);

#define GP_FLOAT_BASE 10000
#define gpMath_EPSILION 10
#define gpMath_PI  31416
#define gpMath_2PI 62832
#define gpMath_PI2 15708
#define gpMath_PI4  7854
#define gpMath_PI6  5236
#define gpMath_E 27183
#define gpMath_1 10000
#define gpMath_2 20000
#define gpMath_3 30000
#define gpMath_SINPI4 7071
#define gpMath_0 0



#endif
