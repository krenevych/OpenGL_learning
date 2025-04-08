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
        "res/shaders/rect.vert",
        "res/shaders/rect.frag"
    );

    // GLuint locationPosAttribs = glGetAttribLocation(shaderProgram, "aPos");
    // GLuint = unsigned int
    GLint locationAmbientColorUniform = glGetUniformLocation(shaderProgram, "ambientColor");

    // позиції вершин та кольори
    float vertices[] = {
        // перший трикутник
        /* позиції */ -0.5f, -0.5f,   /* кольори */ 1.0f, 0.0f, 0.0f,     // вершгина 0
        /* позиції */  0.5f, -0.5f,   /* кольори */ 0.0f, 1.0f, 0.0f,     // вершгина 1
        /* позиції */  0.5f,  0.5f,   /* кольори */ 0.0f, 0.0f, 1.0f,     // вершгина 2
        /* позиції */ -0.5f,  0.5f,   /* кольори */ 1.0f, 0.0f, 1.0f,     // вершгина 3
    };

    unsigned int indices[]{
        0, 1, 2, // перший трикутник
        0, 2, 3, // другий трикутник
    };

    GLuint vert_buffer, index_buffer; // data
    GLuint VAO; // vertex array object

    glGenBuffers(1, &vert_buffer);
    glGenBuffers(1, &index_buffer);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Vertices
    glBindBuffer(GL_ARRAY_BUFFER, vert_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Позиція вершини → location = 0 в шейдері
    glVertexAttribPointer(
        0,                  // location - 0
        2,                  // 2 компоненти: x, y
        GL_FLOAT,           // тип даних
        GL_FALSE,           // не нормалізувати
        5 * sizeof(float),  // stride: 5 float-а на вершину
        (void*)0           // offset: починаємо з 0
    );
    glEnableVertexAttribArray(0); // enables location 0

    // Кольори вершини → location = 1 в шейдері
    glVertexAttribPointer(
        1,                  // location - 1
        3,                  // 3 компоненти: r, g, b
        GL_FLOAT,           // тип даних
        GL_FALSE,           // не нормалізувати
        5 * sizeof(float),  // stride: 5 float-а на вершину
        (void*)(sizeof(float) * 2)            // offset: починаємо з 2
    );
    glEnableVertexAttribArray(1); // enables location 1

    // Indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    /* Loop until the user closes the window */
    do {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Rendering - gl*-function calls
        glUseProgram(shaderProgram);
        glUniform4f(locationAmbientColorUniform, 0.0f, 1.0f, 1.0f, 1.0f);
        glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0); // VAO deactivation

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window) &&
        glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);

    glDeleteBuffers(1, &vert_buffer);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);

    // очистка ресурсів з відеокарти

    glfwTerminate();
    return 0;
}
