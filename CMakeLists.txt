cmake_minimum_required(VERSION 3.22)
project(matrix-math)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test test.cpp matrix.h matrix.cpp vector_utils.cpp vector_utils.h)