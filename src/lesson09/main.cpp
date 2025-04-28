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

    GLuint shaderProgram = createProgram(
        "res/shaders/rect.vert",
        "res/shaders/rect.frag"
    );

    // позиції вершин та кольори
    float vertices[] = {
        // -------- Передня грань (червона) --------
        0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 0.0,  // лівий нижній
        1.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 0.0,  // правий нижній
        1.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 1.0,  // правий верхній
        0.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 1.0,  // лівий верхній

       // -------- Задня грань (зелена) --------
        0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 0.0,
        1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 1.0,

       // -------- Ліва грань (синя) --------
        0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 0.0,
        0.0f, 1.0f, 0.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 0.0,
        0.0f, 1.0f, 1.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 1.0,
        0.0f, 0.0f, 1.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 1.0,

       // -------- Права грань (жовта) --------
        1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 1.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 1.0,

       // -------- Нижня грань (бірюзова) --------
        0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 0.0, 0.0,
        0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 1.0, 0.0,
        1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 0.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 0.0, 1.0,

       // -------- Верхня грань (фіолетова) --------
        0.0f, 1.0f, 0.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 0.0, 1.0,
   };

    unsigned int indices[] = {
        0, 1, 2,  2, 3, 0,       // передня
        4, 5, 6,  6, 7, 4,       // задня
        8, 9,10, 10,11, 8,       // ліва
       12,13,14, 14,15,12,       // права
       16,17,18, 18,19,16,       // нижня
       20,21,22, 22,23,20        // верхня
    };


    auto cubeGeom = Renderer::Geometry();
    cubeGeom.setVertices({
        // -------- Передня грань (червона) --------
        0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 0.0,  // лівий нижній
        1.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 0.0,  // правий нижній
        1.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 1.0, 1.0,  // правий верхній
        0.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f, /* текстурні координати */ 0.0, 1.0,  // лівий верхній

       // -------- Задня грань (зелена) --------
        0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 0.0,
        1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f,   0.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 1.0,

       // -------- Ліва грань (синя) --------
        0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 0.0,
        0.0f, 1.0f, 0.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 0.0,
        0.0f, 1.0f, 1.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 1.0, 1.0,
        0.0f, 0.0f, 1.0f,   0.0f, 0.0f, 1.0f,/* текстурні координати */ 0.0, 1.0,

       // -------- Права грань (жовта) --------
        1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 1.0f,   1.0f, 1.0f, 0.0f,   /* текстурні координати */ 0.0, 1.0,

       // -------- Нижня грань (бірюзова) --------
        0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 0.0, 0.0,
        0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 1.0, 0.0,
        1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 1.0, 1.0,
        1.0f, 0.0f, 0.0f,   0.0f, 1.0f, 1.0f,   /* текстурні координати */ 0.0, 1.0,

       // -------- Верхня грань (фіолетова) --------
        0.0f, 1.0f, 0.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 0.0, 0.0,
        1.0f, 1.0f, 0.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 1.0, 0.0,
        1.0f, 1.0f, 1.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 1.0, 1.0,
        0.0f, 1.0f, 1.0f,   1.0f, 0.0f, 1.0f,    /* текстурні координати */ 0.0, 1.0,
   });

    cubeGeom.addAttribute("aPos", 3, 0, 0);
    cubeGeom.addAttribute("aColor", 3, 3, 1);
    cubeGeom.addAttribute("aTex", 2, 6, 2);

    cubeGeom.setIndices({
        0, 1, 2,  2, 3, 0,       // передня
        4, 5, 6,  6, 7, 4,       // задня
        8, 9,10, 10,11, 8,       // ліва
       12,13,14, 14,15,12,       // права
       16,17,18, 18,19,16,       // нижня
       20,21,22, 22,23,20        // верхня
    });

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
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0, // location - 0
        3, // 3 компоненти: x, y, z
        GL_FLOAT, // тип даних
        GL_FALSE, // не нормалізувати
        8 * sizeof(float), // stride: 5 float-а на вершину
        (void *) 0 // offset: починаємо з 0
    );
    // enables location 0

    // Кольори вершини → location = 1 в шейдері
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
        1, // location - 1
        3, // 3 компоненти: r, g, b
        GL_FLOAT, // тип даних
        GL_FALSE, // не нормалізувати
        8 * sizeof(float), // stride: 5 float-а на вершину
        (void *) (sizeof(float) * 3) // offset: починаємо з 2
    );
    // enables location 1

    // Текстурні координати → location = 2 в шейдері
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(
        2, // location - 2
        2, // 3 компоненти: r, g, b
        GL_FLOAT, // тип даних
        GL_FALSE, // не нормалізувати
        8 * sizeof(float), // stride: 5 float-а на вершину
        (void *) (sizeof(float) * 6) // offset: починаємо з 5
    );
    // enables location 1

    // Indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    auto texture0_loc = glGetUniformLocation(shaderProgram, "MainTexture");

    unsigned int texture0_id = loadTexture("res/textures/girl.jpg");

    float t = 0;
    float deltaT = 0.01f;

    auto modelLoc = glGetUniformLocation(shaderProgram, "Model");
    auto viewLoc = glGetUniformLocation(shaderProgram, "View");
    auto projectionLoc = glGetUniformLocation(shaderProgram, "Projection");
    auto model = glm::mat4(1.0f);

    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 1.5f, 4.0f), // позиція камери
        glm::vec3(0.0f, 0.0f, 0.0f), // куди дивимось
        glm::vec3(0.0f, 1.0f, 0.0f) // вектор вгору
    );


    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        (float)width / (float)height,
        0.1f,
        100.0f
    );

    glEnable(GL_DEPTH_TEST);

    /* Loop until the user closes the window */
    do {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Rendering - gl*-function calls
        glUseProgram(shaderProgram);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture0_id);
        glUniform1i(texture0_loc, 0);

        // t = glfwGetTime();
        if (t > 1.0f || t < 0.0f) {
            deltaT = -deltaT;
        }

        t += deltaT;

        model = glm::rotate(model, glm::radians(5.0f) / 10, glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (float*)(&view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, (float*)(&projection));

        // glBindVertexArray(VAO);
        //
        // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, nullptr);
        // glBindVertexArray(0); // VAO deactivation

        cubeGeom.bind();
        cubeGeom.draw();
        cubeGeom.unbind();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window) &&
             glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);

    // очистка ресурсів з відеокарти
    glDeleteBuffers(1, &vert_buffer);
    glDeleteBuffers(1, &index_buffer);
    glDeleteTextures(1, &texture0_id);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);


    glfwTerminate();
    return 0;
}
