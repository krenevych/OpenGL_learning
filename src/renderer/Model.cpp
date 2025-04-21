//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Model.h"

namespace Renderer {
    Model::Model() {

    }

    Model::~Model() {

    }

    void Model::draw() {

        // активування матеріалів та геометрії
        // та draw calls

        mGeometry->bind();
        mMaterial->bind();

        mGeometry->draw();

        mGeometry->unbind();
        mMaterial->unbind();

    }
} // Renderer
