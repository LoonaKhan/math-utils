cmake_minimum_required(VERSION 3.22)
project(matrix-math)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix_Test tests/matrix_tests.cpp matrix.h matrix.cpp)
add_executable(Vector_Test tests/vector_utils_tests.cpp vector_utils.h vector_utils.cpp)
add_executable(Lines_Test tests/lines_tests.cpp lines.cpp lines.h)
add_executable(Planes_Test tests/planes_tests.cpp planes.h planes.cpp)