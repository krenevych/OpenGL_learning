
#version 330 core

layout(location = 0) in vec4 aPos;
layout(location = 1) in vec2 aTex;

out vec2 vTex;

void main() {
    // gl_Position = vec4(aPos, 1.0);
    gl_Position = aPos;
    vTex = vec2(aTex.x, 1.0 - aTex.y);
}