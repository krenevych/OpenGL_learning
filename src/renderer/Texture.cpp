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

    void Texture::bind(unsigned int shaderProgram) const {
        auto texture0_loc = glGetUniformLocation(shaderProgram, "MainTexture");
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, mTextureId);
        glUniform1i(texture0_loc, 0);
    }

    void Texture::unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    unsigned int Texture::load(const std::string &fileName) {
        return loadTexture(fileName);
    }
} // Renderer

