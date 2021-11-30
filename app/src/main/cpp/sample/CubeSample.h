//
// Created by Administrator on 2021/11/29.
//

#ifndef LCOPENGLES_CUBESAMPLE_H
#define LCOPENGLES_CUBESAMPLE_H

#include "../LCOpenGLShader.h"
#include "../LCGLTexture.h"

/**
 * 立方体
 */
class CubeSample {

public:
    CubeSample();
    ~CubeSample();

    void Init(AAssetManager*  pManager);
    void SetWidthAndHeight(int width, int height);
    void UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float scale, float ratio);
    void Draw();
    void Destroy();

private:
    LCOpenGLShader* m_pOpenGLShader;

    glm::mat4 m_MVPMatrix{};

    int m_width;
    int m_height;
    float m_angle = 0.0f;

    LCGLTexture* m_pGLTexture;
    GLuint m_texID;
};


#endif //LCOPENGLES_CUBESAMPLE_H
