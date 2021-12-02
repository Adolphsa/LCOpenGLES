//
// Created by Administrator on 2021/11/30.
//

#ifndef LCOPENGLES_LCOPENGLVAO_H
#define LCOPENGLES_LCOPENGLVAO_H

#include "LCGLCommonDef.h"

class LCOpenGLVAO {

public:
    LCOpenGLVAO();
    ~LCOpenGLVAO();

    void Create();
    void Bind();
    void Release();

private:
    GLuint  m_vaoId;
};


#endif //LCOPENGLES_LCOPENGLVAO_H
