//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <vector>
#include <memory>
#include "Camera.h"
#include "Model.h"

namespace Renderer {
    class SceneBase {
    public:
        SceneBase(int width, int height);

        virtual ~SceneBase();

        virtual void onSceneInit();

        virtual void onPreRenderScene();

        virtual void onRenderScene(const std::shared_ptr<Camera> &camera);

        virtual void onPostRenderScene();

        void addModel(std::shared_ptr<Model> model);

        void addCamera(std::shared_ptr<Camera> camera);

        void render();

        std::shared_ptr<Model> getModel(const std::string& name);

    private:
        [[nodiscard]] std::vector<std::shared_ptr<Camera> > getCamerasSortedByDrawOrder() const;

    protected:
        int mWidth;
        int mHeight;

        std::vector<std::shared_ptr<Model> > mModels;
        std::vector<std::shared_ptr<Camera> > mCameras;
    };
} // Renderer

#endif //SCENE_BASE_H
