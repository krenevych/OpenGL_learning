//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Program.h"
#include "utils.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "glad/glad.h"

namespace Renderer {
    Program::Program(
        const std::string& vertPath,
        const std::string& fragPath
    )
        : mShaderProgram(0) {

        mShaderProgram = createProgram(vertPath, fragPath);
    }

    Program::~Program() {
        if (mShaderProgram) {
            glDeleteProgram(mShaderProgram);
        }
    }

    unsigned int Program::getShaderProgram() const {
        return mShaderProgram;
    }

    void Program::activate() const {
        glUseProgram(mShaderProgram);
    }

    void Program::deactivate() {
        glUseProgram(0);
    }

    GLuint Program::shader(std::string &filePath, GLuint shaderType) {
        std::string shaderCodeStr = LoadShaderFromFile(filePath);
        auto shaderCode = shaderCodeStr.c_str();

        GLuint shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderCode, nullptr);
        glCompileShader(shader);

        // Перевірка компіляції шейдера
        GLint success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Помилка компіляції шейдера:\n" << filePath << "\n" << infoLog << std::endl;
            glDeleteShader(shader);
            return 0;
        }

        return shader;
    }

    GLuint Program::createProgram(
        std::string vertPath,
        std::string fragPath
    ) {
        auto vertexShader = createShader(
            vertPath,
            GL_VERTEX_SHADER
        );

        if (vertexShader == 0) {
            return 0;
        }

        auto fragmentShader = createShader(
            fragPath,
            GL_FRAGMENT_SHADER
        );

        if (fragmentShader == 0) {
            return 0;
        }

        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        // Перевірка лінкування шейдерної програми
        GLint success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
            std::cerr << "Помилка лінкування shader program:\n" << infoLog << std::endl;
            glDeleteProgram(shaderProgram);
            return 0;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return shaderProgram;
    }
} // Renderer
