//
// Created by Administrator on 2021/11/24.
//

#include "LoadImageSample.h"

LoadImageSample::LoadImageSample()
{

    m_pOpenGLShader = new LCOpenGLShader();

    m_texID1 = 0;
    m_pGLTexture1 = new LCGLTexture();

    m_texID2 = 0;
    m_pGLTexture2 = new LCGLTexture();
}

LoadImageSample::~LoadImageSample()
{
    CCGLSafePtrDelete(m_pOpenGLShader);
    CCGLSafePtrDelete(m_pGLTexture1);
    CCGLSafePtrDelete(m_pGLTexture2);
}

void LoadImageSample::Init(AAssetManager*  pManager)
{

    m_texID1 = m_pGLTexture1->CreateGLTextureFromFile(pManager, "1.png");
    m_texID2 = m_pGLTexture1->CreateGLTextureFromFile(pManager, "2.png");

    m_pOpenGLShader->InitShadersFromFile(pManager, "loadImage_vertex.glsl", "loadImage_fragment.glsl");

}

void LoadImageSample::Draw()
{
    CCFloat5 planVertices[] =
    {
            { -0.5f, -0.5f, 1.0f,    0,  0 },
            {  -0.5f,0.5f, 1.0f,   0,  1 },
            {  0.5f,-0.5f, 1.0f,    1,  0 },
            {  0.5f, 0.5f, 1.0f,    1,  1 },
    };

    LOGD("Pain Image");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    m_pOpenGLShader->Bind();

    m_pOpenGLShader->SetAttributeBuffer(0, GL_FLOAT, planVertices, 3, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(0);

    m_pOpenGLShader->SetAttributeBuffer(1, GL_FLOAT, &planVertices[0].u, 2, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(1);

    m_pOpenGLShader->SetUniformValue("texture1", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texID1);

    m_pOpenGLShader->SetUniformValue("texture2", 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_texID2);


    glDrawArrays(GL_TRIANGLE_STRIP,0,4);

    m_pOpenGLShader->Release();

}

void LoadImageSample::Destroy()
{

}