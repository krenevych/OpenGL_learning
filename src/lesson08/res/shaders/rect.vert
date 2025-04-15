
#version 330 core

layout(location = 0) in vec4 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTex;

//uniform vec4 ambientColor;

out vec4 vColor;
out vec2 vTex;  // transfer (with interpolation) into fragment shader

uniform mat4 Model; // трансформація моделі
uniform mat4 View; // як розташована камера, перетворює позіцію в систему координат камери
uniform mat4 Projection; // проекція камери


void main() {
    mat4 MVP = Projection * View  * Model;
    gl_Position =  MVP * aPos;
    vColor = aColor;
    vTex = aTex;
    vTex.y = 1.0 - vTex.y;
//    vColor = ambientColor;
}