//
// Created by Administrator on 2021/11/22.
//

#ifndef LCOPENGLES_LCGLCOMMONDEF_H
#define LCOPENGLES_LCGLCOMMONDEF_H

#include <string>

#include <GLES3/gl3.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include <assert.h>
#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>
#include "LCNDKLogDef.h"

#define MATH_PI 3.1415926535897932384626433832802

template<typename T>
void CCGLSafePtrDelete(T* ptr)
{
    delete ptr;
    ptr = NULL;
}

class CCGlobalDefine
{
    inline static void PrintGLError()
    {
        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
        {
            LOGD("glError: %s",err);
        }
    }

};

#ifdef __cplusplus
extern "C" {
#endif


struct  CCFloat7{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float a;
};

struct  CCFloat3{
    float x;
    float y;
    float z;
};

struct  CCFloat2{
    float u;
    float v;
};

struct  CCFloat4{
    float r;
    float g;
    float b;
    float a;
};

struct  CCFloat5{
    float x;
    float y;
    float z;
    float u;
    float v;
};



#ifdef __cplusplus
}
#endif

#endif //LCOPENGLES_LCGLCOMMONDEF_H
