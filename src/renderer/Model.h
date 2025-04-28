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

        void draw();
        void bind(); // FIXME: Remove after refactoring

        void setGeometry(std::shared_ptr<Geometry>& geometry);
        void setMaterial(std::shared_ptr<Material>& material);
        void setTransform(std::shared_ptr<Transformation>& transform);

    private:

        std::shared_ptr<Geometry> mGeometry;
        std::shared_ptr<Material> mMaterial;
        std::shared_ptr<Transformation> mTransform;

    };
} // Renderer

#endif //MODEL_H
