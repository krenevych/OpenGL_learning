//
// Created by Andrii Krenevych on 21.04.2025.
//

#include "SceneBase.h"

namespace Renderer {
    SceneBase::SceneBase(int width, int height)
        : mWidth(width),
          mHeight(height) {
    }

    SceneBase::~SceneBase() = default;

    void SceneBase::onSceneInit() {
    }

    void SceneBase::onPreRenderScene() {
    }

    void SceneBase::onRenderScene(const std::shared_ptr<Camera> &camera) {
    }

    void SceneBase::onPostRenderScene() {
    }

    void SceneBase::addModel(std::shared_ptr<Model> model) {
        mModels.push_back(std::move(model));
    }

    void SceneBase::addCamera(std::shared_ptr<Camera> camera) {
        mCameras.push_back(std::move(camera));
    }

    void SceneBase::render() {
        onPreRenderScene();
        const auto cameras = getCamerasSortedByDrawOrder();
        for (const auto &camera: cameras) {
            camera->applyDepthTest();
            camera->applyClear();

            onRenderScene(camera);
            for (const auto &model: mModels) {
                model->draw(camera);
            }
        }
        onPostRenderScene();
    }

    std::shared_ptr<Model> SceneBase::getModel(const std::string& name) {
        auto it = std::find_if(mModels.begin(), mModels.end(),
            [&name](const std::shared_ptr<Model>& model) {
                return model->getName() == name;
            });

        return (it != mModels.end()) ? *it : nullptr;
    }

    std::vector<std::shared_ptr<Camera> > SceneBase::getCamerasSortedByDrawOrder() const {
        std::vector<std::shared_ptr<Camera> > sortedCameras = mCameras;
        std::sort(sortedCameras.begin(), sortedCameras.end(),
                  [](const std::shared_ptr<Camera> &a, const std::shared_ptr<Camera> &b) {
                      return a->getDrawOrder() < b->getDrawOrder();
                  });
        return sortedCameras;
    }
} // Renderer
