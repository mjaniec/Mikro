#include <TestDB.h>
#include <stdlib.h>

extern CU_TestInfo gp_allocTests[];

CU_SuiteInfo gp_suites[] = {
		SUITE_ENTRY(gp_allocTests, NULL, NULL),
/*  { "suitename1", NULL, NULL, gp_allocTests}, */
  /* { "suitename2", suite2_init-func, suite2_cleanup_func, test_array2 }, */
  CU_SUITE_INFO_NULL
};