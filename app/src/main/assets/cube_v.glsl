#version 300 es
layout(location = 0) in vec4 a_posiiton;
layout(location = 1) in vec4 a_color;

uniform mat4 u_mat;
out vec4 v_color;

void main() {
    gl_Position = u_mat * a_posiiton;
    v_color = a_color;
}
