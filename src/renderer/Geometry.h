//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <vector>

#include "glad/glad.h"

namespace Renderer {
    class Geometry {
    public:
        Geometry();

        virtual ~Geometry();

        void setVertices(const std::vector<float>& vertices);
        void setIndices(const std::vector<unsigned int>& indices);

        void bind();

        void unbind();

        void draw();

        int getVertexCount();

    private:

        GLuint VAO; // vertex array object
        GLuint vert_buffer, index_buffer; // data

        std::vector<float> mVertices;
        std::vector<unsigned int> mIndices;

    };
} // Renderer

#endif //GEOMETRY_H
