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

namespace TBB_EXT {
	class temp_class {
	};
}

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

void f_yo(CStrRef data) {
	g_context->out().write((const char *)data, data.length());
}

void f_parallel_for(int start, int length, int blocksize, CVarRef func) {
	Array indices = Array::Create();

	for (int i = start; i < length; i++) {
		indices.append(i);
	}

	Array args;
	args.set(0, indices);

	f_call_user_func_array(func, args);
}


///////////////////////////////////////////////////////////////////////////////
}
