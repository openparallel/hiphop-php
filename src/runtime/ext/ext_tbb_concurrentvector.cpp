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
   | TBB - implement the concurrent_vector class and the 				  |
   | concurrent_globals function										  |
   +----------------------------------------------------------------------+
*/

#include <runtime/ext/ext_tbb.h>
#include <tbb/tbb.h>
#include "tbb_context.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

c_concurrentvector::c_concurrentvector() {

}


c_concurrentvector::~c_concurrentvector() {

}

// Construct from an optional array
void c_concurrentvector::t___construct(CArrRef srcarray) {
	INSTANCE_METHOD_INJECTION(concurrentvector, concurrentvector::__construct);
  
	if(srcarray.isNull()) {
	  return;
	}

	ArrayData *pdSrcData = srcarray.getArrayData();

	vectorData.grow_to_at_least(pdSrcData->size());
	Variant v = pdSrcData->reset();

	// Copy each row
	int i=0;
	while(!v.isBoolean() || v.toBoolean())
	{
		vectorData[i++] = v;
  		v = pdSrcData->next();
	}
}

// Push a Variant data item onto the end of the array
void c_concurrentvector::t_push(CVarRef data_item) {
  INSTANCE_METHOD_INJECTION(concurrentvector, concurrentvector::push);
  vectorData.push_back(Variant(data_item));
}

// Get the size of the array
int64 c_concurrentvector::t_size() {
  INSTANCE_METHOD_INJECTION(concurrentvector, concurrentvector::size);
  return vectorData.size();
}

// Get the element at 'index'
Variant c_concurrentvector::t_element_at(int64 index) {
	if(index < 0 || index >= (int64)vectorData.size()) {
		raise_error("ConcurrentVector->element_at, index %lld out of range [0,%lld)", index, (int64)vectorData.size());
		return Variant();
	}

	return vectorData[index];
}

// Set the element at 'index' to 'data_item'
void c_concurrentvector::t_set_at(int64 index, CVarRef data_item) {
	if(index < 0) {
		raise_error("ConcurrentVector->set_at, index %lld < 0", index);
		return;
	}

	if(index >= (int64)vectorData.size()) {
		vectorData.grow_to_at_least(index+1);
	}

	vectorData[index] = data_item;
}

// Return as a PHP array
Array c_concurrentvector::t_as_array() {
	Array res;

	for(tbb::concurrent_vector<Variant>::const_iterator i(vectorData.begin()); i != vectorData.end(); i++) {
		res.append(*i);
	}

	return res;
}

Variant c_concurrentvector::t___destruct() {
  INSTANCE_METHOD_INJECTION(concurrentvector, concurrentvector::__destruct);
  return null;
}

// provide readonly access to $GLOBALS from within a thread
// the returned value from this is a copy. The caller can do what it likes with it,
// but the results are invisible to any other thread.
Array f_concurrent_globals() {
	Array res = TbbContext::GetGlobals();

	return res;
}

}

