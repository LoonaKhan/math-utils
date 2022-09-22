cmake_minimum_required(VERSION 3.22)
project(matrix-math)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix_Test src/lin_alg/tests/matrix_tests.cpp src/lin_alg/matrix.h src/lin_alg/matrix.cpp)
add_executable(Vector_Test src/lin_alg/tests/vector_utils_tests.cpp src/lin_alg/vector_utils.h src/lin_alg/vector_utils.cpp)
add_executable(Lines_Test src/lin_alg/tests/lines_tests.cpp src/lin_alg/lines.cpp src/lin_alg/lines.h)
add_executable(Planes_Test src/lin_alg/tests/planes_tests.cpp src/lin_alg/planes.h src/lin_alg/planes.cpp)