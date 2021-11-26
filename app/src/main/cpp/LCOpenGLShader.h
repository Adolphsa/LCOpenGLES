//
// Created by Administrator on 2021/11/22.
//

#ifndef LCOPENGLES_LCOPENGLSHADER_H
#define LCOPENGLES_LCOPENGLSHADER_H

#include "LCGLCommonDef.h"

class LCOpenGLShader {

public:
    LCOpenGLShader();
    ~LCOpenGLShader();

    void Bind();
    void Release();

    void InitShadersFromFile(AAssetManager*  pManager, const char* vPath,const char* fPath);

    void DisableAttributeArray(int location);
    void EnableAttributeArray(int location);
    void SetAttributeBuffer(int location,GLenum type, const void *values, int tupleSize, int stride = 0);

    void SetUniformValue(const char* name, int iValue);
    void SetUniformValue(const char* name, GLfloat fValue);
    void SetUniformValue(const char* name, glm::vec2 vecValue);
    void SetUniformValue(const char* name, glm::vec3 vecValue);
    void SetUniformValue(const char* name, glm::mat4 matValue);

private:
    int compileShader(AAssetManager*  m_pAssetManager, const char* sPath, GLint sType);

private:
    GLuint m_shaderProgram;

};


#endif //LCOPENGLES_LCOPENGLSHADER_H
