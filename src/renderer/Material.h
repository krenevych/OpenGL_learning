//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include <memory>

#include "Program.h"

namespace Renderer {
    class Material {
    public:
        Material();

        virtual ~Material();

        void bind();

        void unbind();

        void setProgram(std::shared_ptr<Program>& program);

    private:
        std::shared_ptr<Program> mProgram;

    };
} // Renderer

#endif //MATERIAL_H
