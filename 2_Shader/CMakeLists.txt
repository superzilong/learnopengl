cmake_minimum_required(VERSION 3.0.0)
project(TestGL)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(glfw3)
find_package(GLEW)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TestGL main.cpp)
target_link_libraries(TestGL GLEW::GLEW)
target_link_libraries(TestGL glfw::glfw)
