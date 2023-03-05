cmake_minimum_required(VERSION 2.8)
project(log)

set(SOURCE_LIB FileLogger.cpp Logger.cpp)

add_library(log STATIC ${SOURCE_LIB})

target_include_directories(log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(log PRIVATE util)
