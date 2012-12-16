#ifndef gp_Math_c
#define gp_Math_c

#include "..\..\Include\Math\gp_Math.h"

gpByte gpMath_Sign(gpFloat x){
	if(x<0)return -1;
	if(x>0)return +1;
	return 0;
}

gpFloat gpMul(gpFloat a, gpFloat b){
	$fun;
	long X=a/GP_FLOAT_BASE, x=a%GP_FLOAT_BASE;
	long Y=b/GP_FLOAT_BASE, y=b%GP_FLOAT_BASE;
	return X*Y*GP_FLOAT_BASE +X*y+Y*x+x*y/GP_FLOAT_BASE;
}


gpFloat gpDiv(gpFloat a, gpFloat b){
	$fun;

	if(gpMath_Sign(a)*gpMath_Sign(b)==-1)
		return gpNeg(gpDiv(gpMath_Abs(a),gpMath_Abs(b)));

	a=gpMath_Abs(a); b=gpMath_Abs(b);
	if(a==gpMath_0)return gpMath_0;
	gpFloat x=1,y,z;
	gpFloat tmp = gpMul(x, b);

	for(;tmp <= a && tmp >= gpMath_0;)
	{
		x <<= 1;
		tmp = gpMul(x, b);
	}


	x>>=1;
	for(y=x>>1; y>0; y>>=1){
		z=gpAdd(x,y);
		if(gpMul(z,b)<=a && gpMul(z, b) > 0)
		{
			x=z;
		}
	}
	if(gpMul(x,b)>a)--x;

	return x;
}

gpInt gpMath_Int(gpFloat a){
	return a/GP_FLOAT_BASE;
}

gpFloat gpMath_FloatI(gpInt a){
	return ((gpFloat)a)*GP_FLOAT_BASE;
}

/*
gpFloat gpMath_AngleToAzimut(gpPoint*a,gpPoint*b){
	gpPoint x=gpPoint_init(b->x-a->x,b->y-a->y);

	gpFloat product=gpNeg(x.y);
	gpFloat length =gpMath_Sqrt(gpAdd(gpMath_Square(x.x),gpMath_Square(x.y)));
	gpFloat sin=gpNeg(gpDiv(product,length));
	//printf("\nproduct: %d.%d, length: %d.%d",
	//		(int)(product/GP_FLOAT_BASE),(int)(product%GP_FLOAT_BASE),
	//		(int)(length/GP_FLOAT_BASE),(int)(length%GP_FLOAT_BASE));
	//product = length(x)*sin(\alpha)


	//printf("\na: (%d.%d,%d.%d),  sin: %d.%d\n",
	//		(int)((x.x)/GP_FLOAT_BASE),(int)((x.x)%GP_FLOAT_BASE),
	//		(int)((x.y)/GP_FLOAT_BASE),(int)((x.y)%GP_FLOAT_BASE),
	//		(int)(sin  /GP_FLOAT_BASE),(int)(sin  %GP_FLOAT_BASE));

	if(gpMath_Equals(x.x,gpMath_0)){
		return (x.y>gpMath_0)?gpMath_PI2:gpNeg(gpMath_PI);
	}
	if(x.x>0){
		return gpMath_ASin(sin);
	}
	else{
		return gpAdd(gpMath_PI,gpMath_ASin(gpMath_Abs(sin)));
	}
	return 0;
}
*/

gpFloat gpMkFloat(gpString x){
	$fun;
	gpChar*p;
	gpFloat base=10;
	gpFloat res=0;
	gpBool neg=false;
	gpFloat mul;
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
	if(denom<GP_FLOAT_BASE)
		return gpMath_Abs(gpSub(a,b))<gpMath_EPSILION;
	else return gpMath_Abs(gpDiv(gpSub(a,b),denom))<gpMath_EPSILION;
}

gpInt gpMath_MinInt(gpInt a, gpInt b)
{
	return a > b ? b : a;
}

gpFloat gpMath_Sqrt(gpFloat a){
	$fun;
	$assert0(a>=gpMath_0, GP_EARG);
	gpFloat xn = a;
	gpFloat xn_1;
	gpFloat two = gpMath_2;
	do
	{
		xn_1 = xn;
		xn = gpDiv(gpAdd(xn_1, gpDiv(a, xn_1)), two);
	} while(!gpMath_Equals(xn, xn_1));
	return xn;
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
	gpFloat d2=gpMkFloat("6");
	gpFloat d3=gpMkFloat("15");
	gpFloat d4=gpMkFloat("28");

	gpFloat x2=gpDiv(gpMath_Square(x),d1);
	gpFloat x4=gpDiv(gpMul(x2,x2),d2);
	gpFloat x6=gpDiv(gpMul(x2,x4),d3);
	gpFloat x8=gpDiv(gpMul(x2,x6),d4);

	return gpAdd(gpMath_1, gpAdd(x2,gpAdd(x4,gpAdd(x6,x8))));
}
gpFloat gpMath_Tan(gpFloat x){
	$fun;
	while(x>gpMath_PI2)x-=gpMath_PI;
	if(x<0)return gpNeg(gpMath_Tan(gpNeg(x)));

	$assert0(!gpMath_Equals(gpMath_PI2,x),GP_EARG);
	return gpDiv(gpMath_Sin(x),gpMath_Cos(x));
}

