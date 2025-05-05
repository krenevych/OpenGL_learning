//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include <map>
#include <memory>

#include "Program.h"
#include "Property.h"
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

        void setTexture(const std::string &name, const std::shared_ptr<Texture> &texture);

        void setProperty(const std::shared_ptr<Property> & property);

    private:
        std::shared_ptr<Program> mProgram;
        std::map<std::string, std::shared_ptr<Texture>> mTextures;
        std::map<std::string, std::shared_ptr<Property>> mProperties;


    };
} // Renderer

#endif //MATERIAL_H
