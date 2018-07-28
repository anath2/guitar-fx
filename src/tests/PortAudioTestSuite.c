#include <CUnit/Basic.h>

/* Exploratory tests for port audio */
int setupPortAudioSuite(void)
{
  CU_pSuite pSuite = NULL;
  pSuite = CU_add_suite("Port Audio Test Suite", initPortAudioTestSuite, cleanPortAudioTestSuite);

  if (NULL == pSuite) {
    return -1;
  }

  if ((NULL == CU_add_test(pSuite, "Test generate signal with port audio", testSawTooth))) {
      return -1;
  }

  return 0;

}


int initPortAudioTestSuite(void)
{
  return 0;
}


int cleanPortAudioTestSuite(void)
{
  return 0;
}


void testSawTooth(void)
{
  /* Generate a saw tooth wave using port audio */
}
