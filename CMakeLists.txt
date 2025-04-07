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

set(UTILS_DIR src/utils)
file(GLOB_RECURSE
        UTILS
        ${UTILS_DIR}/*.cpp
        ${UTILS_DIR}/*.h
)

#MESSAGE("=========" ${UTILS})

# lesson 01
set(LESSON_TARGET lesson01)
set(LESSON_DIR src/${LESSON_TARGET})
file(GLOB_RECURSE LESSON_SRC
    ${LESSON_DIR}/*.cpp
    ${LESSON_DIR}/*.h
)

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
)
target_link_libraries(${LESSON_TARGET} ${ALL_LIBS})

########## lesson 02 #########
set(LESSON_TARGET lesson02)
set(LESSON_DIR src/${LESSON_TARGET})
file(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS}
)
target_link_libraries(${LESSON_TARGET} ${ALL_LIBS})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)

######### lesson 03 #########
set(LESSON_TARGET lesson03)
set(LESSON_DIR src/${LESSON_TARGET})
file(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS}
)
target_link_libraries(${LESSON_TARGET} ${ALL_LIBS})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)

######### lesson 04 #########
set(LESSON_TARGET lesson04)
set(LESSON_DIR src/${LESSON_TARGET})
file(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS}
)
target_link_libraries(${LESSON_TARGET} ${ALL_LIBS})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)

######### lesson 05 #########
set(LESSON_TARGET lesson05)
set(LESSON_DIR src/${LESSON_TARGET})
file(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS}
)
target_link_libraries(${LESSON_TARGET} ${ALL_LIBS})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)
