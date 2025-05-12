//
// Created by Andrii Krenevych on 11.05.2025.
//


#pragma once

#ifndef SCENE_H
#define SCENE_H
#include "SceneBase.h"

#define CUBE "cube"

#define CAMERA_1_MASK 1       //    ...0000001
#define CAMERA_2_MASK 1 << 1  //    ...0000010

class Scene : public Renderer::SceneBase {
public:
    Scene(int width, int height);

    ~Scene() override;

    void onSceneInit() override;

    void onPreRenderScene() override;

    void onRenderScene(const std::shared_ptr<Renderer::Camera> &camera) override;

    void onPostRenderScene() override;
};


#endif //SCENE_H
