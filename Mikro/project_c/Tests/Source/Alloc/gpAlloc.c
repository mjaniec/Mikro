#include <CUnit.h>
#include <Basic.h>
#include <TestDB.h>
#include <gp_Alloc.h>
#include <stdlib.h>
/*
#ifndef false
#define false 0
#endif
*/

void shouldntAllocateBecauseOfMaxSize()
{
	gpVoid* mem = gpAlloc_alloc(gpAlloc_MAX_MEM);
	CU_ASSERT_PTR_NULL(mem);
}

void shouldntAllocateBecauseOfMaxSizeInTwoAllocations()
{
	gpVoid* mem = gpAlloc_alloc(gpAlloc_MAX_MEM / 2);
	CU_ASSERT_PTR_NOT_NULL(mem);

	gpVoid* mem2 = gpAlloc_alloc(gpAlloc_MAX_MEM / 2);
	CU_ASSERT_PTR_NULL(mem2);

	gpAlloc_free(mem);
}

void shouldntAllocateBecauseOfSizeBelowZero()
{
	gpVoid* mem = gpAlloc_alloc(-1);
	CU_ASSERT_PTR_NULL(mem);
}

void shouldAllocate()
{
	gpVoid* mem = gpAlloc_alloc(gpAlloc_MAX_MEM - sizeof(gpInt));
	CU_ASSERT_PTR_NOT_NULL(mem);
	gpAlloc_free(mem);
}

void shouldAllocateInTwoAllocations()
{
	gpVoid* mem = gpAlloc_alloc(gpAlloc_MAX_MEM / 2 - sizeof(gpInt));
	CU_ASSERT_PTR_NOT_NULL(mem);

	gpVoid* mem2 = gpAlloc_alloc(gpAlloc_MAX_MEM / 2 - sizeof(gpInt));
	CU_ASSERT_PTR_NOT_NULL(mem2);

	gpAlloc_free(mem);
	gpAlloc_free(mem2);
}

void shouldAllocateInTwoAllocationsBecauseOfFree()
{
	gpVoid* mem = gpAlloc_alloc(gpAlloc_MAX_MEM - sizeof(gpInt));
	CU_ASSERT_PTR_NOT_NULL(mem);
	gpAlloc_free(mem);

	mem = gpAlloc_alloc(gpAlloc_MAX_MEM - sizeof(gpInt));
	CU_ASSERT_PTR_NOT_NULL(mem);
	gpAlloc_free(mem);
}

void shouldntAllocateBecauseOfNoConsistentSpace(){
	gpVoid* mem1=gpAlloc_alloc(100);
	CU_ASSERT_PTR_NOT_NULL(mem1);
	gpVoid* mem2=gpAlloc_alloc(10);
	CU_ASSERT_PTR_NOT_NULL(mem2);
	gpAlloc_free(mem1);
	gpVoid* mem3=gpAlloc_alloc(gpAlloc_MAX_MEM-20-sizeof(gpInt));
	CU_ASSERT_PTR_NULL(mem3);
	gpAlloc_free(mem3);
	gpAlloc_free(mem2);
}

void stressTest(){
	gpVoid* mem[30];
	for(int i=0; i<30; ++i)
		mem[i]=null;
	for(int i=0; i<3000; ++i){
		int index=i%30;
		if(i%79<index)index=i%79;
		if(i%101<index)index=i%101;
		if(mem[index]){
			gpAlloc_free(mem[index])$r;
			mem[index]=null;
		}else{
			mem[index]=gpAlloc_alloc(index%31+1)$r;
			CU_ASSERT_PTR_NOT_NULL(mem[index]);
		}
	}
	for(int i=0; i<30; ++i)
		if(mem[i])gpAlloc_free(mem[i])$r;
}

CU_TestInfo gp_allocTests[] = {
		TEST_ENTRY(shouldntAllocateBecauseOfNoConsistentSpace),
		TEST_ENTRY(shouldAllocate),
		TEST_ENTRY(shouldntAllocateBecauseOfMaxSize),
		TEST_ENTRY(shouldntAllocateBecauseOfSizeBelowZero),
		TEST_ENTRY(stressTest),
		TEST_ENTRY(shouldntAllocateBecauseOfMaxSizeInTwoAllocations),
		TEST_ENTRY(shouldAllocateInTwoAllocations),
		TEST_ENTRY(shouldAllocateInTwoAllocationsBecauseOfFree),
  CU_TEST_INFO_NULL
};
