#include <CUnit.h>
#include <Basic.h>
#include <TestDB.h>
#include <gp_types.h>
#include <gp_Alloc.h>


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

CU_TestInfo gp_allocTests[] = {
		TEST_ENTRY(shouldntAllocateBecauseOfMaxSize),
		TEST_ENTRY(shouldntAllocateBecauseOfSizeBelowZero),
		TEST_ENTRY(shouldAllocate),
		TEST_ENTRY(shouldntAllocateBecauseOfMaxSizeInTwoAllocations),
		TEST_ENTRY(shouldAllocateInTwoAllocations),
		TEST_ENTRY(shouldAllocateInTwoAllocationsBecauseOfFree),
  CU_TEST_INFO_NULL
};
