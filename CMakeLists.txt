cmake_minimum_required(VERSION 2.8)
project(toy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wconversion -Wshadow -Wno-unused-parameter -Wno-unused-function -Wno-missing-field-initializers -Wno-ignored-qualifiers -Werror -Wno-conversion -O0 -Wnon-virtual-dtor -Woverloaded-virtual -Wno-aggressive-loop-optimizations -std=gnu++1z")

set(SOURCE_EXE main.cpp)




add_executable(toy ${SOURCE_EXE})

add_subdirectory(core)
add_subdirectory(conf)
add_subdirectory(util)
add_subdirectory(log)
add_subdirectory(parser)

target_include_directories(toy PRIVATE core )
target_link_libraries(toy PRIVATE core)
