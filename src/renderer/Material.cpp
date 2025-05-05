//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Material.h"

namespace Renderer {
    Material::Material(const std::string &vertPath, const std::string &fragPath) {
        mProgram = std::make_shared<Program>(vertPath, fragPath);
    }

    Material::~Material() = default;

    void Material::bind() {
        mProgram->activate();


        // int r = 10;
        // int g = r; // копіювання
        //
        // g = 99; // r = 10, g = 99


        // int r = 10;
        // int& g = r;
        // g = 99; // r = 99, g = 99

        // int r = 10;
        // const int& g = r;
        // // g = 99; // ця операція не валідна, бо g - незмінювана
        // r = 99; // r = 99, g = 99

        int textureUnit = 0;
        for (const auto &textureEntity: mTextures) {
            const auto &name = textureEntity.first;
            const auto &texture = textureEntity.second;
            texture->bind(mProgram->getShaderProgram(), name, textureUnit++);
        }
    }

    void Material::unbind() {
        mProgram->deactivate();
    }

    void Material::setProgram(std::shared_ptr<Program> &program) {
        mProgram = program;
    }

    unsigned int Material::getShaderProgram() {
        return mProgram->getShaderProgram();
    }

    void Material::setTexture(const std::string &name, const std::shared_ptr<Texture> &texture) {
        mTextures[name] = texture;
    }
} // Renderer
