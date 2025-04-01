//
// Created by Andrii Krenevych on 01.04.2025.
//

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "glad/glad.h"

#include "utils.h"

std::string LoadShaderFromFile(const std::string &filePath) {
    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл: " << filePath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << shaderFile.rdbuf(); // зчитує весь вміст файлу в потік

    return buffer.str(); // повертає як std::string
}

GLuint createShader(std::string &filePath, GLuint shaderType) {
    std::string shaderCodeStr = LoadShaderFromFile(filePath);
    auto shaderCode =  shaderCodeStr.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    return shader;
}

GLuint createProgram(
    std::string vertPath,
    std::string fragPath
) {
    auto vertexShader = createShader(
        vertPath,
        GL_VERTEX_SHADER
        );

    auto fragmentShader = createShader(
        fragPath,
        GL_FRAGMENT_SHADER
        );

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
