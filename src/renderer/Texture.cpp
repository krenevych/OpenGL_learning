//
// Created by Andrii Krenevych on 21.04.2025.
//

#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include <iostream>

#include "stb_image.h"
#include "glad/glad.h"

#include "Texture.h"

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
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load and generate the texture
        int width, height, nrChannels;
        unsigned char *data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
        if (!data) {
            std::cout << "Failed to load texture" << std::endl;
            glDeleteTextures(1, &texture);
            return 0;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        return texture;
    }
} // Renderer