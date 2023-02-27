cmake_minimum_required(VERSION 3.14)

project(Huffman)

file(GLOB SRC src/*.cpp)

add_executable(Huffman ${SRC})
