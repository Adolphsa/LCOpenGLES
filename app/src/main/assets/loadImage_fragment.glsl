#version 300 es
precision mediump float;

uniform sampler2D texture1;
uniform sampler2D texture2;
in vec2 o_uv;

out vec4 fragColor;

void main() {
    fragColor = mix(texture(texture1, o_uv), texture(texture2, o_uv), 0.5);
}
