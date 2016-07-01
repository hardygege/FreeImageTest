package com.example.myfreeimagedemo;

import java.io.File;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends Activity implements View.OnClickListener {

	/**
	 * FILTER_BOX = 0, // Box, pulse, Fourier window, 1st order (constant)
	 * b-spline FILTER_BICUBIC = 1, // Mitchell & Netravali's two-param cubic
	 * filter FILTER_BILINEAR = 2, // Bilinear filter FILTER_BSPLINE = 3, // 4th
	 * order (cubic) b-spline FILTER_CATMULLROM = 4, // Catmull-Rom spline,
	 * Overhauser spline FILTER_LANCZOS3 = 5 // Lanczos3 filter
	 */

	public static final int FILTER_BOX = 0;
	public static final int FILTER_BICUBIC = 1;
	public static final int FILTER_BILINEAR = 2;
	public static final int FILTER_BSPLINE = 3;
	public static final int FILTER_CATMULLROM = 4;
	public static final int FILTER_LANCZOS3 = 5;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		View test0View = findViewById(R.id.test_btn0);
		View test1View = findViewById(R.id.test_btn1);
		View test2View = findViewById(R.id.test_btn2);
		View test3View = findViewById(R.id.test_btn3);
		View test4View = findViewById(R.id.test_btn4);
		View test5View = findViewById(R.id.test_btn5);
		
		test0View.setOnClickListener(this);
		test1View.setOnClickListener(this);
		test2View.setOnClickListener(this);
		test3View.setOnClickListener(this);
		test4View.setOnClickListener(this);
		test5View.setOnClickListener(this);
	}

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.test_btn0:
			testPic(FILTER_BOX);
			break;
		case R.id.test_btn1:
			testPic(FILTER_BICUBIC);
			break;
		case R.id.test_btn2:
			testPic(FILTER_BILINEAR);
			break;
		case R.id.test_btn3:
			testPic(FILTER_BSPLINE);
			break;
		case R.id.test_btn4:
			testPic(FILTER_CATMULLROM);
			break;
		case R.id.test_btn5:
			testPic(FILTER_LANCZOS3);
			break;
		}
	}

	private void testPic(final int filterType) {
		String srcPath = "/sdcard/aPictest/test_s_czp_source.jpg";
		String dstPath = "/sdcard/aPictest/z_resize_result_"+ filterType +".jpg";
		printLog(" resizeA ================= start file hasexists = "+ new File(srcPath).exists());

		int result = NImageProcesser.resize(960, 1280, srcPath, dstPath, filterType);

		printLog(" resizeA ================= end result = " + result);
	}
	
	private void printLog(String log) {
		Log.d(getClass().getSimpleName(), log);
	}
}
