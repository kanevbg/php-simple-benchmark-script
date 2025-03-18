<?php
/**
 * Common php test functions for compression 
 * Php 4.4+
 */

/** ---------------------------------- Tests functions -------------------------------------------- */

function test_36_01_zlib_deflate_compress()
{
	global $stringTest, $emptyResult, $testsLoopLimits, $totalOps, $stringTest;

	if (!function_exists('gzdeflate')) {
		return $emptyResult;
	}

	$count = $testsLoopLimits['36_zlib_compress'];
	$time_start = get_microtime();
	for ($i = 0; $i < $count; $i++) {
		$r = gzdeflate($stringTest, 1);
	}
	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}

function test_36_02_zlib_gzip_compress()
{
	global $stringTest, $emptyResult, $testsLoopLimits, $totalOps, $stringTest;

	if (!function_exists('gzencode')) {
		return $emptyResult;
	}

	$count = $testsLoopLimits['36_gzip_compress'];
	$time_start = get_microtime();
	for ($i = 0; $i < $count; $i++) {
		$r = gzencode($stringTest, 1);
	}
	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}

function test_36_bzip2_compress()
{
	global $stringTest, $emptyResult, $testsLoopLimits, $totalOps, $stringTest;

	if (!function_exists('bzcompress')) {
		return $emptyResult;
	}

	$count = $testsLoopLimits['36_bzip2_compress'];
	$time_start = get_microtime();
	for ($i = 0; $i < $count; $i++) {
		$r = bzcompress($stringTest, 1);
	}
	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}

function test_36_lz4_compress()
{
	global $stringTest, $emptyResult, $testsLoopLimits, $totalOps, $stringTest;

	if (!function_exists('lz4_compress')) {
		return $emptyResult;
	}

	$count = $testsLoopLimits['36_bzip2_compress'];
	$time_start = get_microtime();
	for ($i = 0; $i < $count; $i++) {
		$r = lz4_compress($stringTest);
	}
	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}

function test_36_zstd_compress()
{
	global $stringTest, $emptyResult, $testsLoopLimits, $totalOps, $stringTest;

	if (!function_exists('zstd_compress')) {
		return $emptyResult;
	}

	$count = $testsLoopLimits['36_zstd_compress'];
	$time_start = get_microtime();
	for ($i = 0; $i < $count; $i++) {
		$r = zstd_compress($stringTest, 1);
	}
	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}

function test_36_brotli_compress()
{
	global $stringTest, $emptyResult, $testsLoopLimits, $totalOps, $stringTest;

	if (!function_exists('brotli_compress')) {
		return $emptyResult;
	}

	$count = $testsLoopLimits['36_brotli_compress'];
	$time_start = get_microtime();
	for ($i = 0; $i < $count; $i++) {
		$r = brotli_compress($stringTest, 1);
	}
	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}
