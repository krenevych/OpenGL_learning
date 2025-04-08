#version 330 core

in vec2 vTex;

uniform sampler2D uTexture0;
uniform sampler2D uTexture1;
uniform sampler2D uTexture2;

out vec4 FragColor;

void main() {
    vec4 color0 = texture(uTexture0, vTex);
    vec4 color1 = texture(uTexture1, vTex);
    vec4 color2 = texture(uTexture2, vTex);
//    FragColor = color1;
//    FragColor = color2;
    FragColor = mix(color0, color1, 0.6);
}