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


#ifndef TBB_CONTEXT_H_
#define TBB_CONTEXT_H_

#include <string>
#include <tbb/tbb.h>
#include <util/thread_local.h>
#include <runtime/base/complex_types.h>

namespace HPHP {


class TbbContext {
public:
	TbbContext();

	virtual ~TbbContext();

	// Assignment operator
	TbbContext& operator=(const TbbContext &other);

	// Called on entry to a parallel_blah function/method
	// 'callerName' is the name of the function
	// returns a context
	static TbbContext Entry(const char *callerName);

	// Called on exit from a parallel_blah function/method
	void Exit();

	// Called on entry to the operator() in an implementation class
	// This means we are potentially in a new thread
	void EnteringOperator() const;

	// Called on exit from the operator() in an implementation class
	void ExitingOperator() const;

	static Array GetGlobals();

private:
	// Keep a context for each worker task (=== thread here)
	static DECLARE_THREAD_LOCAL(TbbContext, localThreadContext);

	size_t callDepth;

	// Get a copy of our global variables
	// Used from the concurrent_globals PHP extension function
	Array globalVariables;										// A copy of the global variables at main thread level
};

}


#endif /* TBB_CONTEXT_H_ */
