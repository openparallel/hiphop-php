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

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

class temp_tbb_class {
        public:
                CVarRef callback;

                void operator() (const tbb::blocked_range<int> &range) const {
                        // Build indices array from blocked_range
                        Array indices = Array::Create();

                        for (int i = range.begin(); i < range.end(); i++) {
                                indices.append(i);
                        }

                        // Build arguments array
                        Array args = Array::Create();
                        args.append(indices);

                        // Call user supplied callback with arguments
                        f_call_user_func_array(this->callback, args);
                }

                temp_tbb_class(CVarRef func) : callback(func) {
                        // ctor
                }
};

void f_yo(CStrRef data) {
	g_context->out().write((const char *)data, data.length());
}

void f_parallel_for(int start, int length, CVarRef func, int blocksize /* = -1 */) {
        // Magic. Probably need to initialize TBB somewhere though

        if (blocksize == -1) {
                // Use auto_partitioner for block size
                tbb::parallel_for(tbb::blocked_range<int>(start, length), temp_tbb_class(func), tbb::auto_partitioner());
        } else {
                // Use manually set block size
                tbb::parallel_for(tbb::blocked_range<int>(start, length, blocksize), temp_tbb_class(func));
        }
}


///////////////////////////////////////////////////////////////////////////////
}
