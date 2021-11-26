//
// Created by Administrator on 2021/11/23.
//

#include "TriangleSample.h"

TriangleSample::TriangleSample()
{
    m_pOpenGLShader = new LCOpenGLShader();
}

TriangleSample::~TriangleSample()
{
    CCGLSafePtrDelete(m_pOpenGLShader);
}

void TriangleSample::Init(AAssetManager*  pManager)
{
    m_pOpenGLShader->InitShadersFromFile(pManager, "triangle_vertex.glsl", "triangle_fragment.glsl");
}

void TriangleSample::Draw()
{
    CCFloat3 vVertices[] = {
            {0.0f,  0.5f, 0.0f},
            {-0.5f, -0.5f, 0.0f},
            {0.5f, -0.5f, 0.0f}
    };

    CCFloat4 colorVertices[] = {
            {1.0f, 0.0f, 0.0f, 1.0f},
            {0.0f ,1.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f, 1.0f}
    };

    LOGD("Pain Triangle");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    m_pOpenGLShader->Bind();

    m_pOpenGLShader->SetAttributeBuffer(0, GL_FLOAT, vVertices, 3, sizeof(CCFloat3));
    m_pOpenGLShader->EnableAttributeArray(0);

    m_pOpenGLShader->SetAttributeBuffer(1, GL_FLOAT, colorVertices, 4, sizeof(CCFloat4));
    m_pOpenGLShader->EnableAttributeArray(1);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    m_pOpenGLShader->Release();
}

void TriangleSample::Destroy()
{

}