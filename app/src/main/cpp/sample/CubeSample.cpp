//
// Created by Administrator on 2021/11/29.
//

#include "CubeSample.h"

CubeSample::CubeSample() {
    m_pOpenGLShader = new LCOpenGLShader();
    m_width = 0;
    m_height = 0;
}

CubeSample::~CubeSample() {
    CCGLSafePtrDelete(m_pOpenGLShader);
}

void CubeSample::Init(AAssetManager *pManager) {

    m_pOpenGLShader->InitShadersFromFile(pManager, "cube_v.glsl", "cube_f.glsl");

}

void CubeSample::SetWidthAndHeight(int width, int height) {
    m_width = width;
    m_height = height;
}

void CubeSample::Draw() {

    CCFloat7 cubeVertexs[] = {
            {-0.5f, -0.5f, -0.5f, 1.0f,  0.0f, 0.0f, 1.0f},
            {0.5f,  -0.5f, -0.5f, 1.0f,  0.0f, 0.0f, 1.0f},
            {0.5f,  0.5f,  -0.5f, 1.0f,  0.0f, 0.0f, 1.0f},
            {0.5f,  0.5f,  -0.5f, 1.0f,  0.0f, 0.0f, 1.0f},
            {-0.5f, 0.5f,  -0.5f, 1.0f,  0.0f, 0.0f, 1.0f},
            {-0.5f, -0.5f, -0.5f, 1.0f,  0.0f, 0.0f, 1.0f},

            {-0.5f, -0.5f, 0.5f,  0.0f,  1.0f, 0.0f, 1.0f},
            {0.5f,  -0.5f, 0.5f,  0.0f,  1.0f, 0.0f, 1.0f},
            {0.5f,  0.5f,  0.5f,  0.0f,  1.0f, 0.0f, 1.0f},
            {0.5f,  0.5f,  0.5f,  0.0f,  1.0f, 0.0f, 1.0f},
            {-0.5f, 0.5f,  0.5f,  0.0f,  1.0f, 0.0f, 1.0f},
            {-0.5f, -0.5f, 0.5f,  0.0f,  1.0f, 0.0f, 1.0f},

            {-0.5f, 0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f},
            {-0.5f, 0.5f,  -0.5f, 0.0f,  0.0f, 1.0f, 1.0f},
            {-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 1.0f},
            {-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 1.0f},
            {-0.5f, -0.5f, 0.5f,  0.0f,  0.0f, 1.0f, 1.0f},
            {-0.5f, 0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f},

            {0.5f,  0.5f,  0.5f,  1.0f,  0.0f, 1.0f, 1.0f},
            {0.5f,  0.5f,  -0.5f, 1.0f,  0.0f, 1.0f, 1.0f},
            {0.5f,  -0.5f, -0.5f, 1.0f,  0.0f, 1.0f, 1.0f},
            {0.5f,  -0.5f, -0.5f, 1.0f,  0.0f, 1.0f, 1.0f},
            {0.5f,  -0.5f, 0.5f,  1.0f,  0.0f, 1.0f, 1.0f},
            {0.5f,  0.5f,  0.5f,  1.0f,  0.0f, 1.0f, 1.0f},

            {-0.5f, -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f},
            {0.5f,  -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f},
            {0.5f,  -0.5f, 0.5f,  0.0f,  1.0f, 1.0f, 1.0f},
            {0.5f,  -0.5f, 0.5f,  0.0f,  1.0f, 1.0f, 1.0f},
            {-0.5f, -0.5f, 0.5f,  0.0f,  1.0f, 1.0f, 1.0f},
            {-0.5f, -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f},

            {-0.5f, 0.5f,  -0.5f, 1.0f,  1.0f, 0.0f, 1.0f},
            {0.5f,  0.5f,  -0.5f, 1.0f,  1.0f, 0.0f, 1.0f},
            {0.5f,  0.5f,  0.5f,  1.0f,  1.0f, 0.0f, 1.0f},
            {0.5f,  0.5f,  0.5f,  1.0f,  1.0f, 0.0f, 1.0f},
            {-0.5f, 0.5f,  0.5f,  01.0f, 1.0f, 0.0f, 1.0f},
            {-0.5f, 0.5f,  -0.5f, 1.0f,  1.0f, 0.0f, 1.0f}
    };

//    LOGD("Pain Cube");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    m_pOpenGLShader->Bind();

    m_pOpenGLShader->SetAttributeBuffer(0, GL_FLOAT, cubeVertexs, 3, sizeof(CCFloat7));
    m_pOpenGLShader->EnableAttributeArray(0);

    m_pOpenGLShader->SetAttributeBuffer(1, GL_FLOAT, &cubeVertexs[0].r, 4, sizeof(CCFloat7));
    m_pOpenGLShader->EnableAttributeArray(1);

    m_angle += 3.0f;
//    LOGD("m_angle = %f", m_angle);

    float ratio = (float)m_width / (float)m_height;

    UpdateMVPMatrix(m_MVPMatrix, m_angle, m_angle, 0.5f, ratio);
    m_pOpenGLShader->SetUniformValue("u_mat", m_MVPMatrix);

    glDrawArrays(GL_TRIANGLES, 0, 36);

    m_pOpenGLShader->Release();
}

void CubeSample::UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float scale, float ratio)
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
            glm::vec3(0, 0, 1.8), // Camera is at (0,0,1), in World Space
            glm::vec3(0, 0, -1), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    // Model matrix
    glm::mat4 Model = glm::mat4(1.0f);
    Model = glm::scale(Model, glm::vec3(scale, scale, scale));
    Model = glm::rotate(Model, radiansX, glm::vec3(1.0f, 1.0f, 1.0f));
//    Model = glm::rotate(Model, radiansY, glm::vec3(0.0f, 1.0f, 0.0f));
    Model = glm::translate(Model, glm::vec3(0.0f, 0.0f, -0.3f));

    mvpMatrix = Projection * View * Model;
}

void CubeSample::Destroy() {

}