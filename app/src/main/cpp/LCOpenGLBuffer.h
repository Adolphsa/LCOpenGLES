//
// Created by Administrator on 2021/11/30.
//

#ifndef LCOPENGLES_LCOPENGLBUFFER_H
#define LCOPENGLES_LCOPENGLBUFFER_H

#include "LCGLCommonDef.h"

class LCOpenGLBuffer {

public:

    enum Type{
        VertexBuffer        = 0x8892, // GL_ARRAY_BUFFER
        IndexBuffer         = 0x8893, // GL_ELEMENT_ARRAY_BUFFER
        PixelPackBuffer     = 0x88EB, // GL_PIXEL_PACK_BUFFER
        PixelUnpackBuffer   = 0x88EC  // GL_PIXEL_UNPACK_BUFFER
    };

    enum UsagePattern
    {
        StreamDraw          = 0x88E0, // GL_STREAM_DRAW
        StreamRead          = 0x88E1, // GL_STREAM_READ
        StreamCopy          = 0x88E2, // GL_STREAM_COPY
        StaticDraw          = 0x88E4, // GL_STATIC_DRAW
        StaticRead          = 0x88E5, // GL_STATIC_READ
        StaticCopy          = 0x88E6, // GL_STATIC_COPY
        DynamicDraw         = 0x88E8, // GL_DYNAMIC_DRAW
        DynamicRead         = 0x88E9, // GL_DYNAMIC_READ
        DynamicCopy         = 0x88EA  // GL_DYNAMIC_COPY
    };

    LCOpenGLBuffer(LCOpenGLBuffer::Type type, LCOpenGLBuffer::UsagePattern usage);
    ~LCOpenGLBuffer();

    void Bind();
    void Release();

    void Create();
    void SetBufferData(const GLvoid *data, GLsizeiptr size);

private:
    LCOpenGLBuffer::Type m_bufferType;
    LCOpenGLBuffer::UsagePattern m_usage;
    GLuint m_buffID;
    GLsizeiptr m_bufferSize;
};


#endif //LCOPENGLES_LCOPENGLBUFFER_H
