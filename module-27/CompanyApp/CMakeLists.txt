cmake_minimum_required(VERSION 3.15)
project(CompanyApp LANGUAGES CXX)

set(CMAKE_CXX_STANARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(CompanyApp
    src/main.cpp 
    src/Company.cpp
)