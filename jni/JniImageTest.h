/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_myfreeimagedemo_NImageProcesser */

#ifndef _Included_com_example_myfreeimagedemo_NImageProcesser
#define _Included_com_example_myfreeimagedemo_NImageProcesser
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_myfreeimagedemo_NImageProcesser
 * Method:    resize
 * Signature: (IILjava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_example_myfreeimagedemo_NImageProcesser_resize
  (JNIEnv *, jclass, jint, jint, jstring, jstring, jint);

/*
 * Class:     com_example_myfreeimagedemo_NImageProcesser
 * Method:    crop
 * Signature: (IIIILjava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_example_myfreeimagedemo_NImageProcesser_crop
  (JNIEnv *, jclass, jint, jint, jint, jint, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif