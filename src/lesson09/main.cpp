#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "utils.h"
#include "texture.h"

#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Model.h"

int main(void) {
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // для macOS


    auto width = 1280;
    auto height = 720;
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *window = glfwCreateWindow(width, height, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSwapInterval(1);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    ///// SET GEOMETRY START
    auto cubeGeom = std::make_shared<Renderer::Geometry>();
    cubeGeom->setVertices({
        // -------- Передня грань (червона) --------
        0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 0.0, // лівий нижній
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 0.0, // правий нижній
        1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 1.0, // правий верхній
        0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 1.0, // лівий верхній

        // -------- Задня грань (зелена) --------
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 0.0,
        1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 1.0,

        // -------- Ліва грань (синя) --------
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 0.0,
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 0.0,
        0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 1.0,
        0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 1.0,

        // -------- Права грань (жовта) --------
        1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, /* текстурні координати */ 0.0, 1.0,

        // -------- Нижня грань (бірюзова) --------
        0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, /* текстурні координати */ 0.0, 0.0,
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, /* текстурні координати */ 0.0, 1.0,

        // -------- Верхня грань (фіолетова) --------
        0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, /* текстурні координати */ 0.0, 1.0,
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
    material->addTexture(texture);
    ///// SET MATERIAL FINISH

    ////// INIT MODEL
    auto model = std::make_shared<Renderer::Model>();
    model->setGeometry(cubeGeom);
    model->setMaterial(material);

    // FIXME: remove after material created
    const auto &shaderProgram = material->getShaderProgram();
    // auto texture0_loc = glGetUniformLocation(shaderProgram, "MainTexture");

    // unsigned int texture0_id = loadTexture("res/textures/girl.jpg");


    float t = 0;
    float deltaT = 0.01f;

    auto modelLoc = glGetUniformLocation(shaderProgram, "Model");
    auto viewLoc = glGetUniformLocation(shaderProgram, "View");
    auto projectionLoc = glGetUniformLocation(shaderProgram, "Projection");
    auto modelMat = glm::mat4(1.0f);

    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 1.5f, 4.0f), // позиція камери
        glm::vec3(0.0f, 0.0f, 0.0f), // куди дивимось
        glm::vec3(0.0f, 1.0f, 0.0f) // вектор вгору
    );


    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        (float) width / (float) height,
        0.1f,
        100.0f
    );

    glEnable(GL_DEPTH_TEST);

    /* Loop until the user closes the window */
    do {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Rendering - gl*-function calls

        model->bind();  // активація шейдерної програми

        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture0_id);
        // glUniform1i(texture0_loc, 0);

        // t = glfwGetTime();
        if (t > 1.0f || t < 0.0f) {
            deltaT = -deltaT;
        }

        t += deltaT;

        modelMat = glm::rotate(modelMat, glm::radians(5.0f) / 10, glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMat));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (float *) (&view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, (float *) (&projection));

        model->draw();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window) &&
             glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);

    // очистка ресурсів з відеокарти
    // glDeleteTextures(1, &texture0_id);

    glfwTerminate();
    return 0;
}
