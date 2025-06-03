#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Scene.h"
#include "SceneBase.h"

int main(void) {
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // для macOS


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

    const auto scene = std::make_shared<Scene>(width, height);
    scene->onSceneInit();

    /* Loop until the user closes the window */
    do {
        scene->render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window) &&
             glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);

    glfwTerminate();
    return 0;
}
