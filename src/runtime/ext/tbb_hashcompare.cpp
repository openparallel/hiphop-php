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

#include "tbb_hashcompare.h"

#include <runtime/base/types.h>
#include <runtime/base/variable_serializer.h>

namespace HPHP {

size_t VarVarHashCompare::hash(const Variant &v) {
	  static VariableSerializer vs(VariableSerializer::Serialize);
	  String str = vs.serialize(v, true);

	  static const size_t FNVOffsetBasis = 2166136261U;
	  static const size_t FNVPrime = 16777619;

	  const char * s = str.c_str();
	  const char *sp=s;
	  size_t hash = FNVOffsetBasis;
	  while(*sp) {
	        hash = hash ^ *sp++;       /* xor  the low 8 bits */
#if defined(NO_FNV_GCC_OPTIMIZATION)
	        hash *= FNVPrime;
#else
	        hash += (hash<<1) + (hash<<4) + (hash<<7) + (hash<<8) + (hash<<24);
#endif
	    }
	  return hash;

}

bool VarVarHashCompare::equal(const Variant &a, const Variant &b) {
	return a.equal(b);
}


}
