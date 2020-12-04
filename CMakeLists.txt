cmake_minimum_required(VERSION 3.0)
project(2dgame)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
#find_package(SDL2 REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(src)
include_directories(lib/lua)

add_subdirectory(lib/glm)
add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(googletest)

