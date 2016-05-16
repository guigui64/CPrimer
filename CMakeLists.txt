cmake_minimum_required(VERSION 3.4)
project(CPrimer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Screen.h Window_mgr.h)
add_executable(CPrimer ${SOURCE_FILES})