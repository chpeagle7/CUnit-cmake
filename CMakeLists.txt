cmake_minimum_required(VERSION 3.17)
project(CTest C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(cunit)

include_directories(cunit/Headers)

add_executable(CTest main.c)

target_link_libraries(CTest cunit)