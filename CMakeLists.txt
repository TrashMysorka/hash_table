cmake_minimum_required(VERSION 3.17)
project(hash_table)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_table main.cpp hash_table.cpp)
add_library(hash STATIC hash_table.cpp hash_table.h)