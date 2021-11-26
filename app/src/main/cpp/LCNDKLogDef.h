//
// Created by Administrator on 2021/11/22.
//

#ifndef LCOPENGLES_LCNDKLOGDEF_H
#define LCOPENGLES_LCNDKLOGDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <android/log.h>

#define LOG "LCNDK-OpenGLES"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__)
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG,__VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG,__VA_ARGS__)

#ifdef __cplusplus
}
#endif


#endif //LCOPENGLES_LCNDKLOGDEF_H
