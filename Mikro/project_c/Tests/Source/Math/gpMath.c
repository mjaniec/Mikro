#include <CUnit.h>
#include <TestDB.h>
#ifndef NULL
#define NULL 0
#endif

void gpMkFloatTest(){
	CU_ASSERT(gpMath_Equals(GP_FLOAT_BASE,gpMkFloat("1")));
	CU_ASSERT(gpMath_Equals(GP_FLOAT_BASE/10+GP_FLOAT_BASE,gpMkFloat("1.1")));
	CU_ASSERT(gpMath_Equals(-2*GP_FLOAT_BASE/100,gpMkFloat("-0.02")));
}

void gpMath_EqualsTest(){
	gpFloat a=0;
	gpFloat b=gpMath_EPSILION;
	CU_ASSERT(!gpMath_Equals(a,b));
	CU_ASSERT(!gpMath_Equals(a,b+1));
	CU_ASSERT( gpMath_Equals(-1,1));
	CU_ASSERT(!gpMath_Equals(gpNeg(gpMath_1),gpMath_1));
}

void gpMulTest(){
	CU_ASSERT(gpMath_Equals(gpMul(gpMkFloat("9"),gpMkFloat("9")),gpMkFloat("81")));
	CU_ASSERT(gpMath_Equals(gpMul(gpMkFloat("125"),gpMkFloat("8")),gpMkFloat("1000")));
	CU_ASSERT(gpMath_Equals(gpMul(gpMkFloat("500"),gpMkFloat("200")),gpMkFloat("100000")));
	CU_ASSERT(gpMath_Equals(gpMul(gpMkFloat("-0.25"),gpMkFloat("0.2")),gpMkFloat("-0.05")));
	CU_ASSERT(gpMath_Equals(gpMul(gpMkFloat("1000"),gpMkFloat("-0.001")),gpMkFloat("-1")));
	CU_ASSERT(gpMath_Equals(gpMul(gpMath_0,gpMkFloat("457")),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMul(gpMkFloat("-18"),gpMkFloat("-0.5")),gpMkFloat("9")));
}

void gpDivTest(){
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("81"),gpMkFloat("9")),gpMkFloat("9")));
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("1000"),gpMkFloat("50")),gpMkFloat("20")));
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("0.5"),gpMkFloat("5")),gpMkFloat("0.1")));
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("-0.05"),gpMkFloat("0.2")),gpMkFloat("-0.25")));
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("-1"),gpMkFloat("-0.001")),gpMkFloat("1000")));
	CU_ASSERT(gpMath_Equals(gpDiv(gpMath_0,gpMkFloat("457")),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("-18"),gpMkFloat("-2")),gpMkFloat("9")));
}

void gpMath_AbsTest(){
	CU_ASSERT(gpMath_Abs(15)==15);
	CU_ASSERT(gpMath_Abs(0)==0);
	CU_ASSERT(gpMath_Abs(-5)==5);
}

void gpMath_MinIntTest()
{
	CU_ASSERT(gpMath_MinInt(1,5)==1);
	CU_ASSERT(gpMath_MinInt(0,0)==0);
	CU_ASSERT(gpMath_MinInt(1,-5)==-5);
}

void gpMath_SqrtTest(){
	CU_ASSERT(gpMath_Equals(gpMath_Sqrt(gpMkFloat("81")),gpMkFloat("9")));
	CU_ASSERT(gpMath_Equals(gpMath_Sqrt(gpMkFloat("0.16")),gpMkFloat("0.4")));
	CU_ASSERT(gpMath_Equals(gpMath_Sqrt(gpMath_0),gpMath_0));
	gpFloat x=gpMkFloat("15.23");
	CU_ASSERT(gpMath_Equals(gpMath_Sqrt(gpMath_Square(x)),x));
	gpMath_Sqrt(gpMkFloat("-5"));
	CU_ASSERT($error==GP_EARG);
}

void gpMath_ExpTest(){
	CU_ASSERT(gpMath_Equals(gpMath_Exp(gpMkFloat("2")), gpMul(gpMath_E,gpMath_E)) );
	CU_ASSERT(gpMath_Equals(gpMath_Exp(gpMath_0),gpMath_1));
}

void gpMath_PowITest(){
	CU_ASSERT(gpMath_Equals(gpMath_PowI(gpMath_E,3),gpMul(gpMul(gpMath_E,gpMath_E),gpMath_E)));
	CU_ASSERT(gpMath_Equals(gpMath_PowI(gpMkFloat("2"),4),gpMkFloat("16")));
}


void gpMath_SinTest(){
	CU_ASSERT(gpMath_Equals(gpMath_Sin(gpMath_PI),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_Sin(gpNeg(gpMath_PI2)),gpMkFloat("-1")));
	CU_ASSERT(gpMath_Equals(gpMath_Sin(gpMath_PI6),gpMkFloat("0.5")));
	CU_ASSERT(gpMath_Equals(gpMath_Sin(gpMkFloat("154")),gpMkFloat("-0.0619")));
	CU_ASSERT(gpMath_Equals(gpMath_Sin(gpMkFloat("-2")),gpMkFloat("-0.9093")));
}


