#version 300 es
layout(location = 0) in vec4 a_posiiton;
layout(location = 1) in vec4 a_color;

out vec4 v_color;

void main() {
    gl_Position = a_posiiton;
    v_color = a_color;
}
