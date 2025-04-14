#version 330 core

in vec4 vColor;
in vec2 vTex;  // receive from vertex shader

out vec4 FragColor;

uniform vec4 ambientColor;
uniform sampler2D texture0; // нульовий текстурний юніт
uniform sampler2D texture1; // нульовий текстурний юніт
uniform sampler2D texture2; // нульовий текстурний юніт

void main() {
//    FragColor = vColor;
//    FragColor = ambientColor;
    vec4 color0 = texture(texture0, vTex);
    vec4 color1 = texture(texture1, vTex);
    vec4 color2 = texture(texture2, vTex);

//    FragColor = color0;
//    FragColor = color1;
    FragColor = color2;
}