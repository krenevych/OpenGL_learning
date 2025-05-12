//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "Camera.h"

#include "glad/glad.h"

namespace Renderer {
    Camera::Camera(float fovDegrees, float aspectRatio, float nearPlane, float farPlane)
        : mPosition(0.0f, 0.0f, 3.0f),
          mTarget(0.0f),
          mUp(0.0f, 1.0f, 0.0f),
          mFovDegrees(fovDegrees),
          mAspectRatio(aspectRatio),
          mNear(nearPlane),
          mFar(farPlane) {
    }

    void Camera::setPosition(const glm::vec3 &position) {
        mPosition = position;
    }

    void Camera::lookAt(const glm::vec3 &target, const glm::vec3 &up) {
        mTarget = target;
        mUp = up;
    }

    void Camera::setPerspective(float fovDegrees, float aspectRatio, float nearPlane, float farPlane) {
        mFovDegrees = fovDegrees;
        mAspectRatio = aspectRatio;
        mNear = nearPlane;
        mFar = farPlane;
    }

     glm::mat4 Camera::getViewMatrix() const {
        return glm::lookAt(mPosition, mTarget, mUp);;
    }

    glm::mat4 Camera::getProjectionMatrix() const {
        return glm::perspective(glm::radians(mFovDegrees), mAspectRatio, mNear, mFar);;
    }

    const glm::vec3 &Camera::getPosition() const {
        return mPosition;
    }


    void Camera::setClearColor(const glm::vec4 &color) {
        mClearColor = color;
    }

    void Camera::setClearColor(const float r, const float g, const float b, const float a) {
        mClearColor = glm::vec4(r, g, b, a);
    }

    void Camera::setClearColorBufferEnabled(bool enabled) {
        mClearColorBuffer = enabled;
    }

    void Camera::setClearDepthBufferEnabled(bool enabled) {
        mClearDepthBuffer = enabled;
    }

    void Camera::setDepthTestEnabled(bool enabled) {
        mEnableDepthTest = enabled;
    }

    const glm::vec4 &Camera::getClearColor() const {
        return mClearColor;
    }

    bool Camera::isClearColorBufferEnabled() const {
        return mClearColorBuffer;
    }

    bool Camera::isClearDepthBufferEnabled() const {
        return mClearDepthBuffer;
    }

    bool Camera::isDepthTestEnabled() const {
        return mEnableDepthTest;
    }

    void Camera::applyClear() const {
        glClearColor(mClearColor.r, mClearColor.g, mClearColor.b, mClearColor.a);

        GLbitfield clearFlags = 0;
        if (mClearColorBuffer) clearFlags |= GL_COLOR_BUFFER_BIT;
        if (mClearDepthBuffer) clearFlags |= GL_DEPTH_BUFFER_BIT;

        if (clearFlags != 0)
            glClear(clearFlags);
    }

    void Camera::applyDepthTest() const {
        if (mEnableDepthTest) {
            glEnable(GL_DEPTH_TEST);
        } else {
            glDisable(GL_DEPTH_TEST);
        }
    }

    void Camera::setDrawOrder(int order) {
        mDrawOrder = order;
    }

    int Camera::getDrawOrder() const {
        return mDrawOrder;
    }

    void Camera::setRenderMask(long mask) {
        mRenderMask = mask;
    }

    long Camera::getRenderMask() const {
        return mRenderMask;
    }
} // Renderer
