#ifndef gp_Math_c
#define gp_Math_c

#include "..\..\Include\Math\gp_Math.h"

//It have to have short name
inline gpFloat gpMul(gpFloat a, gpFloat b){
	$fun;
	long X=a/GP_FLOAT_BASE, x=a%GP_FLOAT_BASE;
	long Y=b/GP_FLOAT_BASE, y=b%GP_FLOAT_BASE;
	return X*Y*GP_FLOAT_BASE +X*y+Y*x+x*y/GP_FLOAT_BASE;
}
inline gpFloat gpDiv(gpFloat a, gpFloat b){
	$fun;
	$assert0(b!=gpMath_0,GP_EARG);
	long A=a, B=b;
	return (A*GP_FLOAT_HALF)/B*GP_FLOAT_HALF;
}

inline gpInt gpMath_Int(gpFloat a){
	return a/GP_FLOAT_BASE;
}

inline gpFloat gpMath_FloatI(gpInt a){
	return ((gpFloat)a)*GP_FLOAT_BASE;
}

gpFloat gpMkFloat(gpString x){
	$fun;
	gpChar*p;
	gpFloat base=10;
	gpFloat res=0;
	gpBool neg=false;
	gpFloat mul;

	$assert0(x!=null,GP_ENULLPTR);
	if(*x=='-')++x,neg=true;
	else if(*x=='+')++x;

	for(p=x; *p && *p!='.' && *p!=','; ++p){
		$assert0('0'<=*p && *p<='9' ,GP_EARG);
		res*=base;
		res+=*p&15;
	}

	res*=GP_FLOAT_BASE;
	if(*p=='.'||*p==','){
		++p;
		$assert0('0'<=*p && *p<='9',GP_EARG);
		for(mul=GP_FLOAT_BASE/base; *p && mul>0; ++p, mul/=base)
			res+=mul*(*p&15);
	}
	if(neg)res=-res;
	return res;
}

inline gpFloat gpMath_Square(gpFloat a){
	return gpMul(a,a);
}

inline gpFloat gpSub(gpFloat a, gpFloat b){return a-b;}
inline gpFloat gpAdd(gpFloat a, gpFloat b){return a+b;}
inline gpFloat gpNeg(gpFloat a){return -a;}

gpFloat gpMath_Abs(gpFloat a){
	return a<0?-a:a;
}

gpFloat gpMath_MinFloat(gpFloat a, gpFloat b){
	return a> b?b:a;
}

gpFloat gpMath_MaxFloat(gpFloat a, gpFloat b){
	return a> b?a:b;
}


gpBool gpMath_Equals(gpFloat a, gpFloat b){
	$fun;
	gpFloat denom=gpMath_MinFloat(gpMath_Abs(a),gpMath_Abs(b));
	if(denom<=gpMath_EPSILION)
		return gpMath_Abs(gpSub(a,b))<gpMath_EPSILION;
	else return gpMath_Abs(gpDiv(gpSub(a,b),denom))<gpMath_EPSILION;
}

gpInt gpMath_MinInt(gpInt a, gpInt b)
{
	return a > b ? b : a;
}

gpInt* gpMath_MinIntP(gpInt* a, gpInt* b)
{
	return a > b ? b : a;
}

gpFloat gpMath_Sqrt(gpFloat a){
	$fun;
	$assert0(a>=gpMath_0, GP_EARG);
	if(a==gpMath_0)return gpMath_0;
	gpFloat x=gpMath_1;
	gpFloat x2=gpMath_1;
	gpFloat two=gpMkFloat("2");

	while(!gpMath_Equals(a,gpMath_Square(x)) || !gpMath_Equals(x,x2)){
		x2=x;
		x=gpDiv(x+gpDiv(a,x),two);
	}
	return x;
}
gpFloat gpMath_Exp(gpFloat a){
	$fun;
	gpFloat res=gpMath_1;
	gpFloat ml =gpMath_1;
	gpFloat fac=gpMath_1;
	gpFloat Iter=gpMath_0;

	for(gpInt iter=0; iter<8; ++iter){
		Iter=gpAdd(Iter,gpMath_1);
		ml=gpMul(ml,a);
		fac=gpMul(fac,Iter);
		res+=gpDiv(ml,fac);
	}
	return res;
}
gpFloat gpMath_PowI(gpFloat base, gpInt exp){
	$fun;
	if(exp==0)return gpMath_1;
	if(exp==1)return base;
	gpFloat half=gpMath_PowI(base,exp/2);
	if(!(exp&1))return gpMul(half,half);
	else return gpMul(half,gpMul(half,base));
}


