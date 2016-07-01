#include <jni.h>
#include <JniImageTest.h>
#include "Source/FreeImage.h"
#include "CCLog.h"

using namespace std;

/** Generic image loader
@param lpszPathName Pointer to the full file name
@param flag Optional load flag constant
@return Returns the loaded dib if successful, returns NULL otherwise
*/
extern "C" FIBITMAP* GenericLoader(const char* lpszPathName, int flag) {
  FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
  // check the file signature and deduce its format
  // (the second argument is currently not used by FreeImage)
  fif = FreeImage_GetFileType(lpszPathName, 0);
  if(fif == FIF_UNKNOWN) {
    // no signature ?
    // try to guess the file format from the file extension
    fif = FreeImage_GetFIFFromFilename(lpszPathName);
  }
  // check that the plugin has reading capabilities ...
  if((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)) {
    // ok, let's load the file
    FIBITMAP *dib = FreeImage_Load(fif, lpszPathName, flag);
    // unless a bad file format, we are done !
    return dib;
  }
  return NULL;
}

extern "C" FREE_IMAGE_FILTER convertFilter(const jint filter){
	FREE_IMAGE_FILTER fiFilter = FILTER_BOX;
	if(filter == 0){
		LOGI(" resize convertFilter FILTER_BOX ");
		fiFilter = FILTER_BOX;
	} else if(filter == 1){
		LOGI(" resize convertFilter FILTER_BICUBIC ");
		fiFilter = FILTER_BICUBIC;
	} else if(filter == 2){
		LOGI(" resize convertFilter FILTER_BILINEAR ");
		fiFilter = FILTER_BILINEAR;
	}else if(filter == 3){
		LOGI(" resize convertFilter FILTER_BSPLINE ");
		fiFilter = FILTER_BSPLINE;
	}else if(filter == 4){
		LOGI(" resize convertFilter FILTER_CATMULLROM ");
		fiFilter = FILTER_CATMULLROM;
	}else if(filter == 5){
		LOGI(" resize convertFilter FILTER_LANCZOS3 ");
		fiFilter = FILTER_LANCZOS3;
	}
	return fiFilter;
}

extern "C" JNIEXPORT jint JNICALL Java_com_example_myfreeimagedemo_NImageProcesser_resize(JNIEnv * env,
		jclass jclazz, jint width, jint height, jstring srcFile, jstring destFile, jint filter) {

	LOGI(" resize w = %d , h = %d , filter = %d ", width, height, filter);

	const char *srcFileString = env->GetStringUTFChars(srcFile, 0);
	const char *destFileString = env->GetStringUTFChars(destFile, 0);

	LOGI(" resize srcFile = %s ", srcFileString);
	LOGI(" resize destFile = %s ", destFileString);

	FreeImage_Initialise(FALSE);

	// load original bitmap from file
	FIBITMAP* srcBitmap = FreeImage_Load(FIF_JPEG, srcFileString, JPEG_DEFAULT);
	jint resultStatus = JNI_OK;
	if (srcBitmap) { //load success
		LOGI(" resize succ 1 ");
		//rescale bitmap
		FREE_IMAGE_FILTER fiFilter = convertFilter(filter);

		FIBITMAP *rescaledBitmap = FreeImage_Rescale(srcBitmap, (int) width,
				(int) height, fiFilter);
		FreeImage_Unload(srcBitmap);

		//save bitmap
		FreeImage_Save(FIF_JPEG, rescaledBitmap, destFileString,
				JPEG_QUALITYSUPERB);
		FreeImage_Unload(rescaledBitmap);
		LOGI(" resize succ 2 ");
		resultStatus = JNI_OK;
		//return JNI_OK;
	} else {
		resultStatus = JNI_ERR;
	}
	env->ReleaseStringUTFChars(srcFile, srcFileString);
	env->ReleaseStringUTFChars(destFile, destFileString);

	FreeImage_DeInitialise();

	LOGE(" resize result = %s ", srcBitmap ? " ok " : "error");
	return resultStatus;
}



extern "C" JNIEXPORT jint JNICALL Java_com_example_myfreeimagedemo_NImageProcesser_crop(JNIEnv *env,
		jclass jclazz, jint x1, jint y1, jint x2, jint y2, jstring srcFile, jstring destFile) {
	FreeImage_Initialise();

	const char *srcFileString = env->GetStringUTFChars(srcFile, 0);
	const char *destFileString = env->GetStringUTFChars(destFile, 0);
	// load original bitmap from file
	FIBITMAP* srcBitmap = FreeImage_Load(FIF_JPEG, srcFileString, JPEG_DEFAULT);

	if (srcBitmap) { //load success

		FIBITMAP *croppedBitmap = FreeImage_Copy(srcBitmap, x1, y1, x2, y2);
		FreeImage_Unload(srcBitmap);

		//save bitmap
		FreeImage_Save(FIF_JPEG, croppedBitmap, destFileString,
				JPEG_QUALITYSUPERB);
		FreeImage_Unload(croppedBitmap);

		env->ReleaseStringUTFChars(srcFile, srcFileString);
		env->ReleaseStringUTFChars(destFile, destFileString);
		//return JNI_OK;
	} else {
		env->ReleaseStringUTFChars(srcFile, srcFileString);
		return JNI_ERR;
	}

	FreeImage_DeInitialise();
	return JNI_OK;
}





