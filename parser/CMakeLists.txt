cmake_minimum_required(VERSION 2.8)
project(parser)

set(SOURCE_LIB InstructionParser.cpp InstructionDetector.cpp)

add_library(parser STATIC ${SOURCE_LIB})

target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(parser PRIVATE util)

