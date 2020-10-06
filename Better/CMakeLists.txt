cmake_minimum_required(VERSION 3.17)
project(before)

set(CMAKE_CXX_STANDARD 20)

add_executable(before main.cpp cmake-build-debug/main.cpp cmake-build-debug/Course.cpp cmake-build-debug/Course.h cmake-build-debug/Student.cpp cmake-build-debug/Student.h)