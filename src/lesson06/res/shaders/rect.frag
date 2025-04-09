#version 330 core

in vec4 vColor;
in vec2 vTex;

out vec4 FragColor;

uniform vec4 ambientColor;
uniform sampler2D texture1;

void main() {
//    FragColor = vColor;
//    FragColor = ambientColor;
    vec4 color1 = texture(texture1, vTex);

    FragColor = color1;
}