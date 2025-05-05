//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include <string>

#include "glm/mat4x4.hpp"
#include "glm/vec4.hpp"

namespace Renderer {
    class Property {
    public:
        explicit Property(const std::string &name);

        virtual ~Property();

        virtual void bind(unsigned int shaderProgram) = 0;

        const std::string& getName();

    protected:
        std::string mName;
    };

    class PropertyVec4: public Property {
    public:
        PropertyVec4(const std::string &name, float x, float y, float z, float w);
        PropertyVec4(const std::string &name, const glm::vec4& value);
        ~PropertyVec4() override;
        void bind(unsigned int shaderProgram) override;

    private:
        glm::vec4 mValue;
    };

    class PropertyMat4: public Property {
    public:
        PropertyMat4(const std::string &name, const glm::mat4& value);
        ~PropertyMat4() override;
        void bind(unsigned int shaderProgram) override;

    private:
        glm::mat4 mValue;
    };
} // Renderer

#endif //PROPERTY_H
