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

       for (const auto& texture : mTextures) {
           texture->bind(mProgram->getShaderProgram());
       }

    }

    void Material::unbind() {
        mProgram->deactivate();
    }

    void Material::setProgram(std::shared_ptr<Program>& program) {
        mProgram = program;
    }

    unsigned int Material::getShaderProgram() {
        return mProgram->getShaderProgram();
    }

    void Material::addTexture(std::shared_ptr<Texture> &texture) {
        mTextures.push_back(texture);
    }
} // Renderer