void gpMath_CosTest(){
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpMath_PI),gpNeg(gpMath_1)));
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpNeg(gpMath_PI2)),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpMath_PI6),gpMkFloat("0.8660")));
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpMkFloat("7")),gpMkFloat("0.7539")));
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpMkFloat("-1.45")),gpMkFloat("0.1205")));
}


void gpMath_TanTest(){
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpMath_0),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpNeg(gpMath_PI4)),gpNeg(gpMath_1)));
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpMath_PI6),gpMkFloat("0.5774")));
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpMkFloat("-0.33")),gpMkFloat("-0.3425")));
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpMkFloat("5")),gpMkFloat("-3.3805")));
}
void gpMath_ASinTest(){
	CU_ASSERT(gpMath_Equals(gpMath_ASin(gpMath_0),        gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_ASin(gpMkFloat("0.5")),gpMath_PI6));
	CU_ASSERT(gpMath_Equals(gpMath_ASin(gpMkFloat("-0.8")),gpMkFloat("-0.9273")));
	CU_ASSERT(gpMath_Equals(gpMath_ASin(gpMkFloat("0.1")),gpMkFloat("0.1001")));
	CU_ASSERT(gpMath_Equals(gpMath_ASin(gpMkFloat("0.99")),gpMkFloat("1.4293")));
}
void gpMath_ACosTest(){
	CU_ASSERT(gpMath_Equals(gpMath_ACos(gpMkFloat("0.5")),gpMul(gpMkFloat("2"),gpMath_PI6)));
	CU_ASSERT(gpMath_Equals(gpMath_ACos(gpMkFloat("-0.8")),gpMkFloat("2.4981")));
	CU_ASSERT(gpMath_Equals(gpMath_ACos(gpMkFloat("0.1")),gpMkFloat("1.4706")));
	CU_ASSERT(gpMath_Equals(gpMath_ACos(gpMkFloat("0.99")),gpMkFloat("0.1415")));
}


void gpMath_ATanTest(){
	CU_ASSERT(gpMath_Equals(gpMath_ATan(gpMath_0),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_ATan(gpMkFloat("1")),gpMath_PI4));
	CU_ASSERT(gpMath_Equals(gpMath_ATan(gpMkFloat("-28")),gpMkFloat("-1.5350")));
}

void gpMath_AngleToAzimutTest(){
	gpPoint _10_10=gpPoint_init(gpMkFloat("10"),gpMkFloat("10"));
	gpPoint _12_10=gpPoint_init(gpMkFloat("12"),gpMkFloat("10"));
	gpPoint _12_12=gpPoint_init(gpMkFloat("12"),gpMkFloat("12"));
	gpPoint _10_12=gpPoint_init(gpMkFloat("10"),gpMkFloat("12"));
	gpPoint _0   = gpPoint_init(gpMath_0,gpMath_0);
	gpPoint _1_3 = gpPoint_init(gpMath_1,gpMath_3);
	gpPoint px   = gpPoint_init(gpNeg(gpMath_2),gpMath_1);

	CU_ASSERT(gpMath_Equals(gpMath_0,gpMath_AngleToAzimut(&_10_10,&_12_10)));
	CU_ASSERT(gpMath_Equals(gpMath_PI4,gpMath_AngleToAzimut(&_10_10,&_12_12)));
	//printf("110: %d %d",gpMath_AngleToAzimut(&_10_10,&_12_12), gpMath_PI4);
	CU_ASSERT(gpMath_Equals(gpMul(gpMkFloat("5"),gpMath_PI4),
							gpMath_AngleToAzimut(&_12_12,&_10_10)
							));
	CU_ASSERT(gpMath_Equals(gpMath_PI2,gpMath_AngleToAzimut(&_10_10,&_10_12)));
	CU_ASSERT(gpMath_Equals(gpMkFloat("1.2490"),gpMath_AngleToAzimut(&_0,&_1_3)));
	CU_ASSERT(gpMath_Equals(gpMkFloat("3.6052"),gpMath_AngleToAzimut(&_0,&px)));
}


CU_TestInfo gp_MathTests[] = {
		TEST_ENTRY(gpMkFloatTest),
		TEST_ENTRY(gpMath_EqualsTest),
		TEST_ENTRY(gpMulTest),
		TEST_ENTRY(gpDivTest),
		TEST_ENTRY(gpMath_AbsTest),
		TEST_ENTRY(gpMath_MinIntTest),
		TEST_ENTRY(gpMath_SqrtTest),
		TEST_ENTRY(gpMath_ExpTest),
		TEST_ENTRY(gpMath_PowITest),
		TEST_ENTRY(gpMath_SinTest),
		TEST_ENTRY(gpMath_CosTest),
		TEST_ENTRY(gpMath_TanTest),
		TEST_ENTRY(gpMath_ASinTest),
		TEST_ENTRY(gpMath_ACosTest),
		TEST_ENTRY(gpMath_ATanTest),
		TEST_ENTRY(gpMath_AngleToAzimutTest),
  CU_TEST_INFO_NULL
};
