//
// Created by Administrator on 2021/11/24.
//

#ifndef LCOPENGLES_LOADIMAGESAMPLE_H
#define LCOPENGLES_LOADIMAGESAMPLE_H

#include "../LCOpenGLShader.h"
#include "../LCGLTexture.h"

class LoadImageSample {
public:
    LoadImageSample();
    ~LoadImageSample();

    void Init(AAssetManager*  pManager);
    void Draw();
    void Destroy();

private:
    LCOpenGLShader* m_pOpenGLShader;

    LCGLTexture* m_pGLTexture1;
    GLuint m_texID1;

    LCGLTexture* m_pGLTexture2;
    GLuint m_texID2;
};


#endif //LCOPENGLES_LOADIMAGESAMPLE_H
