#version 300 es

layout(location = 0) in vec4 aPosition;
layout(location = 1) in vec2 aTexCoord;

out vec2 o_uv;

void main() {

    gl_Position = aPosition;
    o_uv = aTexCoord;
}
