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

#ifndef __EXT_TBB_H__
#define __EXT_TBB_H__

#include <runtime/base/base_includes.h>

#include <tbb/tbb.h>
#include "tbb_hashcompare.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

void f_parallel_for(int64 start, int64 end, CVarRef func, int64 blocksize = -1);
Variant f_parallel_for_array(CVarRef arraydata, CVarRef func, int64 blocksize = -1);
Array f_concurrent_globals();
Variant f_parallel_reduce(CVarRef data, CVarRef workerfunction, CVarRef initialvalue, CVarRef joinfunction = null_variant);


///////////////////////////////////////////////////////////////////////////////
// class ConcurrentVector

FORWARD_DECLARE_CLASS(concurrentvector);
class c_concurrentvector : public ExtObjectData {
 public:
  BEGIN_CLASS_MAP(concurrentvector)
  END_CLASS_MAP(concurrentvector)
  DECLARE_CLASS(concurrentvector, ConcurrentVector, ObjectData)
  DECLARE_INVOKES_FROM_EVAL
  ObjectData* dynCreate(CArrRef params, bool init = true);

  // need to implement
  public: c_concurrentvector();
  public: ~c_concurrentvector();
  public: void t___construct(CArrRef arraydata = null_array);
  public: void t_push(CVarRef data_item);
  public: int64 t_size();
  public: Variant t_element_at(int64 index);
  public: void t_set_at(int64 index, CVarRef data_item);
  public: Array t_as_array();
  public: Variant t___destruct();

  // implemented by HPHP
  public: c_concurrentvector *create(Array arraydata = null_array);
  public: void dynConstruct(CArrRef Params);
  public: void dynConstructFromEval(Eval::VariableEnvironment &env,
                                    const Eval::FunctionCallExpression *call);
  public: virtual void destruct();

  private:
  tbb::concurrent_vector<Variant> vectorData;

};

///////////////////////////////////////////////////////////////////////////////
// class ConcurrentHash

typedef tbb::concurrent_hash_map<Variant, Variant, VarVarHashCompare> VarVarHashData;

FORWARD_DECLARE_CLASS(concurrenthash);
class c_concurrenthash : public ExtObjectData {
 public:
  BEGIN_CLASS_MAP(concurrenthash)
  END_CLASS_MAP(concurrenthash)
  DECLARE_CLASS(concurrenthash, ConcurrentHash, ObjectData)
  DECLARE_INVOKES_FROM_EVAL
  ObjectData* dynCreate(CArrRef params, bool init = true);

  // need to implement
  public: c_concurrenthash();
  public: ~c_concurrenthash();
  public: void t___construct(CArrRef arraydata = null_array);
  public: int64 t_size();
  public: Variant t_find(CVarRef key);
  public: void t_erase(CVarRef key);
  public: void t_insert(CVarRef key, CVarRef data_item);
  public: Array t_as_array();
  public: Variant t___destruct();

  // implemented by HPHP
  public: c_concurrenthash *create(Array arraydata = null_array);
  public: void dynConstruct(CArrRef Params);
  public: void dynConstructFromEval(Eval::VariableEnvironment &env,
                                    const Eval::FunctionCallExpression *call);
  public: virtual void destruct();

  private:
  VarVarHashData hashData;

};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXT_TBB_H__
