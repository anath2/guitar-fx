#include <CUNit/Basic>


int run_all_tests()
{
  CU_pSuite pSuite = NULL;
  pSuite = getPortAudioSuite();
  CU_automated_run_tests();
}


int main()
{
  run_all_tests();
}
