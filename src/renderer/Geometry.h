//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef GEOMETRY_H
#define GEOMETRY_H

namespace Renderer {
    class Geometry {
    public:
        Geometry();

        virtual ~Geometry();

        void bind();

        void unbind();

        void draw();

    private:

    };
} // Renderer

#endif //GEOMETRY_H