gpFloat gpMath_ASin(gpFloat x){
	$fun;
	$assert0(gpNeg(gpMath_1)<=x && x<=gpMath_1,GP_EARG);
	gpFloat denom=gpAdd(gpMath_1,gpMath_Sqrt(gpSub(gpMath_1,gpMath_Square(x))));
	return gpMul(gpMath_2,gpMath_ATan(gpDiv(x,denom)));
}

gpFloat gpMath_ACos(gpFloat x){
	$fun;
	$assert0(gpNeg(gpMath_1)<=x && x<=gpMath_1,GP_EARG);
	return gpMath_PI2-gpMath_ASin(x);
}

gpFloat _gpMath_ATan_PadeApproximation(gpFloat x)
{
	$fun;
	x=gpSub(x,gpMath_1);
	gpFloat m1=gpMkFloat("0.25");
	gpFloat m2=gpMkFloat("5.1416");
	gpFloat m3=gpMkFloat("2.0472");
	gpFloat m4=gpMkFloat("0.3333");
	gpFloat x2=gpMath_Square(x);

	gpFloat value=gpAdd(gpMath_PI,gpAdd(gpMul(m2,x),gpMul(m3,x2)));
	gpFloat denom=gpAdd(gpMath_1,gpAdd(x,gpMul(m4,x2)));

	value=gpMul(m1,gpDiv(value,denom));
	gpFloat rest=gpMath_0;
	x=gpAdd(x,gpMath_1);
	if(x<gpMath_2)return value;

	if(x<gpMkFloat("10") ){
		rest=gpMul(gpSub(x,gpMath_2),gpMkFloat("0.0021"));
		return gpAdd(value,rest);
	}else if(x<gpMkFloat("30")){
		rest=gpMkFloat("0.0168");
		rest=gpAdd(rest,gpMul(gpMkFloat("0.0005"),gpSub(x,gpMkFloat("10"))));
		return gpAdd(value,rest);
	}else {
		return(gpAdd(value,gpMkFloat("0.03")));
	}
}

gpFloat _gpMath_ATan_TylorApproximation(gpFloat x){
	$fun;
	gpFloat m1=gpMkFloat("-0.3333");
	gpFloat m2=gpMkFloat("0.2");
	gpFloat x2=gpMath_Square(x);
	gpFloat x3=gpMul(x2,x);
	gpFloat x5=gpMul(x2,x3);
	return gpAdd(x,gpAdd(gpMul(m1,x3),gpMul(m2,x5)));
}


gpFloat gpMath_ATan(gpFloat x){
	$fun;
	if(x<gpMath_0)return gpNeg(gpMath_ATan(gpNeg(x)));
	if(x<gpMkFloat("0.46"))
		return _gpMath_ATan_TylorApproximation(x);
	else return _gpMath_ATan_PadeApproximation(x);
}

gpFloat gpMath_ATan2(gpFloat x, gpFloat y)
{
	if(x > 0)
	{
		return gpMath_ATan(gpDiv(y, x));
	}
	else if(y >= 0 && x < 0)
	{
		return gpAdd(gpMath_ATan(gpDiv(y, x)), gpMath_PI);
	}
	else if(y < 0 && x < 0)
	{
		return gpSub(gpMath_ATan(gpDiv(y, x)), gpMath_PI);
	}
	else if(y > 0 && gpMath_Equals(x, gpMath_0))
	{
		return gpDiv(gpMath_PI, gpMkFloat("2"));
	}
	else if(y < 0 && gpMath_Equals(x, gpMath_0))
	{
		return gpNeg(gpDiv(gpMath_PI, gpMkFloat("2")));
	}
	else
	{
		return gpMath_PI;
	}
}

gpFloat gpMath_AngleToAzimut(gpPoint first, gpPoint second)
{
	gpFloat delta_x = gpSub(first.x, second.x);
	gpFloat delta_y = gpNeg(gpSub(first.y, second.y));
	gpFloat tmp =  gpMath_ATan2(delta_x, delta_y);
	while(tmp > gpMath_PI)
	{
		tmp = gpSub(tmp, gpMath_PI);
	}

	while(tmp < gpNeg(gpMath_PI))
	{
		tmp = gpAdd(tmp, gpMath_PI);
	}

	if(delta_x > 0 && delta_y > 0)
	{
		tmp = gpSub(gpDiv(gpMath_PI, gpMath_2), tmp);
	}
	else if(delta_x < 0 && delta_y > 0)
	{
		tmp = gpSub(gpAdd(gpMath_2PI, gpDiv(gpMath_PI, gpMath_2)), tmp);
	}
	else
	{
		tmp = gpAdd(gpNeg(tmp), gpDiv(gpMath_PI, gpMath_2));
	}

	return tmp;
}

#endif
