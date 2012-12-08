#include <CUnit.h>
#include <Basic.h>
#include <TestDB.h>

void shouldntPopBecauseOfEmptyness(){
  gpVector v;
  gpInt x;
  gpVector_init(&v);
  gpVector_popBack(&v,&x,sizeof(gpInt));
  CU_ASSERT($error==GP_EINDEX);
  gpVector_destroy(&v);
}

void shouldntPushBecauseOfNullPtr(){
  gpVector v;
  gpVector_init(&v);
  gpVector_pushBack(&v,null,sizeof(gpInt));
  CU_ASSERT($error==GP_ENULLPTR);
  gpVector_destroy(&v);
}

void shouldntPushBecauseOfNegativeSize(){
  gpVector v;
  gpInt x;
  gpVector_init(&v);
  gpVector_pushBack(&v,&x,-sizeof(gpInt));
  CU_ASSERT($error==GP_EARG);
  gpVector_destroy(&v);
}


void functionalTest()
{
	gpInt C=17;
	gpVector v;
	gpInt x=4, y;
	gpVector_init(&v);
	gpVector_pushBack(&v,&x,sizeof(gpInt));
	gpVector_popBack(&v,&y,sizeof(gpInt));
	CU_ASSERT(x==y);
	for(gpInt i=0; i<C; ++i)
		gpVector_pushBack(&v,&i,sizeof(gpInt));
	for(gpInt i=0; i<C; ++i){
		x=*((gpInt*)(gpVector_at(&v,i)));
		CU_ASSERT(x==i);
	}
	
	CU_ASSERT(C==gpVector_getSize(&v));
	gpVector_clean(&v);
	CU_ASSERT(0==gpVector_getSize(&v));
	gpVector_at(&v,5);
	CU_ASSERT($error==GP_EINDEX);

	gpVector_destroy(&v);
}



CU_TestInfo gp_VectorTests[] = {
		TEST_ENTRY(shouldntPopBecauseOfEmptyness),
		TEST_ENTRY(shouldntPushBecauseOfNullPtr),
		TEST_ENTRY(shouldntPushBecauseOfNegativeSize),
		TEST_ENTRY(functionalTest),
  CU_TEST_INFO_NULL
};
