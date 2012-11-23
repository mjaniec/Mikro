#ifndef __GP_TYPES
#define __GP_TYPES

typedef void gpVoid;
typedef char gpBool;
typedef unsigned char gpUByte;
typedef signed char gpByte;
typedef unsigned short gpUWord;
typedef signed short gpWord;
typedef unsigned short gpUInt;
typedef signed short gpInt;
typedef char gpChar;
typedef char* gpString;
typedef short gpFloat;

extern const gpVoid* null;

extern const long GP_FLOAT_BASE;

gpFloat gpMul(gpFloat a, gpFloat b);
gpFloat gpDiv(gpFloat a, gpFloat b);
gpFloat gpSub(gpFloat a, gpFloat b);
gpFloat gpAdd(gpFloat a, gpFloat b);
gpFloat gpNeg(gpFloat a);

#endif