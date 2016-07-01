package com.example.myfreeimagedemo;

public class NImageProcesser {
	
	static{
		//System.loadLibrary("FreeImage");
		System.loadLibrary("FreeImageTest");
	}
	
	
	public static native int resize(int width, int height, String srcPath, String dstPath, int filter);
	
	public static native int crop(int x1, int y1, int x2, int y2, String srcPath, String dstPath);
	
}
