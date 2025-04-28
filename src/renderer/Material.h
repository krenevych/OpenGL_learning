//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include <memory>

#include "Program.h"
#include "Texture.h"

namespace Renderer {
    class Material {
    public:
        Material(
            const std::string &vertPath,
            const std::string &fragPath
        );

        virtual ~Material();

        void bind();

        void unbind();

        void setProgram(std::shared_ptr<Program> &program);

        unsigned int getShaderProgram();

        void addTexture(std::shared_ptr<Texture> &texture);

    private:
        std::shared_ptr<Program> mProgram;
        std::vector<std::shared_ptr<Texture>> mTextures;


    };
} // Renderer

#endif //MATERIAL_H
