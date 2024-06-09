cmake_minimum_required(VERSION 3.27)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_PATH "C:\\SDL2-2.30.3\\x86_64-w64-mingw32")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

add_link_options("-Wall")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

file(GLOB_RECURSE SOURCE source/*.cpp)

add_executable(SpaceInvaders ${SOURCE})

target_link_libraries(SpaceInvaders ${SDL2_LIBRARY})
