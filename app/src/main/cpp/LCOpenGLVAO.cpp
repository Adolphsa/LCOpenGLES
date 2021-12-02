//
// Created by Administrator on 2021/11/30.
//

#include "LCOpenGLVAO.h"

LCOpenGLVAO::LCOpenGLVAO()
{

}

LCOpenGLVAO::~LCOpenGLVAO()
{
    glDeleteVertexArrays(1,&m_vaoId);
}

void LCOpenGLVAO::Create()
{
    glGenVertexArrays(1, &m_vaoId);
}

void LCOpenGLVAO::Bind()
{
    glBindVertexArray(m_vaoId);
}

void LCOpenGLVAO::Release()
{
    glBindVertexArray(0);
}