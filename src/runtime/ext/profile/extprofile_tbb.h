/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __EXTPROFILE_TBB_H__
#define __EXTPROFILE_TBB_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/ext/ext_tbb.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

inline void x_parallel_for(int64 start, int64 end, CVarRef func, int64 blocksize = -1) {
  FUNCTION_INJECTION_BUILTIN(parallel_for);
  f_parallel_for(start, end, func, blocksize);
}

inline Variant x_parallel_for_array(CVarRef arraydata, CVarRef func, int64 blocksize = -1) {
  FUNCTION_INJECTION_BUILTIN(parallel_for_array);
  return f_parallel_for_array(arraydata, func, blocksize);
}

inline Array x_concurrent_globals() {
  FUNCTION_INJECTION_BUILTIN(concurrent_globals);
  return f_concurrent_globals();
}

inline Variant x_parallel_reduce(CVarRef data, CVarRef workerfunction, CVarRef initialvalue, CVarRef joinfunction = null_variant) {
  FUNCTION_INJECTION_BUILTIN(parallel_reduce);
  return f_parallel_reduce(data, workerfunction, initialvalue, joinfunction);
}


///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXTPROFILE_TBB_H__
