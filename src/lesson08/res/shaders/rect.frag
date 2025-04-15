#version 330 core

in vec4 vColor;
in vec2 vTex;  // receive from vertex shader

out vec4 FragColor;

uniform vec4 ambientColor;
uniform sampler2D MainTexture; // нульовий текстурний юніт

void main() {
//    FragColor = texture(MainTexture, vTex);
    FragColor = vColor;
}