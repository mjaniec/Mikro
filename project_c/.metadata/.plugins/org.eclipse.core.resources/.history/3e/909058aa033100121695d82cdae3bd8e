#include <Basic.h>

extern CU_SuiteInfo gp_suites[];

int main()
{
   if (CUE_SUCCESS != CU_initialize_registry())
   {
      return CU_get_error();
   }

   if(CUE_SUCCESS != CU_register_suites(gp_suites))
   {
	   CU_cleanup_registry();
	   return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
