
#ifndef __TEST_EXT_TBB_H__
#define __TEST_EXT_TBB_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <test/test_cpp_ext.h>

///////////////////////////////////////////////////////////////////////////////

class TestExtTbb : public TestCppExt {
 public:
  virtual bool RunTests(const std::string &which);

  bool test_parallel_for();
  bool test_parallel_for_array();
  bool test_concurrent_globals();
  bool test_parallel_reduce();
  bool test_ConcurrentVector();
  bool test_ConcurrentHash();
};

///////////////////////////////////////////////////////////////////////////////

#endif // __TEST_EXT_TBB_H__
