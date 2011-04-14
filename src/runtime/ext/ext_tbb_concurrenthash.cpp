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


#include <runtime/ext/ext_tbb.h>
#include <tbb/tbb.h>
#include "tbb_context.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

c_concurrenthash::c_concurrenthash() {

}


c_concurrenthash::~c_concurrenthash() {

}

// Construct from an optional array
void c_concurrenthash::t___construct(CArrRef srcarray) {
  INSTANCE_METHOD_INJECTION(concurrenthash, concurrenthash::__construct);
  if(srcarray.isNull()) {
	  return;
	}

	hashData.rehash(srcarray.size());

	// Copy each row
	for (ArrayIter iter3 = srcarray.begin(); !iter3.end(); iter3.next()) {
		  Variant v = iter3.second();
		  Variant k = iter3.first();

		  VarVarHashData::accessor valAcc;
		  hashData.insert(valAcc, k);
		  valAcc->second = v;
		  }
}


// Get the number of items in the hash
int64 c_concurrenthash::t_size() {
  INSTANCE_METHOD_INJECTION(concurrenthash, concurrenthash::size);
  return hashData.size();
}

// Get the element at 'key'
Variant c_concurrenthash::t_find(CVarRef key) {
  INSTANCE_METHOD_INJECTION(concurrenthash, concurrenthash::find);
  VarVarHashData::const_accessor resAcc;
    if(!hashData.find(resAcc, key))
    	return Variant();

    return resAcc->second;
}

// Set the element at 'key' to 'data_item'
void c_concurrenthash::t_insert(CVarRef key, CVarRef data_item) {
  INSTANCE_METHOD_INJECTION(concurrenthash, concurrenthash::insert);
  VarVarHashData::accessor dataAcc;
  hashData.insert(dataAcc, key);
  dataAcc->second = data_item;
}

void c_concurrenthash::t_erase(CVarRef key) {
  INSTANCE_METHOD_INJECTION(concurrenthash, concurrenthash::erase);
  hashData.erase(key);
}

// Return as a PHP array
Array c_concurrenthash::t_as_array() {
  INSTANCE_METHOD_INJECTION(concurrenthash, concurrenthash::as_array);
  Array res;

	for(VarVarHashData::const_iterator i(hashData.begin()); i != hashData.end(); i++) {
//		Variant k = *i;

//		VarVarHashData::const_accessor vAcc;
//		if(hashData.find(vAcc, k)) {
			res.set(i->first, i->second);
//		}
//		else {
//			raise_error("c_concurrenthash::t_as_array key %s has no value\n", k.toString().c_str());
//		}
	}

	return res;
}

Variant c_concurrenthash::t___destruct() {
  INSTANCE_METHOD_INJECTION(concurrenthash, concurrenthash::__destruct);
  return null;
}

}

