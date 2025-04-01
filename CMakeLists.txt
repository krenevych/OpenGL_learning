cmake_minimum_required(VERSION 3.30)
project(OpenGL_learning)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        glad
        glm
)

add_subdirectory(external)

add_executable(lesson1 src/lesson01/main.cpp)
target_link_libraries(lesson1 ${ALL_LIBS})

