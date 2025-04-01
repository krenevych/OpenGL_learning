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

# lesson 01
add_executable(lesson01
        src/lesson01/main.cpp
)
target_link_libraries(lesson01 ${ALL_LIBS})

# lesson 02
add_executable(lesson02
        src/lesson02/main.cpp
        src/lesson02/utils.cpp
        src/lesson02/utils.h
)
target_link_libraries(lesson02 ${ALL_LIBS})

