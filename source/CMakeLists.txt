cmake_minimum_required(VERSION 3.12)

project(BlueMarble)

add_executable(BlueMarble main.cpp)

target_include_directories(BlueMarble PRIVATE deps/glm deps/stb deps/glfw/include deps/glew/include)

target_link_directories(BlueMarble PRIVATE deps/glfw/lib-vc2022 deps/glew/lib/Release/x64)

target_link_libraries(BlueMarble PRIVATE glfw3.lib glew32.lib)