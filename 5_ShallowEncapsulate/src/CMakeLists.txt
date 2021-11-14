cmake_minimum_required(VERSION 3.0.0)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(glfw3)
find_package(glad)
find_package(stb)
find_package(glm)

FILE(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
FILE(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(GEN ${sources} ${headers})

list(APPEND allFiles ${sources} ${headers})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${allFiles})

target_link_libraries(GEN glad::glad)
target_link_libraries(GEN glfw::glfw)
target_link_libraries(GEN glm::glm)
target_link_libraries(GEN stb::stb)