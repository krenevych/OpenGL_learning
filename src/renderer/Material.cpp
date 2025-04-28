//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Material.h"

namespace Renderer {
    Material::Material() {
    }

    Material::~Material() {
    }

    void Material::bind() {
        mProgram->activate();
    }

    void Material::unbind() {
        mProgram->deactivate();
    }

    void Material::setProgram(std::shared_ptr<Program>& program) {
        mProgram = program;
    }
} // Renderer