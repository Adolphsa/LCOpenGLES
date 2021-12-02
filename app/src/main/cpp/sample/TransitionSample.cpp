//
// Created by Administrator on 2021/12/1.
//

#include "TransitionSample.h"

TransitionSample::TransitionSample()
{
    m_pVAO = new LCOpenGLVAO();
    m_pVBO = new LCOpenGLBuffer(LCOpenGLBuffer::VertexBuffer, LCOpenGLBuffer::StaticDraw);
    m_pEBO = new LCOpenGLBuffer(LCOpenGLBuffer::IndexBuffer, LCOpenGLBuffer::StaticDraw);

    m_pOpenGLShader = new LCOpenGLShader();

}

TransitionSample::~TransitionSample()
{
    glDeleteTextures(6,m_texId);

    CCGLSafePtrDelete(m_pOpenGLShader);
    CCGLSafePtrDelete(m_pVAO);
    CCGLSafePtrDelete(m_pVBO);
    CCGLSafePtrDelete(m_pEBO);
}

void TransitionSample::Init(AAssetManager*  pManager)
{

    if (pManager != nullptr) {
        loadTextureResources(pManager);
        loadShaderResources(pManager);
    }

    setupRenderScreenSize();

    setupRenderingObject();
}

void TransitionSample::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);

    renderObject();

}

void TransitionSample::Destroy()
{

}

void TransitionSample::setupRenderingObject()
{
    if (m_pOpenGLShader == nullptr) {
        return;
    }

    const CCFloat5 planeVertexes[]  = {
            {  -0.5,-0.5, 0.0 ,  0.0, 0.0 },
            {  -0.5, 0.5, 0.0 ,  0.0, 1.0 },
            {  0.5, -0.5,  0.0 , 1.0, 0.0 },
            {   0.5, 0.5, 0.0 ,  1.0, 1.0 },
    };

    const short planeIndexes[]= {
            0, 1, 2,  1, 3, 2
    };

    m_pVAO->Create();
    m_pVAO->Bind();

    m_pVBO->Create();
    m_pVBO->Bind();
    m_pVBO->SetBufferData(planeVertexes, sizeof(planeVertexes));

    m_pEBO->Create();
    m_pEBO->Bind();
    m_pEBO->SetBufferData(planeIndexes, sizeof(planeIndexes));

    int offset = 0;

    m_pOpenGLShader->SetAttributeBuffer(0, GL_FLOAT, (void *)offset, 3, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(0);

    offset += 3 * sizeof(float);

    m_pOpenGLShader->SetAttributeBuffer(1, GL_FLOAT, (void *)offset, 2, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(1);

    m_pVAO->Release();
    m_pVBO->Release();
    m_pEBO->Release();

    glBindTexture(GL_TEXTURE_2D,0);

}

void TransitionSample::renderObject()
{
    m_nValue += 0.01f;
    if (m_nValue > 1.0f) {
        m_nValue = 0.0f;
    }

//    m_angle += 0.01f;

    glm::mat4x4  objectMat;
    glm::mat4x4  objectTransMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3));
//    glm::mat4x4  objectRotMat = glm::rotate(glm::mat4(1.0f), m_angle, glm::vec3(1.0f, 1.0f, 1.0f) );
//    glm::mat4x4  objectScaleMat = glm::scale(glm::mat4(1.0f),glm::vec3(0.5f, 0.5f, 0.5) );

    glm::mat4 projMat = glm::perspective(glm::radians(45.0f), m_nResolution.x/m_nResolution.y, 0.1f, 1000.0f);
    objectMat = projMat* objectTransMat ;

    m_pOpenGLShader->Bind();

    m_pOpenGLShader->SetUniformValue("u_mat", objectMat);
    m_pOpenGLShader->SetUniformValue("uValue", m_nValue);

    m_pOpenGLShader->SetUniformValue("uTexture0", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texId[0]);

    m_pOpenGLShader->SetUniformValue("uTexture1", 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_texId[1]);

    m_pVAO->Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);

    m_pOpenGLShader->Release();
    m_pVAO->Release();
}

void TransitionSample::setupRenderScreenSize()
{
    int viewport[4] = {0};
    glGetIntegerv( GL_VIEWPORT, viewport );
    int sWidth = viewport[2];
    int sHeight = viewport[3];
    m_nResolution = glm::vec2(sWidth,sHeight);

    LOGD("VIEWPORT: width = %d height = %d",viewport[2],viewport[3]);
}

void TransitionSample::setupFrameBufferObject()
{

}

void TransitionSample::loadTextureResources(AAssetManager *pManager)
{
    for (int i = 0; i < 6; ++i) {
        char nameBuff[6];
        memset(nameBuff, 0, sizeof(nameBuff));
        sprintf(nameBuff,"%d.png",i+1);
        nameBuff[5]='\0';
        LOGD("Image Name:%s",nameBuff);
        LCGLTexture glTexture;
        m_texId[i] = glTexture.CreateGLTextureFromFile(pManager,nameBuff);
    }
}

void TransitionSample::loadShaderResources(AAssetManager *pManager)
{
    m_pOpenGLShader->InitShadersFromFile(pManager, "transition_leftbottom_to_righttop_v.glsl", "transition_leftbottom_to_righttop_f.glsl");
}