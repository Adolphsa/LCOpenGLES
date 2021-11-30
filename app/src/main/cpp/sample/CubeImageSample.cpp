//
// Created by Administrator on 2021/11/30.
//

#include "CubeImageSample.h"

CubeImageSample::CubeImageSample()
{
    m_pOpenGLShader = new LCOpenGLShader();
    m_pGLTexture = new LCGLTexture();

    m_width = 0;
    m_height = 0;
    m_angle = 0.0f;
}

CubeImageSample::~CubeImageSample()
{
    CCGLSafePtrDelete(m_pOpenGLShader);
    CCGLSafePtrDelete(m_pGLTexture);
}

void CubeImageSample::Init(AAssetManager*  pManager)
{
    m_pOpenGLShader->InitShadersFromFile(pManager, "cube_image_v.glsl", "cube_image_f.glsl");

    m_texID[0] = m_pGLTexture->CreateGLTextureFromFile(pManager, "1.png");
    m_texID[1] = m_pGLTexture->CreateGLTextureFromFile(pManager, "2.png");
    m_texID[2] = m_pGLTexture->CreateGLTextureFromFile(pManager, "3.png");
    m_texID[3] = m_pGLTexture->CreateGLTextureFromFile(pManager, "4.png");
    m_texID[4] = m_pGLTexture->CreateGLTextureFromFile(pManager, "5.png");
    m_texID[5] = m_pGLTexture->CreateGLTextureFromFile(pManager, "6.png");

}

void CubeImageSample::SetWidthAndHeight(int width, int height)
{
    m_width = width;
    m_height = height;
}

void CubeImageSample::UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float scale, float ratio)
{
    angleX = angleX % 360;
    angleY = angleY % 360;

    //转化为弧度角
    float radiansX = static_cast<float>(MATH_PI / 180.0f * angleX);
    float radiansY = static_cast<float>(MATH_PI / 180.0f * angleY);

    // Projection matrix
    //glm::mat4 Projection = glm::ortho(-ratio, ratio, -1.0f, 1.0f, 0.0f, 100.0f);
    //glm::mat4 Projection = glm::frustum(-ratio, ratio, -1.0f, 1.0f, 4.0f, 100.0f);
    glm::mat4 Projection = glm::perspective(45.0f, ratio, 0.1f, 100.f);

    // View matrix
    glm::mat4 View = glm::lookAt(
            glm::vec3(0, 0, 2.0), // Camera is at (0,0,1), in World Space
            glm::vec3(0, 0, 0), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    // Model matrix
    glm::mat4 Model = glm::mat4(1.0f);
    Model = glm::scale(Model, glm::vec3(scale, scale, scale));
    Model = glm::rotate(Model, radiansX, glm::vec3(1.0f, 1.0f, 1.0f));
//    Model = glm::rotate(Model, radiansY, glm::vec3(0.0f, 1.0f, 0.0f));
    Model = glm::translate(Model, glm::vec3(0.3f, 0.3f, -0.3f));

    mvpMatrix = Projection * View * Model;
}

void CubeImageSample::Draw()
{
    CCFloat5  cubeImageVertex[] = {
            { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f},
            { 0.5f, -0.5f, -0.5f,  1.0f, 0.0f},
            { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
            { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
            {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f},
            {-0.5f, -0.5f, -0.5f,  0.0f, 0.0f},

            {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
            {0.5f, -0.5f,  0.5f,  1.0f, 0.0f},
            {0.5f,  0.5f,  0.5f,  1.0f, 1.0f},
            {0.5f,  0.5f,  0.5f,  1.0f, 1.0f},
            {-0.5f,  0.5f,  0.5f,  0.0f, 1.0f},
            {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},

            {-0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
            {-0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
            {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
            {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
            {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
            {-0.5f,  0.5f,  0.5f,  1.0f, 0.0f},

            {0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
            {0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
            {0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
            {0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
            {0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
            {0.5f,  0.5f,  0.5f,  1.0f, 0.0f},

            {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
            {0.5f, -0.5f, -0.5f,  1.0f, 1.0f},
            {0.5f, -0.5f,  0.5f,  1.0f, 0.0f},
            {0.5f, -0.5f,  0.5f,  1.0f, 0.0f},
            {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
            {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},

            {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f},
            {0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
            {0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
            {0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
            {-0.5f,  0.5f,  0.5f,  0.0f, 0.0f},
            {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f}
    };


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    m_pOpenGLShader->Bind();

    m_pOpenGLShader->SetAttributeBuffer(0, GL_FLOAT, cubeImageVertex, 3, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(0);

    m_pOpenGLShader->SetAttributeBuffer(1, GL_FLOAT, &cubeImageVertex[0].u, 2, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(1);

//    m_angle += 0.05f;
//    LOGD("Pain Cube Image %f", m_angle);
//    glm::mat4x4  objectMat;
//    glm::mat4x4  objectTransMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3));
//    glm::mat4x4  objectRotMat = glm::rotate(glm::mat4(1.0f),m_angle,glm::vec3(1.0f, 1.0f, 1.0) );
//    glm::mat4x4  objectScaleMat = glm::scale(glm::mat4(1.0f),glm::vec3(1.0f, 1.0f, 1.0) );
//    objectMat = objectTransMat * objectRotMat * objectScaleMat;
//
//    glm::mat4 projMat = glm::perspective(glm::radians(60.0f), (float)m_width/(float)m_height, 0.1f, 1000.0f);
//    objectMat = projMat* objectMat ;

    m_angle += 3.0f;
//    LOGD("m_angle = %f", m_angle);
    float ratio = (float)m_width / (float)m_height;
    UpdateMVPMatrix(m_MVPMatrix, m_angle, m_angle, 0.5f, ratio);
    m_pOpenGLShader->SetUniformValue("u_mat", m_MVPMatrix);

    for (int i = 0; i < 6; ++i) {
        m_pOpenGLShader->SetUniformValue("texture", i);
        glBindTexture(GL_TEXTURE_2D, m_texID[i]);
        glDrawArrays(GL_TRIANGLES,i*6,6);
    }
//    glDrawArrays(GL_TRIANGLES, 0, 36);

    m_pOpenGLShader->Release();
}

void CubeImageSample::Destroy()
{

}
