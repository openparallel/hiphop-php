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
   | TBB - context passed to tbb worker classes and held in local thread  |
   +----------------------------------------------------------------------+
*/

#include "tbb_context.h"
#include <runtime/base/runtime_error.h>
#include <runtime/ext/ext.h>

namespace HPHP {

// Keep a pointer in each threads TLS to an instance of this class
IMPLEMENT_THREAD_LOCAL(TbbContext, TbbContext::localThreadContext);

TbbContext::TbbContext() {
	callerStackTop = 0;
}

TbbContext::~TbbContext() {
}

// Assignment operator
// This copies everything and in particular dereferences the global variables into a copy
TbbContext& TbbContext::operator=(const TbbContext &other) {
	if (this == &other)      // Same object?
	      return *this;

	callerStack = other.callerStack;
	callerStackTop = other.callerStackTop;

	// Dereference global variables
	// Passing references causes thread problems, so we can only access a copy of the globals from worker
	// tasks
	globalVariables = Array();
	for (ArrayIter iter3 = other.globalVariables.begin(); !iter3.end(); iter3.next()) {
	  Variant v = iter3.second();
	  Variant k = iter3.first();

	  //printf("  setting %s:%s\n", k.toString().c_str(), v.toString().c_str());
	  globalVariables.set(k, v);
	}

	return *this;
}

// Called on entry to a parallel_blah function/method
// 'callerName' is the name of the function
// returns a context
/* static */ TbbContext TbbContext::Entry(const char *callerName) {
	if(localThreadContext->callerStackTop==0) {
		// We are in the main HipHop thread (for the "VM")

		// printf("TbbContext::Entry(%s) - new thread\n", callerName);
	}
	else {
		// printf("TbbContext::Entry(%s) - nested thread\n", callerName);
		// We are in a nested thread, e.g. a parallel operation is called from another
	}

	// Push the caller name onto the stack
	if(localThreadContext->callerStack.size() <= localThreadContext->callerStackTop) {
		localThreadContext->callerStack.grow_to_at_least(localThreadContext->callerStackTop+1);
	}
	localThreadContext->callerStack[(localThreadContext->callerStackTop)++] = std::string(callerName);

	// Dereference global variables
	// Only a readonly copy is accessible in worker tasks
	localThreadContext->globalVariables = Array();
    for (ArrayIter iter3 = get_global_array_wrapper().begin(); !iter3.end(); ++iter3) {
      Variant gv = iter3.second();
      Variant gk = iter3.first();

      localThreadContext->globalVariables.set(gk, gv);
    }
	//printf("TbbContext::Entry Set globalVariables to %p\n", localThreadContext->globalVariables);

	return *localThreadContext;
}

// Called on exit from a parallel_blah function/method
void TbbContext::Exit() {
	if(callerStackTop==0) {
		raise_error("TbbContext::Exit - called when all tasks have already exited");	// Internal error should not happen
		return;
	}

	// Else pop
	callerStackTop--;
	if(callerStackTop==0) {
		callerStack.clear();
	}

//	printf("TbbContext::Exit\n");
}

// Called on entry to the operator() in an implementation class
// This means we are potentially in a new thread
void TbbContext::EnteringOperator() const {
	if(localThreadContext->callerStackTop==0) {
		printf("+++TbbContext::EnteringOperator - new task thread\n");

		// Set the thread context from the parent
		*localThreadContext = *this;

	} else {
		printf("TbbContext::EnteringOperator - parent main thread\n");
	}
}

// Called on exit from the operator() in an implementation class
void TbbContext::ExitingOperator() const {
}

// Get a copy of our global variables
// Used from the concurrent_globals PHP extension function
Array TbbContext::GetGlobals() {
	return localThreadContext->globalVariables;
}

}

