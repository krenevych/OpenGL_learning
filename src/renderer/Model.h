//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <memory>

#include "Geometry.h"
#include "Material.h"
#include "Transformation.h"

namespace Renderer {
    class Model {
    public:
        Model();

        virtual ~Model();

        void draw(const std::shared_ptr<Camera> &camera) const;

        void setGeometry(std::shared_ptr<Geometry>& geometry);
        void setMaterial(std::shared_ptr<Material>& material);

        void setPosition(const glm::vec3 &position) const;

        void setScale(const glm::vec3 &scale) const;

        void setRotationEuler(glm::vec3 eulerDegrees) const;

        void setRotationQuaternion(const glm::quat &quat) const;

        void setTransformation(const glm::mat4 &matrix) const;

        const glm::vec3 &getPosition() const;

        const glm::vec3 &getScale() const;

        const glm::quat &getRotation() const;

        glm::mat4 getTransformation() const;

        void setDrawOrder(int order);
        int getDrawOrder() const;

        void setVisible(bool visible);
        bool isVisible() const;

        void setRenderMask(long mask);
        long getRenderMask() const;

        void setName(const std::string &name);
        const std::string &getName() const;

    private:

        std::string mName;
        int mDrawOrder = 0;
        bool mVisible = true;
        long mRenderMask = -1;  // бітова маска видимості

        std::shared_ptr<Geometry> mGeometry;
        std::shared_ptr<Material> mMaterial;
        std::shared_ptr<Transformation> mTransform;
    };
} // Renderer

#endif //MODEL_H
