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

#include "tbb_utils.h"
#include "tbb_context.h"
#include <runtime/base/runtime_error.h>
#include <runtime/ext/ext.h>

namespace HPHP {

// Keep a pointer in each threads TLS to an instance of this class
IMPLEMENT_THREAD_LOCAL(TbbContext, TbbContext::localThreadContext);

TbbContext::TbbContext() {
	callDepth = 0;
}

TbbContext::~TbbContext() {
}

// Assignment operator
// This copies everything and in particular dereferences the global variables into a copy
TbbContext& TbbContext::operator=(const TbbContext &other) {
	if (this == &other)      // Same object?
	      return *this;

	callDepth = other.callDepth;
	globalVariables.clear();

	// Dereference global variables
	// Passing references causes thread problems, so we can only access a copy of the globals from worker
	// tasks
	globalVariables = Array();
	for (ArrayIter iter3 = other.globalVariables.begin(); !iter3.end(); iter3.next()) {
	  Variant v = iter3.second();
	  Variant k = iter3.first();

	  //printf("  setting %s:%s\n", k.toString().c_str(), v.toString().c_str());
	  globalVariables.set(DeepCopyVariant(k), DeepCopyVariant(v));
	}

	return *this;
}

// Called on entry to a parallel_blah function/method
// 'callerName' is the name of the function
// returns a context
/* static */ TbbContext TbbContext::Entry(const char *callerName) {
	if(localThreadContext->callDepth==0) {
		// We are in the main HipHop thread (for the "VM")

		//printf("TbbContext::Entry(%s) - new thread\n", callerName);
	}
	else {
		//printf("TbbContext::Entry(%s) - nested thread\n", callerName);
		// We are in a nested thread, e.g. a parallel operation is called from another
	}

	(localThreadContext->callDepth)++;

	// Dereference global variables
	// Only a readonly copy is accessible in worker tasks
	localThreadContext->globalVariables.clear();

	localThreadContext->globalVariables = Array();
    for (ArrayIter iter3 = get_global_array_wrapper().begin(); !iter3.end(); ++iter3) {
      Variant gv = iter3.second();
      Variant gk = iter3.first();

      localThreadContext->globalVariables.set(gk, gv);
    }

	return *localThreadContext;
}

// Called on exit from a parallel_blah function/method
void TbbContext::Exit() {
	if(callDepth==0) {
		raise_error("TbbContext::Exit - called when all tasks have already exited");	// Internal error should not happen
		return;
	}

	// Else pop
	callDepth--;

	// printf("TbbContext::Exit\n");
}

// Called on entry to the operator() in an implementation class
// This means we are potentially in a new thread
void TbbContext::EnteringOperator() const {
	if(localThreadContext->callDepth==0) {
		//printf("+++TbbContext::EnteringOperator - new task thread\n");

		// Set the thread context from the parent
		*localThreadContext = *this;

	} else {
		 //printf("TbbContext::EnteringOperator - parent main thread\n");
	}
}

// Called on exit from the operator() in an implementation class
void TbbContext::ExitingOperator() const {
	//printf("TbbContext::ExitingOperator\n");

	// Clear the stack status so when we get reused, we reinitialize
	localThreadContext->callDepth = 0;
}

// Get a copy of our global variables
// Used from the concurrent_globals PHP extension function
Array TbbContext::GetGlobals() {
//	if(localThreadContext->callerStack.size()==0) {
	if(localThreadContext->callDepth==0) {
		// We are on the main thread and have direct access to globals
		return get_global_array_wrapper();
	}
	else {
		// We are on a worker thread and get a read-only copy of globals
		return localThreadContext->globalVariables;
	}
}

}

