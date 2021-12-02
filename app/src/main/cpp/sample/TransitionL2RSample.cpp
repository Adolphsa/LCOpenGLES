//
// Created by Administrator on 2021/12/2.
//

#include "TransitionL2RSample.h"

TransitionL2RSample::TransitionL2RSample()
{
    m_pVAO = new LCOpenGLVAO();
    m_pVBO = new LCOpenGLBuffer(LCOpenGLBuffer::VertexBuffer, LCOpenGLBuffer::StaticDraw);
    m_pEBO = new LCOpenGLBuffer(LCOpenGLBuffer::IndexBuffer, LCOpenGLBuffer::StaticDraw);

    m_pOpenGLShader = new LCOpenGLShader();
}

TransitionL2RSample::~TransitionL2RSample()
{
    glDeleteTextures(6, m_texId);

    CCGLSafePtrDelete(m_pVAO);
    CCGLSafePtrDelete(m_pVBO);
    CCGLSafePtrDelete(m_pEBO);
    CCGLSafePtrDelete(m_pOpenGLShader);
}

void TransitionL2RSample::Init(AAssetManager*  pManager)
{
    if (pManager == nullptr) return;

    //加载纹理
    loadTextureResources(pManager);
    //加载shader
    loadShaderResources(pManager);
    //设置渲染的屏幕大小
    setupRenderScreenSize();
    //设置渲染相关对象
    setupRenderingObject();
}

void TransitionL2RSample::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);

    renderObject();
}

void TransitionL2RSample::Destroy()
{

}

void TransitionL2RSample::setupRenderingObject()
{
    if (m_pOpenGLShader == nullptr) return;

    //顶点坐标和uv坐标
    const CCFloat5 planeVertexes[]  = {
            {  -0.5,-0.5, 0.0 ,  0.0, 0.0 },
            {  -0.5, 0.5, 0.0 ,  0.0, 1.0 },
            {  0.5, -0.5,  0.0 , 1.0, 0.0 },
            {   0.5, 0.5, 0.0 ,  1.0, 1.0 },
    };

    //索引坐标
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

    m_pOpenGLShader->SetAttributeBuffer(0, GL_FLOAT, (void*)offset, 3, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(0);

    offset += 3 * sizeof(float);

    m_pOpenGLShader->SetAttributeBuffer(1, GL_FLOAT, (void*)offset, 2, sizeof(CCFloat5));
    m_pOpenGLShader->EnableAttributeArray(1);

    m_pVAO->Release();
    m_pVBO->Release();
    m_pEBO->Release();

    glBindTexture(GL_TEXTURE_2D,0);
}

void TransitionL2RSample::renderObject()
{
    m_nValue += 0.01f;
    if (m_nValue > 1.0f) {
        m_nValue = 0.0f;
    }

    glm::mat4x4  objectMat;
    glm::mat4x4  objectTransMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3));

    glm::mat4 projMat = glm::perspective(glm::radians(45.0f), m_nResolution.x/m_nResolution.y, 0.1f, 1000.0f);
    objectMat = projMat* objectTransMat;

    m_pOpenGLShader->Bind();

    m_pOpenGLShader->SetUniformValue("u_mat", objectMat);
    m_pOpenGLShader->SetUniformValue("uValue", m_nValue);

    m_pOpenGLShader->SetUniformValue("uTexture0", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texId[3]);

    m_pOpenGLShader->SetUniformValue("uTexture1", 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_texId[4]);

    m_pVAO->Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);

    m_pOpenGLShader->Release();
    m_pVAO->Release();
}

void TransitionL2RSample::setupRenderScreenSize()
{
    int viewport[4] = {0};
    glGetIntegerv( GL_VIEWPORT, viewport );
    int sWidth = viewport[2];
    int sHeight = viewport[3];
    m_nResolution = glm::vec2(sWidth,sHeight);

    LOGD("VIEWPORT: width = %d height = %d",viewport[2],viewport[3]);
}

void TransitionL2RSample::setupFrameBufferObject()
{

}

void TransitionL2RSample::loadTextureResources(AAssetManager *pManager)
{
    //从assets文件夹加载图片 并转化为纹理
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

void TransitionL2RSample::loadShaderResources(AAssetManager *pManager)
{
    //从assets文件夹加载shader文件 并编译链接
    //从左到右
//    m_pOpenGLShader->InitShadersFromFile(pManager,
//                                         "transition_left_to_right_v.glsl",
//                                         "transition_left_to_right_f.glsl");

    //从右到左
    m_pOpenGLShader->InitShadersFromFile(pManager,
                                         "transition_right_to_left_v.glsl",
                                         "transition_right_to_left_f.glsl");
}
