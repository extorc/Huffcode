cmake_minimum_required(VERSION 3.14)

project(Huffman)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC src/*.cpp)

add_executable(Huffman ${SRC})
