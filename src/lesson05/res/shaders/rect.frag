#version 330 core

in vec4 vColor;

out vec4 FragColor;

uniform vec4 ambientColor;

void main() {
//    FragColor = vColor;
    FragColor = ambientColor;
}