//
// Created by Administrator on 2021/11/30.
//

#ifndef LCOPENGLES_CUBEIMAGESAMPLE_H
#define LCOPENGLES_CUBEIMAGESAMPLE_H

#include "../LCOpenGLShader.h"
#include "../LCGLTexture.h"

/**
 * 立方体贴图
 */
class CubeImageSample {

public:
    CubeImageSample();
    ~CubeImageSample();

    void Init(AAssetManager*  pManager);
    void SetWidthAndHeight(int width, int height);
    void UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float scale, float ratio);
    void Draw();
    void Destroy();

private:

    LCOpenGLShader* m_pOpenGLShader;
    LCGLTexture* m_pGLTexture;
    GLuint m_texID[6];

    glm::mat4 m_MVPMatrix{};
    int m_width;
    int m_height;
    float m_angle;
};


#endif //LCOPENGLES_CUBEIMAGESAMPLE_H
