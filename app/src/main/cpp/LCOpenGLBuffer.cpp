//
// Created by Administrator on 2021/11/30.
//

#include "LCOpenGLBuffer.h"

LCOpenGLBuffer::LCOpenGLBuffer(LCOpenGLBuffer::Type type, LCOpenGLBuffer::UsagePattern usage)
{
    m_bufferSize = 0;
    m_usage = usage;
    m_bufferType = type;
}

LCOpenGLBuffer::~LCOpenGLBuffer()
{
    glDeleteBuffers(1, &m_buffID);
}

void LCOpenGLBuffer::Create()
{
    glGenBuffers(1, &m_buffID);
}

void LCOpenGLBuffer::Bind()
{
    glBindBuffer(m_bufferType, m_buffID);
}

void LCOpenGLBuffer::SetBufferData(const GLvoid *data, GLsizeiptr size)
{
    if (size > m_bufferSize) {
        m_bufferSize = size;
        glBufferData(m_bufferType, size, data, m_usage);
    } else {
        glBufferSubData(m_bufferType, 0, size, data);
    }
}

void LCOpenGLBuffer::Release()
{
    glBindBuffer(m_bufferType, 0);
}

