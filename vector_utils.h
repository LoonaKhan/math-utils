/*
 * Vector utilities.
 *
 * Created by loona on 14/06/22.
*/

#ifndef MATRIX_MATH_VECTOR_UTILS_H
#define MATRIX_MATH_VECTOR_UTILS_H
#include <vector>

namespace vtr {

    // dot product
    float dotProd(std::vector<float> u, std::vector<float> v);

    // cross product
    std::vector<float> crossProd(std::vector<float> u, std::vector<float> v);

}

#endif //MATRIX_MATH_VECTOR_UTILS_H
