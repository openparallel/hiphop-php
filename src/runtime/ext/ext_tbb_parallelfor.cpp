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
#include <vector>
#include <memory>

#include <runtime/ext/ext_tbb.h>
#include <tbb/tbb.h>

#include "tbb_context.h"
#include "tbb_utils.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


// Class to hold parameters passed into a parallel_for call.
class PforTaskParameters {
		friend void f_parallel_for(int64 start, int64 end, CVarRef func, int64 blocksize);
		friend Variant f_parallel_for_array(CVarRef arraydata, CVarRef func, int64 blocksize);

        private:
                CVarRef callback;										// PHP callback function
                std::vector<Variant> inputArrayOfVariant;				// Input array to process
                std::vector<Variant> *pOutputArrayOfVariant;			// Output array to generate - will be allocated once and copied around as a pointer
                TbbContext callerContext;								// Context of the caller, used to access globals

        public:
                // The default operator called from parallel_for
                void operator() (const tbb::blocked_range<int64> &range) const {
                		callerContext.EnteringOperator();

                        // Build arguments array
                        Array args = Array::Create();

                        // Pass the range start and end as parameters
                        args.append(range.begin());
                        args.append(range.end());

                        // If an input array is defined, copy it and pass as a parameter
                        if(inputArrayOfVariant.size() > 0) {
                        	Array inputPHPArray = Array::Create();
                        	for(size_t ai=0; ai<inputArrayOfVariant.size(); ai++)
                        		inputPHPArray.append(inputArrayOfVariant[ai]);

                        	Variant inputArrayArg(inputPHPArray.getArrayData());
                        	args.append(inputArrayArg);
                        }

                        // Call user supplied callback with arguments
                        // This is a PHP function of the form worker($begin, $end, $array), returning an array or nothing
                        // If an array is returned, it is expected to have elements which will be comingled into the output
                        // array in the elements defined by the input range.
                        Variant vres = f_call_user_func_array(this->callback, args);

                		callerContext.ExitingOperator();		// Call this straight after the callback completes

                		// Return if no result to pass back
                        if(vres.isNull() || !vres.isArray())
                        	return;

                        // Now we take the output array [0..N) and assign it into the overall output array at [begin..begin+N)

                        // Extract output array from result variant
                    	const Array aOutputArray = vres.asCArrRef();
                    	ArrayData *pdOutputArray = aOutputArray.getArrayData();

                    	Variant v = pdOutputArray->reset();

                    	// Check the output array is the same size or smaller than the range passed
                    	size_t outIdx = range.begin();
                    	if(pdOutputArray->size() > (range.end()-range.begin())) {
                    		raise_warning("Callback function returned array larger than passed range size");
                    		return;
                    	}

                    	// Copy each row
                    	while(!v.isBoolean() || v.toBoolean())
                    	{
                        	// printf(" outIdx=%d, v=%s\n", (int)outIdx, v.toString().c_str());
                        	( *pOutputArrayOfVariant ) [outIdx++] = v;

                        	v = pdOutputArray->next();
                    	}

                }

                // Construct with context and worker function - used for the parallel_for form.
                PforTaskParameters(TbbContext context, CVarRef func, std::vector<Variant> *pOutArray) : callback(func), callerContext(context) {
                	pOutputArrayOfVariant = pOutArray;
                }

                // Construct with context, worker function and array data - used for the parallel_for_array form
                PforTaskParameters(TbbContext context, ArrayData *inputArrayData, CVarRef func, std::vector<Variant> *pOutArray) : callback(func), callerContext(context) {
                	pOutputArrayOfVariant = pOutArray;

                	Variant v = inputArrayData->reset();

                	while(!v.isBoolean() || v.toBoolean())
                	{
                    	// printf(" v=%s\n", v.toString().c_str());
                    	inputArrayOfVariant.push_back(Variant(v));	// copy

                    	v = inputArrayData->next();
                	}
                }

};

//void f_yo(CStrRef data) {
//	g_context->out().write((const char *)data, data.length());
//}

// f_parallel_for
//  arraydata - input array to process
//  func - worker function of the form worker($begin, $end)
//  blocksize - optional blocksize, refer to TBB documentation
//
// Call 'func' for non-overlapping ranges which cover the range [begin,end)
// This will use threads as appropriate for the machine.
// Note that globals are only accessible as a copy within 'func', so this version is only
// useful to generate external outputs.
void f_parallel_for(int64 begin, int64 end, CVarRef func, int64 blocksize /* = -1 */) {
        TbbInitializeIfNeeded();

        TbbContext myContext  = TbbContext::Entry("parallel_for");

        std::vector<Variant> outArray;
        outArray.resize(end-begin);

        if (blocksize == -1) {
                // Use auto_partitioner for block size
                tbb::parallel_for(tbb::blocked_range<int64>(begin, end), PforTaskParameters(myContext, func, &outArray), tbb::auto_partitioner());
        } else {
                // Use manually set block size
                tbb::parallel_for(tbb::blocked_range<int64>(begin, end, blocksize), PforTaskParameters(myContext, func, &outArray));
        }

        myContext.Exit();
}



// f_parallel_for
//  begin - start of range to process
//	end - 1 after end of range to process
//  func - worker function of the form worker($begin, $end, $inputdata) - returns an array of max length ($end-$begin)
//  blocksize - optional blocksize, refer to TBB documentation
// Returns: array of maximum length ($end-$begin)
//
// Call 'func' for non-overlapping array segments to cover all of arraydata
// This will use threads as appropriate for the machine.
// If a result is returned by 'func' it will be placed into the result array elements corresponding to the input elements
Variant f_parallel_for_array(CVarRef arraydata, CVarRef func, int64 blocksize /* = -1 */) {
	if(!arraydata.isArray())
	{
		raise_error("parallel_for_array expected an array in first argument");
		return Variant();
	}

	// Get the input array
	const Array aArray = arraydata.asCArrRef();
	ArrayData *pdArray = aArray.getArrayData();

	size_t asize = pdArray->size();
	if(asize==0)
		return Variant();

    TbbContext myContext  = TbbContext::Entry("parallel_for_array");

    std::vector<Variant> outArray;
    outArray.resize(asize);

    // Construct task parameters
	PforTaskParameters tclass = PforTaskParameters(myContext, pdArray, func, &outArray);

    TbbInitializeIfNeeded();

    if (blocksize == -1) {
            // Use auto_partitioner for block size
            tbb::parallel_for(tbb::blocked_range<int64>(0, asize), tclass, tbb::auto_partitioner());
    } else {
            // Use manually set block size
            tbb::parallel_for(tbb::blocked_range<int64>(0, asize, blocksize), tclass);
    }

    myContext.Exit();


    // Create the result array
	Array resPHPArray = Array::Create();
	for(size_t ai=0; ai<outArray.size(); ai++) {
		Variant amem = outArray[ai];
		// printf(" ai=%d, append %s\n", (int)ai, amem.toString().c_str());
		if(!amem.isNull())
			resPHPArray.append(amem);
	}

	if(resPHPArray.size()==0)
		return Variant();		// i.e null

	return resPHPArray.getArrayData();
}


///////////////////////////////////////////////////////////////////////////////
}
