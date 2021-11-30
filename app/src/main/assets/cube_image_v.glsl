#version 300 es

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TexCoord;

uniform mat4 u_mat;
out vec2 o_uv;

void main() {
    gl_Position = u_mat * vec4(a_Position, 1.0);
    o_uv = a_TexCoord;
}
