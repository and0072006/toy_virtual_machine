cmake_minimum_required(VERSION 2.8)
project(util)

set(SOURCE_LIB Util.cpp)

add_library(util STATIC ${SOURCE_LIB})

target_include_directories(util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
