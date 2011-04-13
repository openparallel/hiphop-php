
#include <test/test_ext_tbb.h>
#include <runtime/ext/ext_tbb.h>

IMPLEMENT_SEP_EXTENSION_TEST(Tbb);
///////////////////////////////////////////////////////////////////////////////

bool TestExtTbb::RunTests(const std::string &which) {
  bool ret = true;

  RUN_TEST(test_parallel_for);
  RUN_TEST(test_parallel_for_array);
  RUN_TEST(test_concurrent_globals);
  RUN_TEST(test_parallel_reduce);
  RUN_TEST(test_ConcurrentVector);
  RUN_TEST(test_ConcurrentHash);

  return ret;
}

///////////////////////////////////////////////////////////////////////////////

bool TestExtTbb::test_parallel_for() {
  return Count(true);
}

bool TestExtTbb::test_parallel_for_array() {
  return Count(true);
}

bool TestExtTbb::test_concurrent_globals() {
  return Count(true);
}

bool TestExtTbb::test_parallel_reduce() {
  return Count(true);
}
