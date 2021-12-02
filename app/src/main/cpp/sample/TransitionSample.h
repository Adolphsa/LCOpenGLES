//
// Created by Administrator on 2021/12/1.
//

#ifndef LCOPENGLES_TRANSITIONSAMPLE_H
#define LCOPENGLES_TRANSITIONSAMPLE_H

#include "../LCOpenGLShader.h"
#include "../LCGLTexture.h"
#include "../LCOpenGLVAO.h"
#include "../LCOpenGLBuffer.h"

/**
 * 两张图片  从左下到右上
 */
class TransitionSample {

public:
    TransitionSample();
    ~TransitionSample();

    void Init(AAssetManager*  pManager);
    void Draw();
    void Destroy();

private:
    void loadTextureResources(AAssetManager *pManager);
    void loadShaderResources(AAssetManager *pManager);

    void setupRenderScreenSize();
    void setupFrameBufferObject();

    void setupRenderingObject();
    void renderObject();

private:
    float m_nValue = 0.0f;
    float m_angle  = 0.0f;
    GLuint m_texId[6];

    glm::vec2            m_nResolution;

    LCOpenGLShader* m_pOpenGLShader;
    LCOpenGLVAO*          m_pVAO;
    LCOpenGLBuffer*       m_pVBO;
    LCOpenGLBuffer*       m_pEBO;

};


#endif //LCOPENGLES_TRANSITIONSAMPLE_H
