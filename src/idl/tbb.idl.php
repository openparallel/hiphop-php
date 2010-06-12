<?php

include_once 'base.php';

///////////////////////////////////////////////////////////////////////////////

f('yo', null,
  array('data' => String));

f('parallel_for', null,
  array('start' => Int32,
  	'length' => Int32,
	'blocksize' => Int32,
	'func' => Variant));
