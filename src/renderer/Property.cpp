//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Property.h"

#include "glad/glad.h"

namespace Renderer {
    Property::Property(const std::string &name)
        : mName(name) {
    }

    Property::~Property() = default;

    const std::string & Property::getName(){
        return mName;
    }


    PropertyVec4::PropertyVec4(const std::string &name,
                               const float x, const float y, const float z, const float w)
        : Property(name),
          mValue(x, y, z, w) {
    }

    PropertyVec4::PropertyVec4(const std::string &name, const glm::vec4& value)
        : Property(name),
          mValue(value) {
    }

    PropertyVec4::~PropertyVec4() = default;

    void PropertyVec4::bind(unsigned int shaderProgram) {
        auto propLoc = glGetUniformLocation(shaderProgram, mName.c_str());

        glUniform4fv(propLoc, 1, (float*)&mValue);
    }

    PropertyMat4::PropertyMat4(const std::string &name, const glm::mat4 &value)
    : Property(name),
    mValue(value){
    }

    PropertyMat4::~PropertyMat4() = default;

    void PropertyMat4::bind(unsigned int shaderProgram) {
        auto propLoc = glGetUniformLocation(shaderProgram, mName.c_str());
        glUniformMatrix4fv(propLoc, 1, GL_FALSE, (float*)&mValue);
    }
} // Renderer
