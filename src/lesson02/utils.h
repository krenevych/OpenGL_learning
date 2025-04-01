//
// Created by Andrii Krenevych on 01.04.2025.
//

#ifndef UTILS_H
#define UTILS_H

std::string LoadShaderFromFile(const std::string &filePath);

GLuint createShader(
    std::string &filePath,
    GLuint shaderType);

GLuint createProgram(
    std::string vertPath,
    std::string fragPath
);


#endif //UTILS_H
