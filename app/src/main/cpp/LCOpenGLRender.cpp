//
// Created by Administrator on 2021/11/22.
//

#include "com_lc_les_LCGLRender.h"
#include "LCNDKLogDef.h"

#include "LCOpenGLShader.h"
#include "sample/TriangleSample.h"
#include "sample/RectangleSample.h"
#include "sample/LoadImageSample.h"

#include <GLES3/gl3.h>


LCOpenGLShader m_ndkOpenGLShader;
//TriangleSample m_triangleSample;
//RectangleSample m_rectangleSample;
LoadImageSample m_LoadImageSample;

#ifdef __cplusplus
extern "C" {
#endif

void Java_com_lc_les_LCGLRender_ndkInit(JNIEnv *env, jobject obj, jobject assetManager)
{
    AAssetManager *astManager = AAssetManager_fromJava (env, assetManager);

    LOGD("ndkInit");
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClearDepthf(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    m_LoadImageSample.Init(astManager);
}


void Java_com_lc_les_LCGLRender_ndkPaintGL(JNIEnv *env, jobject obj)
{
    m_LoadImageSample.Draw();
}


void Java_com_lc_les_LCGLRender_ndkResizeGL(JNIEnv *env, jobject obj, jint width, jint height)
{
    LOGD("ndkResizeGL");
    glViewport(0, 0, width, height);

}

#ifdef __cplusplus
}
#endif
