cmake_minimum_required(VERSION 2.8)
project(core)

set(SOURCE_LIB Toy.cpp)

add_library(core STATIC ${SOURCE_LIB})

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
