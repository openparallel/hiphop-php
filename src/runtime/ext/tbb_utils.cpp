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

#include <tbb/tbb.h>
#include <runtime/base/hphp.h>

#include "tbb_utils.h"

const int TBB_REQUIRED_THREADS = tbb::task_scheduler_init::automatic;	// work out threads from the machine
// const int TBB_REQUIRED_THREADS = 1;				// No threading

namespace HPHP {

void TbbInitializeIfNeeded(){
	static bool tbbInitDone = false;

	if(!tbbInitDone) {
		tbb::task_scheduler_init init(TBB_REQUIRED_THREADS);

		tbbInitDone = true;
	}

}

Variant DeepCopyVariant(Variant &other) {
	return x_unserialize(x_serialize(other));
}

}
