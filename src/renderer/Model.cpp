//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Model.h"

#include "Camera.h"
#include "Transformation.h"

namespace Renderer {
    Model::Model()
        : mTransform(std::make_shared<Transformation>()) {
    }

    Model::~Model() = default;

    void Model::draw(const std::shared_ptr<Camera> &camera) const {

        if (!mVisible) {
            return;
        }

        // якщо маски камери та моделі збігаються, тоді малювати інакше вийти з методу
        //   0000001                 &    1111111
        if ((camera->getRenderMask() & mRenderMask) == 0) {
            return;
        }

        mGeometry->bind();
        mMaterial->bind(camera, mTransform->getTransform());

        mGeometry->draw();

        mGeometry->unbind();
        mMaterial->unbind();
    }

    void Model::setGeometry(std::shared_ptr<Geometry> &geometry) {
        mGeometry = geometry;
    }

    void Model::setMaterial(std::shared_ptr<Material> &material) {
        mMaterial = material;
    }

    void Model::setPosition(const glm::vec3 &position) const {
        mTransform->setPosition(position);
    }

    void Model::setScale(const glm::vec3 &scale) const {
        mTransform->setScale(scale);
    }

    void Model::setRotationEuler(glm::vec3 eulerDegrees) const {
        mTransform->setRotationEuler(eulerDegrees);
    }

    void Model::setRotationQuaternion(const glm::quat &quat) const {
        mTransform->setRotationQuaternion(quat);
    }

    void Model::setTransformation(const glm::mat4 &matrix) const {
        mTransform->setTransform(matrix);
    }

    const glm::vec3 &Model::getPosition() const {
        return mTransform->getPosition();
    }

    const glm::vec3 &Model::getScale() const {
        return mTransform->getScale();
    }

    const glm::quat &Model::getRotation() const {
        return mTransform->getRotation();
    }

    glm::mat4 Model::getTransformation() const {
        return mTransform->getTransform();
    }

    void Model::setDrawOrder(int order) {
    }

    int Model::getDrawOrder() const {
    }

    void Model::setVisible(bool visible) {
        mVisible = visible;
    }

    bool Model::isVisible() const {
        return mVisible;
    }

    void Model::setRenderMask(long mask) {
        mRenderMask = mask;
    }

    long Model::getRenderMask() const {
        return mRenderMask;
    }

    void Model::setName(const std::string &name) {
        mName = name;
    }

    const std::string &Model::getName() const {
        return mName;
    }
} // Renderer
