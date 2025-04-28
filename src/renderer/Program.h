//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <iostream>

#include "glad/glad.h"


namespace Renderer {

class Program {
public:
    Program(
        const std::string& vertPath,
        const std::string& fragPath
        );
    virtual ~Program();

    [[nodiscard]] unsigned int getShaderProgram() const;

    void activate() const;

    void deactivate();

private:



    static GLuint shader(std::string &filePath, GLuint shaderType);

    static GLuint createProgram(
        std::string vertPath,
        std::string fragPath
    );

    GLuint mShaderProgram;

};

} // Renderer

#endif //PROGRAM_H
