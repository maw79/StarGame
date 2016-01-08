cmake_minimum_required(VERSION 3.3)
project(OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glut
        GL
        GLU
        m)

set(SOURCE_FILES
        main.cpp
        player.cpp
        player.h
        Stars.cpp
        Stars.h)

add_executable(OpenGL ${SOURCE_FILES})

target_link_libraries(OpenGL ${ALL_LIBS})
