
#version 330 core

layout(location = 0) in vec4 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTex;

//uniform vec4 ambientColor;

out vec4 vColor;
out vec2 vTex;  // transfer (with interpolation) into fragment shader

void main() {
    // gl_Position = vec4(aPos, 1.0);
    gl_Position = aPos;
    vColor = aColor;
    vTex = aTex;
    vTex.y = 1.0 - vTex.y;
//    vColor = ambientColor;
}