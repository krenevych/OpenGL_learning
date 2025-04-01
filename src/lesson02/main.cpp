#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "utils.h"


int main(void)
{

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // для macOS


    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glClearColor(1.0, 1.0, 1.0, 1.0);



    GLuint shaderProgram = createProgram(
        "triangle.vert",
        "triangle.frag");

    GLuint locationPosAttribs = glGetAttribLocation(shaderProgram, "aPos");



    float vertices[] = {
        -0.5f, -0.5f, 0.f, 0.5f, -0.5f, 0.f, 0.0f, 0.5f, 0.f,
    };

    GLuint VBO; // data
    GLuint VAO; // vertex array object

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Позиція вершини → location = 0 в шейдері
    glVertexAttribPointer(
        // 0,               // location - 0
        locationPosAttribs,                  // location - found directly
        3,                  // 3 компоненти: x, y, z
        GL_FLOAT,           // тип даних
        GL_FALSE,           // не нормалізувати
        3 * sizeof(float),  // stride: 3 float-а на вершину
        (void*)0            // offset: починаємо з 0
    );
    // glEnableVertexAttribArray(0); // enables location 0
    glEnableVertexAttribArray(locationPosAttribs);
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    do {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Rendering - gl*-function calls
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0); // VAO deactivation

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window) &&
        glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);


    // очистка ресурсів з відеокарти

    glfwTerminate();
    return 0;
}
