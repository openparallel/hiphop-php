#if EXT_TYPE == 0
"parallel_for", T(Void), S(0), "start", T(Int64), NULL, S(0), "end", T(Int64), NULL, S(0), "func", T(Variant), NULL, S(0), "blocksize", T(Int64), "-1", S(0), NULL, S(0), 
"parallel_for_array", T(Variant), S(0), "arraydata", T(Variant), NULL, S(0), "func", T(Variant), NULL, S(0), "blocksize", T(Int64), "-1", S(0), NULL, S(0), 
"concurrent_globals", T(Array), S(0), NULL, S(0), 
"parallel_reduce", T(Variant), S(0), "data", T(Variant), NULL, S(0), "workerfunction", T(Variant), NULL, S(0), "initialvalue", T(Variant), NULL, S(0), "joinfunction", T(Variant), "null_variant", S(0), NULL, S(0), 
#elif EXT_TYPE == 1
#elif EXT_TYPE == 2
"concurrentvector", "", NULL, "__construct", T(Void), S(0), "arraydata", T(Array), "null_array", S(0), NULL, S(0), S(0), S(0), S(0),"push", T(Void), S(0), "data_item", T(Variant), NULL, S(0), NULL, S(0), S(0), S(0), S(0),"size", T(Int64), S(0), NULL, S(0), S(0), S(0), S(0),"element_at", T(Variant), S(0), "index", T(Int64), NULL, S(0), NULL, S(0), S(0), S(0), S(0),"set_at", T(Void), S(0), "index", T(Int64), NULL, S(0), "data_item", T(Variant), NULL, S(0), NULL, S(0), S(0), S(0), S(0),"as_array", T(Array), S(0), NULL, S(0), S(0), S(0), S(0),"__destruct", T(Variant), S(0), NULL, S(0), S(0), S(0), S(0),NULL,NULL,NULL,
"concurrenthash", "", NULL, "__construct", T(Void), S(0), "arraydata", T(Array), "null_array", S(0), NULL, S(0), S(0), S(0), S(0),"size", T(Int64), S(0), NULL, S(0), S(0), S(0), S(0),"find", T(Variant), S(0), "key", T(Variant), NULL, S(0), NULL, S(0), S(0), S(0), S(0),"erase", T(Void), S(0), "key", T(Variant), NULL, S(0), NULL, S(0), S(0), S(0), S(0),"insert", T(Void), S(0), "key", T(Variant), NULL, S(0), "data_item", T(Variant), NULL, S(0), NULL, S(0), S(0), S(0), S(0),"as_array", T(Array), S(0), NULL, S(0), S(0), S(0), S(0),"__destruct", T(Variant), S(0), NULL, S(0), S(0), S(0), S(0),NULL,NULL,NULL,
#elif EXT_TYPE == 3

#endif
