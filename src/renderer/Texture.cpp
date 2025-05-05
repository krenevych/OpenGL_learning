//
// Created by Andrii Krenevych on 21.04.2025.
//

#include <string>
#include <iostream>

#include "glad/glad.h"

#include "Texture.h"

#include <texture.h>

namespace Renderer {
    Texture::Texture(const std::string &fileName) {
        mTextureId = load(fileName);
    }

    Texture::~Texture() {
        if (mTextureId) {
            glDeleteTextures(1, &mTextureId);
        }
    }

    void Texture::bind(unsigned int shaderProgram, const std::string& name, unsigned int textureUnit) const {
        auto texture0_loc = glGetUniformLocation(shaderProgram, name.c_str()); // (char *)&name
        glActiveTexture(GL_TEXTURE0 + textureUnit);  // активує текстурний юніт під номером textureUnit
        glBindTexture(GL_TEXTURE_2D, mTextureId);
        glUniform1i(texture0_loc, (int)textureUnit);
    }

    void Texture::unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    unsigned int Texture::load(const std::string &fileName) {
        return loadTexture(fileName);
    }
} // Renderer

