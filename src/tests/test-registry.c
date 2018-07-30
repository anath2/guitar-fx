#include <CUnit/Basic.h>
int main()
{
  /* Initialize test registry */
  if (CU_SUCCESS != CU_initialize_registry()) {
    CU_get_error();
  }

  if (setupPortAudioSuite() == -1) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
