cmake_minimum_required(VERSION 2.8)
project(conf)

set(SOURCE_LIB ConfigReader.cpp TxtConfigReader.cpp)

add_library(conf STATIC ${SOURCE_LIB})

target_include_directories(conf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(conf PRIVATE util)
target_link_libraries(conf PRIVATE core util)

