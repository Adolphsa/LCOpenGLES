//
// Created by Administrator on 2021/11/24.
//

#ifndef LCOPENGLES_LCGLTEXTURE_H
#define LCOPENGLES_LCGLTEXTURE_H

#include "LCGLCommonDef.h"
#include "LCNDKLogDef.h"
#include "LCImage.h"

class LCGLTexture {

public:
    LCGLTexture();
    ~LCGLTexture();

    GLuint  GetTextureID();
    GLuint  CreateGLTextureFromFile(AAssetManager *assetManager, const char* fileName);

private:
    GLuint  generateTexture(AAssetManager *assetManager, const char* fileName);
    GLuint  createOpenGLTexture(LCImage* pImg);

private:
    GLuint m_texID;

};


#endif //LCOPENGLES_LCGLTEXTURE_H
