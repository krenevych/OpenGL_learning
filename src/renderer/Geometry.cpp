//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Geometry.h"


namespace Renderer {
    Geometry::Geometry()
        : VAO(0),
          vert_buffer(0),
          index_buffer(0) {

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &vert_buffer);
        // glGenBuffers(1, &index_buffer); // модель може бути безіндексна, тому цей буфер будемо створювати лише коли будемо додавати індекси
    }

    Geometry::~Geometry() {
        glDeleteBuffers(1, &vert_buffer);
        if (index_buffer != 0)
            glDeleteBuffers(1, &index_buffer);
        glDeleteVertexArrays(1, &VAO);
    }

    void Geometry::setVertices(const std::vector<float> &vertices) {
        mVertices = vertices;

        glBindVertexArray(VAO);
        // Vertices
        glBindBuffer(GL_ARRAY_BUFFER, vert_buffer);
        glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_STATIC_DRAW);
    }

    void Geometry::setIndices(const std::vector<unsigned int> &indices) {
        mIndices = indices;

        glGenBuffers(1, &index_buffer);

        glBindVertexArray(VAO);
        // Indices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(unsigned int), mIndices.data(), GL_STATIC_DRAW);


    }

    void Geometry::addAttribute(const std::string& name, int size, int offset, int location) {
        auto attrib = Attribute {
            .name = name,
            .size = size,
            .offset = offset,
            .location = location
        };
        mAttributes.push_back(attrib);
    }

    int Geometry::getStride() {
        auto stride = 0;
        for (const auto& attrib : mAttributes) {
            stride += attrib.size;
        }
        return stride;
    }

    void Geometry::bind() {
        glBindVertexArray(VAO);

        for (const auto& attrib : mAttributes) {
            // Позиція вершини → location = 0 в шейдері
            glEnableVertexAttribArray(attrib.location);
            glVertexAttribPointer(
                attrib.location, // location
                attrib.size, // size
                GL_FLOAT, // тип даних
                GL_FALSE, // не нормалізувати
                getStride() * sizeof(float), // stride
                (void *) (sizeof(float) * attrib.offset) // offset
            );
        }
    }

    void Geometry::unbind() {
        glBindVertexArray(0);
    }

    void Geometry::draw() {
        if (index_buffer != 0) {  // індексна модель, бо згенерований індексний буфер
            glDrawElements(GL_TRIANGLES, getVertexCount() , GL_UNSIGNED_INT, nullptr);
        } else {
            glDrawArrays(GL_TRIANGLES, 0, getVertexCount() );
        }
    }

    int Geometry::getVertexCount() {
        if (index_buffer != 0) {
            return mIndices.size();
        } else {
            return mVertices.size() / getStride(); // TODO:
        }
    }
} // Renderer
