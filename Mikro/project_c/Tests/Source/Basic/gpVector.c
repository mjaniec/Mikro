#include <CUnit.h>
#include <Basic.h>
#include <TestDB.h>

void shouldntPopBecauseOfEmptyness(){
  gpVector v;
  gpInt x;
  gpVector_init(&v)$c;
  gpVector_popBack(&v,&x,sizeof(gpInt))$c;
  CU_ASSERT($error==GP_EINDEX);
  gpVector_destroy(&v)$c;
}

void shouldntPushBecauseOfNullPtr(){
  gpVector v;
  gpVector_init(&v)$c;
  gpVector_pushBack(&v,null,sizeof(gpInt))$c;
  CU_ASSERT($error==GP_ENULLPTR);
  gpVector_destroy(&v)$c;
}

void shouldntPushBecauseOfNegativeSize(){
  gpVector v;
  gpInt x;
  gpVector_init(&v)$c;
  gpVector_pushBack(&v,&x,-sizeof(gpInt))$c;
  CU_ASSERT($error==GP_EARG);
  gpVector_destroy(&v)$c;
}


void vectorFunctionalTest()
{
	gpInt C=17;
	gpVector v;
	gpInt x=4, y;
	gpVector_init(&v)$c;
	gpVector_pushBack(&v,&x,sizeof(gpInt))$c;
	gpVector_popBack(&v,&y,sizeof(gpInt))$c;
	CU_ASSERT(x==y);
	for(gpInt i=0; i<C; ++i)
		gpVector_pushBack(&v,&i,sizeof(gpInt))$c;
	for(gpInt i=0; i<C; ++i){
		x=*((gpInt*)(gpVector_at(&v,i)))$c;
		CU_ASSERT(x==i);
	}
	
	CU_ASSERT(C==gpVector_getSize(&v));
	gpVector_clean(&v)$c;
	CU_ASSERT(0==gpVector_getSize(&v));
	gpVector_at(&v,5)$c;
	CU_ASSERT($error==GP_EINDEX);

	gpVector_destroy(&v)$c;
}

void vectorStressTest(){
	gpVector vec;
	gpPoint p;
	gpVector_init(&vec)$c;
	for(gpInt i=0; i<50; ++i){
		gpVector_clean(&vec)$c;
		for(gpInt j=0; j<i; ++j){
			p.x=j; p.y=j;
			gpVector_pushBack(&vec,&p,sizeof(gpPoint))$c;
		}
		for(gpInt j=0; j<i; ++j){
			CU_ASSERT(j==((gpPoint*)gpVector_at(&vec,j))->x)$c;
		}
	}
	gpVector_destroy(&vec)$c;
}



CU_TestInfo gp_VectorTests[] = {
		TEST_ENTRY(shouldntPopBecauseOfEmptyness),
		TEST_ENTRY(shouldntPushBecauseOfNullPtr),
		TEST_ENTRY(shouldntPushBecauseOfNegativeSize),
		TEST_ENTRY(vectorFunctionalTest),
		TEST_ENTRY(vectorStressTest),
  CU_TEST_INFO_NULL
};
