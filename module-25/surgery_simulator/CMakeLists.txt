cmake_minimum_required(VERSION 3.15)
project(SurgerySimulator VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(surgery_simulator
    src/main.cpp
    src/surgery.cpp
)

target_include_directories(surgery_simulator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
