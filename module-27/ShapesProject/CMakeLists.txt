cmake_minimum_required(VERSION 3.15)
project(ShapesProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ShapesProject
    src/main.cpp
    src/Shape.cpp
    src/Circle.cpp
    src/Square.cpp
    src/Triangle.cpp
    src/Rectangle.cpp
)