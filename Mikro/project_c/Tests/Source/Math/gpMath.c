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
}

void gpDivTest(){
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("81"),gpMkFloat("9")),gpMkFloat("9")));
	CU_ASSERT(gpMath_Equals(gpDiv(gpMkFloat("1000"),gpMkFloat("50")),gpMkFloat("20")));
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
}


void gpMath_CosTest(){
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpMath_PI),gpNeg(gpMath_1)));
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpNeg(gpMath_PI2)),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_Cos(gpMath_PI6),gpMkFloat("0.8660")));
}


void gpMath_TanTest(){
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpMath_0),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpNeg(gpMath_PI4)),gpNeg(gpMath_1)));
	CU_ASSERT(gpMath_Equals(gpMath_Tan(gpMath_PI6),gpMkFloat("0.5700")));
}
void gpMath_ASinTest(){
	CU_ASSERT(gpMath_Equals(gpMath_ASin(gpMath_0),        gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_ASin(gpMkFloat("0.5")),gpMath_PI6));
}
void gpMath_ACosTest(){
	CU_ASSERT(gpMath_Equals(gpMath_ACos(gpMkFloat("0.5")),gpMul(gpMkFloat("2"),gpMath_PI6)));
}

void gpMath_ATanTest(){
	CU_ASSERT(gpMath_Equals(gpMath_ATan(gpMath_0),gpMath_0));
	CU_ASSERT(gpMath_Equals(gpMath_ATan(gpMkFloat("1")),gpMath_PI4));
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
  CU_TEST_INFO_NULL
};
