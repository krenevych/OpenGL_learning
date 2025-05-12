//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Renderer {
    class Camera {
    public:
        Camera(float fovDegrees, float aspectRatio, float nearPlane, float farPlane);

        void setPosition(const glm::vec3 &position);

        void lookAt(const glm::vec3 &target, const glm::vec3 &up = glm::vec3(0.0f, 1.0f, 0.0f));

        void setPerspective(float fovDegrees, float aspectRatio, float nearPlane, float farPlane);

        glm::mat4 getViewMatrix() const;

        glm::mat4 getProjectionMatrix() const;

        const glm::vec3 &getPosition() const;

        void applyClear() const;

        void setClearColor(const glm::vec4 &color);

        void setClearColor(float r, float g, float b, float a);

        void setClearColorBufferEnabled(bool enabled);

        void setClearDepthBufferEnabled(bool enabled);

        void setDepthTestEnabled(bool enabled);

        const glm::vec4 &getClearColor() const;

        bool isClearColorBufferEnabled() const;

        bool isClearDepthBufferEnabled() const;

        bool isDepthTestEnabled() const;

        void applyDepthTest() const;

        void setDrawOrder(int order);
        int getDrawOrder() const;

        void setRenderMask(long mask);
        long getRenderMask() const;

    private:
        int mDrawOrder = 0;
        long mRenderMask = -1;   // бітова маска видимості, за промовчанням -1, що відповідає числу "11111...111" у двійковій системі запису


        glm::vec4 mClearColor{1.0f, 1.0f, 1.0f, 1.0f};
        bool mClearColorBuffer = true;
        bool mClearDepthBuffer = false;
        bool mEnableDepthTest = false;

        glm::vec3 mPosition;
        glm::vec3 mTarget;
        glm::vec3 mUp;

        float mFovDegrees;
        float mAspectRatio;
        float mNear;
        float mFar;
    };
} // Renderer

#endif //CAMERA_H
