//
// Created by Administrator on 2021/11/30.
//

#ifndef LCOPENGLES_LCFRAMEBUFFEROBJECT_H
#define LCOPENGLES_LCFRAMEBUFFEROBJECT_H

#include "LCGLCommonDef.h"

class LCFrameBufferObject {

public:
    LCFrameBufferObject();
    ~LCFrameBufferObject();

    void Bind();
    void Release();
    GLuint GetTextureID();

    void CreateWithSize(int width, int height);

private:
    GLuint      m_fboId;
    GLuint      m_renderBufferId;
    GLuint      m_textureId;
};


#endif //LCOPENGLES_LCFRAMEBUFFEROBJECT_H
