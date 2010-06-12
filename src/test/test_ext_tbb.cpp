
#include <test/test_ext_tbb.h>
#include <runtime/ext/ext_tbb.h>

IMPLEMENT_SEP_EXTENSION_TEST(Tbb);
///////////////////////////////////////////////////////////////////////////////

bool TestExtTbb::RunTests(const std::string &which) {
  bool ret = true;

  RUN_TEST(test_yo);

  return ret;
}

///////////////////////////////////////////////////////////////////////////////

bool TestExtTbb::test_yo() {
  return Count(true);
}
