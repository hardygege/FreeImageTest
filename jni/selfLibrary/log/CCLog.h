/*
 * CCLog.h
 *
 *  Created on: 2016年6月30日
 *      Author: hardy
 */

#ifndef SELFLIBRARY_LOG_CCLOG_H_
#define SELFLIBRARY_LOG_CCLOG_H_

#ifdef _ANDROID_
#include <android/log.h>
#define  LOG_TAG    "CCImgLib"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGT(...)  __android_log_print(ANDROID_LOG_INFO,"alert",__VA_ARGS__)
#define  LOGW(a )  __android_log_write(ANDROID_LOG_WARN,LOG_TAG,a)
#else
#include <stdio.h>
#pragma warning (disable:4127)
#ifdef _DEBUG
#define  LOGI(...) do { printf(__VA_ARGS__);printf("\n"); } while(0)
#define  LOGE(...) do { printf(__VA_ARGS__);printf("\n"); } while(0)
#define  LOGT(...) do { printf(__VA_ARGS__);printf("\n"); } while(0)
#define  LOGW(a )  do { } while(0)
#else
#define  LOGI(...) do { } while(0)
#define  LOGE(...) do { } while(0)
#define  LOGT(...) do { } while(0)
#define  LOGW(a )  do { } while(0)
#endif

#endif

#define	 null 		0



#endif /* SELFLIBRARY_LOG_CCLOG_H_ */
