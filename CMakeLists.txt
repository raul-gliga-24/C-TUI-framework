cmake_minimum_required(VERSION 3.20)
project(tui_framework LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(tui_framework 
    src/main.cpp
    src/core/Label.cpp
    src/renderer/Buffer.hpp
    src/renderer/Buffer.cpp
    src/renderer/Renderer.cpp
    src/hal/Terminal.cpp
    src/hal/InputReader.cpp
    src/composite/Panel.cpp)
target_include_directories(tui_framework PRIVATE src)