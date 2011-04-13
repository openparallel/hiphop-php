
#include <runtime/ext/ext_tbb.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

void f_parallel_for(int64 start, int64 end, CVarRef func, int64 blocksize /* = -1 */) {
  throw NotImplementedException(__func__);
}

Variant f_parallel_for_array(CVarRef arraydata, CVarRef func, int64 blocksize /* = -1 */) {
  throw NotImplementedException(__func__);
}

Array f_concurrent_globals() {
  throw NotImplementedException(__func__);
}

Variant f_parallel_reduce(CVarRef data, CVarRef workerfunction, CVarRef initialvalue, CVarRef joinfunction /* = null_variant */) {
  throw NotImplementedException(__func__);
}


///////////////////////////////////////////////////////////////////////////////
}
