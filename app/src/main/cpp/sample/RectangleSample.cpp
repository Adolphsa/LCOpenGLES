//
// Created by Administrator on 2021/11/23.
//

#include "RectangleSample.h"

RectangleSample::RectangleSample()
{
    m_pOpenGLShader = new LCOpenGLShader();
}

RectangleSample::~RectangleSample()
{
    CCGLSafePtrDelete(m_pOpenGLShader);
}

void RectangleSample::Init(AAssetManager*  pManager)
{
    m_pOpenGLShader->InitShadersFromFile(pManager, "rectangle_vertex.glsl", "rectangle_fragment.glsl");
}

void RectangleSample::Draw()
{
    //绘制的时候需要注意绘制的顺序
    //按照定义的顶点的1 2 3, 2 3 4这样的顺序来绘制
    CCFloat3 vVertices[] = {
            {-0.5f,  -0.5f, 0.0f},//1
            {-0.5f, 0.5f, 0.0f}, //2
            {0.5f, -0.5f, 0.0f}, //3
            {0.5f, 0.5f, 0.0f} //4
    };

    CCFloat4 colorVertices[] = {
            {1.0f, 0.0f, 0.0f, 1.0f},
            {0.0f ,1.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f, 1.0f},
            {1.0f, 0.0f, 1.0f, 1.0f}
    };

    LOGD("Pain Rectangle");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    m_pOpenGLShader->Bind();

    m_pOpenGLShader->SetAttributeBuffer(0, GL_FLOAT, vVertices, 3, sizeof(CCFloat3));
    m_pOpenGLShader->EnableAttributeArray(0);

    m_pOpenGLShader->SetAttributeBuffer(1, GL_FLOAT, colorVertices, 4, sizeof(CCFloat4));
    m_pOpenGLShader->EnableAttributeArray(1);

    glDrawArrays(GL_TRIANGLE_STRIP,0,4);

    m_pOpenGLShader->Release();
}

void RectangleSample::Destroy()
{

}
