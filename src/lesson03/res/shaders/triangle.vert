
#version 330 core

layout(location = 0) in vec4 aPos;
layout(location = 1) in vec4 aColor;

out vec4 vColor;

void main() {
    // gl_Position = vec4(aPos, 1.0);
    gl_Position = aPos;
    vColor = aColor;
}