gpFloat gpMath_Sin(gpFloat x){
	$fun;
	if(x<gpMath_0)return gpNeg(gpMath_Sin(gpNeg(x)));
	if(x>gpMath_PI){
		gpFloat y=gpMath_FloatI(gpMath_Int(gpDiv(x,gpMath_2PI)));
		x=gpSub(x,gpMul(y,gpMath_2PI));
	}
	if(x>gpMath_PI)return gpNeg(gpMath_Sin(gpSub(gpMath_2PI,x)));
	if(x>gpMath_PI2)return gpMath_Sin(gpSub(gpMath_PI,x));
	if(x>gpMath_PI4)return gpMath_Cos(gpSub(gpMath_PI2,x));

	gpFloat d1=gpMkFloat("-6");
	gpFloat d2=gpMkFloat("-20");
	gpFloat d3=gpMkFloat("-42");

	gpFloat x1=x;
	gpFloat x2=gpMath_Square(x);
	gpFloat x3=gpDiv(gpMul(x2,x1),d1);
	gpFloat x5=gpDiv(gpMul(x3,x2),d2);
	gpFloat x7=gpDiv(gpMul(x5,x2),d3);

	return gpAdd(x,gpAdd(x3,gpAdd(x5,x7)));
}
gpFloat gpMath_Cos(gpFloat x){
	$fun;
	if(x<gpMath_0)return gpMath_Cos(gpNeg(x));
	if(x>gpMath_PI){
		gpFloat y=gpMath_FloatI(gpMath_Int(gpDiv(x,gpMath_2PI)));
		x=gpSub(x,gpMul(y,gpMath_2PI));
	}
	if(x>gpMath_PI)return gpMath_Cos(gpSub(gpMath_2PI,x));
	if(x>gpMath_PI2)return gpNeg(gpMath_Cos(gpSub(gpMath_PI,x)));
	if(x>gpMath_PI4)return gpMath_Sin(gpSub(gpMath_PI2,x));

	gpFloat d1=gpMkFloat("-2");
	gpFloat d2=gpMkFloat("-12");
	gpFloat d3=gpMkFloat("-30");
	gpFloat d4=gpMkFloat("-56");

	gpFloat x2=gpDiv(gpMath_Square(x),d1);
	gpFloat x4=gpDiv(gpMul(x2,x2),d2);
	gpFloat x6=gpDiv(gpMul(x2,x4),d3);
	gpFloat x8=gpDiv(gpMul(x2,x6),d4);

	return gpAdd(gpMath_1, gpAdd(x2,gpAdd(x4,gpAdd(x6,x8))));
}
gpFloat gpMath_Tan(gpFloat x){
	$fun;
	//I no it sucks but do we really need other solutions?
	while(x>gpMath_PI2)x-=gpMath_PI;
	if(x<0)return gpNeg(gpMath_Tan(gpNeg(x)));

	$assert0(!gpMath_Equals(gpMath_PI2,x),GP_EARG);
	return gpDiv(gpMath_Sin(x),gpMath_Cos(x));
}
gpFloat gpMath_ASin(gpFloat x){
	$fun;
	$assert0(gpNeg(gpMath_1)<=x && x<=gpMath_1,GP_EARG);
	gpFloat m1=gpMkFloat("0.1667");
	gpFloat m2=gpMkFloat("0.075");
	gpFloat m3=gpMkFloat("0.0446");

	gpFloat x2=gpMath_Square(x);
	gpFloat x3=gpMul(x ,x2);
	gpFloat x5=gpMul(x3,x2);
	gpFloat x7=gpMul(x5,x2);

	return gpAdd(x,gpAdd(gpMul(x3,m1),gpAdd(gpMul(x5,m2),gpMul(x7,m3))));
}
gpFloat gpMath_ACos(gpFloat x){
	$fun;
	$assert0(gpNeg(gpMath_1)<=x && x<=gpMath_1,GP_EARG);
	return gpMath_PI2-gpMath_ASin(x);
}
gpFloat gpMath_ATan(gpFloat x){
	$fun;
	return gpMath_ASin(gpDiv(x,gpMath_Sqrt(gpAdd(gpMath_Square(x),1))));
}


#endif
