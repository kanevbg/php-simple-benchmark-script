<?php
/**
 * Tests for Imagick
 */

function test_35_imagick_qrcode()
{
	global $testsLoopLimits, $totalOps, $qr;

	$size = 25; // Dimension in dots
	$dot = 9; // Pixels per dot
	$imgW = $imgH = $size;

	$count = $testsLoopLimits['35_imagick_qrcode'];
	$time_start = get_microtime();

	$pixelPerPoint = 9;
	$outerFrame = 1;
	$q = 75;

	$col[0] = new ImagickPixel("white");
	$col[1] = new ImagickPixel("black");

	for ($c=0; $c<$count; $c++) {

		$image = new Imagick();
		$image->newImage($imgW, $imgH, $col[0]);

		$image->setCompressionQuality($q);
		$image->setImageFormat('jpeg');

		$draw = new ImagickDraw();
		$draw->setFillColor($col[1]);

		// Loop over all dots and draw them:
		for ($y = 0, $i = 0; $y < $size; $y++) {
			for ($x = 0; $x < $size; $x++, $i++) {
				if ($qr[$i] == '1') { // Draw a dot?
					$draw->point($x,$y);
				}
			}
		}

		$image->drawImage($draw);
		$image->borderImage($col[0],$outerFrame,$outerFrame);
		$image->scaleImage( $imgW * $pixelPerPoint, 0 );

		// Save the result
//		$image->writeImages("test-im.jpg",true);
		$image->writeImages("/dev/null",true);
	}

	$totalOps += $count;
	return format_result_test(get_microtime() - $time_start, $count, mymemory_usage());
}
