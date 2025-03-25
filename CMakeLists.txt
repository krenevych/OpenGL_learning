cmake_minimum_required(VERSION 3.30)
project(OpenGL_learning)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
)

add_subdirectory(external)

add_executable(OpenGL_learning src/main.cpp)
target_link_libraries(OpenGL_learning ${ALL_LIBS})

