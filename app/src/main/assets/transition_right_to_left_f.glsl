#version 300 es
precision mediump float;

uniform float uValue;

uniform sampler2D uTexture0;
uniform sampler2D uTexture1;

in vec2 o_uv;
out vec4 fragColor;

void main() {

    vec4 newColor = vec4(0, 0, 0, 0);

    if (o_uv.x > (1.0 - uValue)) {
        newColor = texture(uTexture1, vec2(o_uv.x - (1.0-uValue), o_uv.y));
    } else {
        newColor = texture(uTexture0, o_uv);
    }

    fragColor = newColor;
}
