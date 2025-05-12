//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Material.h"


namespace Renderer {
    Material::Material(const std::string &vertPath, const std::string &fragPath) {
        mProgram = std::make_shared<Program>(vertPath, fragPath);
    }

    Material::~Material() = default;

    void Material::bind(
        const std::shared_ptr<Camera> &camera,
        const glm::mat4 &modelMat
    ) const {
        mProgram->activate();

        glUniformMatrix4fv(
            glGetUniformLocation(mProgram->getShaderProgram(), "Model"),
            1, GL_FALSE, (float *) &modelMat
        );

        const glm::mat4 viewMatr = camera->getViewMatrix();
        glUniformMatrix4fv(
            glGetUniformLocation(mProgram->getShaderProgram(), "View"),
            1, GL_FALSE, (float *) &viewMatr
        );

        const glm::mat4 projectionMatr = camera->getProjectionMatrix();
        glUniformMatrix4fv(
            glGetUniformLocation(mProgram->getShaderProgram(), "Projection"),
            1, GL_FALSE, (float *) &projectionMatr
        );

        int textureUnit = 0;
        for (const auto &textureEntity: mTextures) {
            const auto &name = textureEntity.first;
            const auto &texture = textureEntity.second;
            texture->bind(mProgram->getShaderProgram(), name, textureUnit++);
        }

        for (const auto &propertyEntity: mProperties) {
            const auto &name = propertyEntity.first;
            const auto &property = propertyEntity.second;
            property->bind(mProgram->getShaderProgram());
        }
    }

    void Material::unbind() {
        Program::deactivate();
    }

    void Material::setProgram(const std::shared_ptr<Program> &program) {
        mProgram = program;
    }

    void Material::setTexture(const std::string &name, const std::shared_ptr<Texture> &texture) {
        mTextures[name] = texture;
    }

    void Material::setProperty(const std::shared_ptr<Property> &property) {
        mProperties[property->getName()] = property;
    }
} // Renderer
