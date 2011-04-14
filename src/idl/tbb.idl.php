#include <tbb/tbb.h>
#include "tbb_hashcompare.h"

<?php

include_once 'base.php';

///////////////////////////////////////////////////////////////////////////////

// f('yo', null,
//  array('data' => String));

f('parallel_for', null,
  array('start' => Int64,
  	'end' => Int64,
        'func' => Variant,
        'blocksize' => array(Int64, '-1'), // Optional
));

f('parallel_for_array', Variant,
  array('arraydata' => Variant,
        'func' => Variant,
        'blocksize' => array(Int64, '-1'), // Optional
));

c('ConcurrentVector', null, array(),
  array(
    m(PublicMethod, '__construct', null,
      array('arraydata' => array(VariantMap, "null_array"))),
    m(PublicMethod, 'push', null,
      array('data_item' => Variant)),
    m(PublicMethod, 'size', Int64),
    m(PublicMethod, 'element_at', Variant,
     array('index' => Int64)),
    m(PublicMethod, 'set_at', null,
     array('index' => Int64,
     	'data_item' => Variant)),
    m(PublicMethod, 'as_array', VariantMap)),
    
  "\nprivate: \n" .
  "  tbb::concurrent_vector<Variant> vectorData;\n"
);

c('ConcurrentHash', null, array(),
  array(
    m(PublicMethod, '__construct', null,
      array('arraydata' => array(VariantMap, "null_array"))),
    m(PublicMethod, 'size', Int64),
    m(PublicMethod, 'find', Variant,
     array('key' => Variant)),
    m(PublicMethod, 'erase', null,
     array('key' => Variant)),
    m(PublicMethod, 'insert', null,
     array('key' => Variant,
     	'data_item' => Variant)),
    m(PublicMethod, 'as_array', VariantMap)),
      "\nprivate: \n" .
  "  VarVarHashData hashData;\n"
);

f('concurrent_globals', VariantMap);

f('parallel_reduce', Variant,
  array('data' => Variant,
  	'workerfunction' => Variant,
  	'initialvalue' => Variant,
  	'joinfunction' => array(Variant, 'null_variant'),
  	));
  	
