cmake_minimum_required(VERSION 3.0)
project(2dgame)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(src)
include_directories(lib/lua)

add_subdirectory(lib/glm)
add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

