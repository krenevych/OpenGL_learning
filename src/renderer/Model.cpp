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
        mMaterial->bind();  // FIXME: uncomment after refactoring

        mGeometry->draw();

        mGeometry->unbind();
        mMaterial->unbind();  // FIXME: uncomment after refactoring

    }

    void Model::bind() {  // FIXME: remove after refactoring
        mMaterial->bind();
    }

    void Model::setGeometry(std::shared_ptr<Geometry> &geometry) {
        mGeometry = geometry;
    }

    void Model::setMaterial(std::shared_ptr<Material> &material) {
        mMaterial = material;
    }

    void Model::setTransform(std::shared_ptr<Transformation> &transform) {
        mTransform = transform;
    }
} // Renderer
