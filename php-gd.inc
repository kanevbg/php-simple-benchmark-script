<?php
/**
 * Tests for GD
 */

function test_34_gd_qrcode()
{
	global $testsLoopLimits, $totalOps, $qr;

	$size = 25; // Dimension in dots
	$dot = 9; // Pixels per dot

	$count = $testsLoopLimits['34_gd_qrcode'];
	$time_start = get_microtime();

	for ($c=0; $c<$count; $c++) {

	$img = imagecreatetruecolor($size * $dot, $size * $dot);

	// Enable alpha blending
	imagealphablending($img, true);
	imagesavealpha($img, true);

	// Allocate colors
	$back = imagecolorallocatealpha($img, 0, 0, 0, 127);
	$dots = imagecolorallocatealpha($img, 0, 64, 127, 64);

	// Fill the image with background/transparency
	imagefill($img, 0, 0, $back);

	// Loop over all dots and draw them:
	for ($y = 0, $i = 0; $y < $size; $y++) {
		for ($x = 0; $x < $size; $x++, $i++) {
			if ($qr[$i] == '1') { // Draw a dot?
				// Draw rectangles
				imagefilledrectangle($img, $x * $dot, $y * $dot, ($x + 1) * $dot - 1, ($y + 1) * $dot - 1, $dots);
			}
		}
	}

	// Save the result
//	imagejpeg($img, "test-gd.jpg", 75);
	imagejpeg($img, "/dev/null", 75);

	imagedestroy($img);

//	echo $i . '.';

	}

	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}
