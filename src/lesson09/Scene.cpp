//
// Created by Andrii Krenevych on 11.05.2025.
//

#include "Scene.h"

Scene::Scene(int width, int height)
    : SceneBase(width, height) {
}

Scene::~Scene() = default;

void Scene::onSceneInit() {
    SceneBase::onSceneInit();

    ///// SET GEOMETRY START
    auto cubeGeom = std::make_shared<Renderer::Geometry>();
    cubeGeom->setVertices({
        // -------- Передня грань (червона) --------
        0.0f, 0.0f, 0.0f, /* кольори */ 1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 0.0, // лівий нижній
        1.0f, 0.0f, 0.0f, /* кольори */ 1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 0.0, // правий нижній
        1.0f, 1.0f, 0.0f, /* кольори */ 1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 1.0, // правий верхній
        0.0f, 1.0f, 0.0f, /* кольори */ 1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 1.0, // лівий верхній

        // -------- Задня грань (зелена) --------
        0.0f, 0.0f, 1.0f, /* кольори */ 0.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 0.0,
        1.0f, 0.0f, 1.0f, /* кольори */ 0.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f, /* кольори */ 0.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f, /* кольори */ 0.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 1.0,

        // -------- Ліва грань (синя) --------
        0.0f, 0.0f, 0.0f, /* кольори */ 0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 0.0,
        0.0f, 1.0f, 0.0f, /* кольори */ 0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 0.0,
        0.0f, 1.0f, 1.0f, /* кольори */ 0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 1.0,
        0.0f, 0.0f, 1.0f, /* кольори */ 0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 1.0,

        // -------- Права грань (жовта) --------
        1.0f, 0.0f, 0.0f, /* кольори */ 1.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f, /* кольори */ 1.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f, /* кольори */ 1.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 1.0f, /* кольори */ 1.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 1.0,

        // -------- Нижня грань (бірюзова) --------
        0.0f, 0.0f, 0.0f, /* кольори */ 0.0f, 1.0f, 1.0f, /* текстурні координати */ 0.0, 0.0,
        0.0f, 0.0f, 1.0f, /* кольори */ 0.0f, 1.0f, 1.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 0.0f, 1.0f, /* кольори */ 0.0f, 1.0f, 1.0f, /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 0.0f, /* кольори */ 0.0f, 1.0f, 1.0f, /* текстурні координати */ 0.0, 1.0,

        // -------- Верхня грань (фіолетова) --------
        0.0f, 1.0f, 0.0f, /* кольори */ 1.0f, 0.0f, 1.0f, /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f, /* кольори */ 1.0f, 0.0f, 1.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f, /* кольори */ 1.0f, 0.0f, 1.0f, /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f, /* кольори */ 1.0f, 0.0f, 1.0f, /* текстурні координати */ 0.0, 1.0,
    });

    cubeGeom->addAttribute("aPos", 3, 0, 0);
    cubeGeom->addAttribute("aColor", 3, 3, 1);
    cubeGeom->addAttribute("aTex", 2, 6, 2);

    cubeGeom->setIndices({
        0, 1, 2, 2, 3, 0, // передня
        4, 5, 6, 6, 7, 4, // задня
        8, 9, 10, 10, 11, 8, // ліва
        12, 13, 14, 14, 15, 12, // права
        16, 17, 18, 18, 19, 16, // нижня
        20, 21, 22, 22, 23, 20 // верхня
    });
    ///// SET GEOMETRY FINISH

    ///// SET MATERIAL START
    auto material = std::make_shared<Renderer::Material>(
        "res/shaders/rect.vert",
        "res/shaders/rect.frag"
    );

    // додамо текстури, властивості і т.д.
    auto texture = std::make_shared<Renderer::Texture>("res/textures/girl.jpg");
    material->setTexture("MainTexture", texture);

    auto textureSecond = std::make_shared<Renderer::Texture>("res/textures/house.jpg");
    material->setTexture("SecondTexture", textureSecond);

    auto ambientColorProperty = std::make_shared<Renderer::PropertyVec4>(
        "ambientColor", 0.0f, 1.0f, 0.0f, 1.0f
    );
    material->setProperty(ambientColorProperty);
    ///// SET MATERIAL FINISH

    ////// INIT MODEL
    auto model = std::make_shared<Renderer::Model>();
    model->setGeometry(cubeGeom);
    model->setMaterial(material);
    model->setName(CUBE);
    model->setRenderMask(CAMERA_2_MASK);
    addModel(model);

    const auto camera = std::make_shared<Renderer::Camera>(45.0f,
                                                           (float) mWidth / (float) mHeight,
                                                           0.1f,
                                                           100.0f);
    camera->setPosition(glm::vec3(0.0f, 1.5f, 4.0f));
    camera->lookAt(glm::vec3(1.0f, 0.0f, 0.0f), // куди дивимось
                   glm::vec3(0.0f, 1.0f, 0.0f) // вектор вгору)
    );
    camera->setClearColor(1.0, 0.0, 0.0, 1.0);
    camera->setClearColorBufferEnabled(true);
    camera->setClearDepthBufferEnabled(true);
    camera->setDepthTestEnabled(true);
    camera->setRenderMask(CAMERA_1_MASK);
    camera->setDrawOrder(1);
    addCamera(camera);

    const auto camera2 = std::make_shared<Renderer::Camera>(45.0f,
                                                           (float) mWidth / (float) mHeight,
                                                           0.1f,
                                                           100.0f);
    camera2->setPosition(glm::vec3(0.0f, 1.5f, 4.0f));
    camera2->lookAt(glm::vec3(-1.0f, 0.0f, 0.0f), // куди дивимось
                   glm::vec3(0.0f, 1.0f, 0.0f) // вектор вгору)
    );
    camera2->setClearColor(0.0, 1.0, 0.0, 1.0);
    camera2->setClearColorBufferEnabled(false);
    camera2->setClearDepthBufferEnabled(false);
    camera2->setDepthTestEnabled(true);
    camera2->setRenderMask(CAMERA_2_MASK);
    camera2->setDrawOrder(10);
    addCamera(camera2);
}

void Scene::onPreRenderScene() {
    SceneBase::onPreRenderScene();

    auto model = getModel(CUBE);
    auto modelMat = model->getTransformation();
    modelMat = glm::rotate(modelMat, glm::radians(5.0f) / 10, glm::vec3(0.0f, 1.0f, 0.0f));
    model->setTransformation(modelMat);
}

void Scene::onRenderScene(const std::shared_ptr<Renderer::Camera> &camera) {
    SceneBase::onRenderScene(camera);
}

void Scene::onPostRenderScene() {
    SceneBase::onPostRenderScene();
}
