//
// Created by Administrator on 2021/12/2.
//

#ifndef LCOPENGLES_TRANSITIONL2RSAMPLE_H
#define LCOPENGLES_TRANSITIONL2RSAMPLE_H

#include "../LCOpenGLShader.h"
#include "../LCGLTexture.h"
#include "../LCOpenGLVAO.h"
#include "../LCOpenGLBuffer.h"

/**
 * 从左滑到右
 */
class TransitionL2RSample {

public:
    TransitionL2RSample();
    ~TransitionL2RSample();

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
    GLuint m_texId[6];

    glm::vec2            m_nResolution;

    LCOpenGLShader* m_pOpenGLShader;
    LCOpenGLVAO*          m_pVAO;
    LCOpenGLBuffer*       m_pVBO;
    LCOpenGLBuffer*       m_pEBO;

};


#endif //LCOPENGLES_TRANSITIONL2RSAMPLE_H
