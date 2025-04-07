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
        "res/shaders/triangle.vert",
        "res/shaders/triangle.frag"
    );

    GLuint locationPosAttribs = glGetAttribLocation(shaderProgram, "aPos");

    // позиції вершин
    float verticesPositions[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f,
    };



    GLuint pos_buffer; // data
    GLuint color_buffer; // data
    GLuint VAO; // vertex array object

    glGenBuffers(1, &pos_buffer);
    glGenBuffers(1, &color_buffer);

    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    // POSITIONS
    glBindBuffer(GL_ARRAY_BUFFER, pos_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPositions), verticesPositions, GL_STATIC_DRAW);

    // Позиція вершини → location = 0 в шейдері
    glVertexAttribPointer(
        0,                  // location - 0
        2,                  // 2 компоненти: x, y
        GL_FLOAT,           // тип даних
        GL_FALSE,           // не нормалізувати
        2 * sizeof(float),  // stride: 2 float-а на вершину
        (void*)0            // offset: починаємо з 0
    );
    glEnableVertexAttribArray(0); // enables location 0


    // COLORS
    float verticesColors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
    };
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesColors), verticesColors, GL_STATIC_DRAW);

    // Позиція вершини → location = 1 в шейдері
    glVertexAttribPointer(
        1,                  // location - 1
        3,                  // 2 компоненти: x, y
        GL_FLOAT,           // тип даних
        GL_FALSE,           // не нормалізувати
        3 * sizeof(float),  // stride: 2 float-а на вершину
        (void*)0            // offset: починаємо з 0
    );
    glEnableVertexAttribArray(1);

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

    glDeleteBuffers(1, &pos_buffer);
    glDeleteBuffers(1, &color_buffer);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);


    // очистка ресурсів з відеокарти

    glfwTerminate();
    return 0;
}
