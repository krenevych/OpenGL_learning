#version 330 core

in vec4 vColor;
in vec2 vTex;  // receive from vertex shader

out vec4 FragColor;

uniform vec4 ambientColor;
uniform sampler2D MainTexture; // нульовий текстурний юніт
uniform sampler2D SecondTexture; // перший тексурний юнік

void main() {
    vec4 color1 = texture(MainTexture, vTex);
    vec4 color2 = texture(SecondTexture, vTex);
    FragColor = mix(color1, color2, 0.5);
}