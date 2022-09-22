/*
 * Vector utilities.
 *
 * Created by loona on 14/06/22.
 *
 * TODO: figure out genStdVector
*/

#ifndef MATRIX_MATH_VECTOR_UTILS_H
#define MATRIX_MATH_VECTOR_UTILS_H

#define Vector std::vector<float> // to make it a smidge faster since its re-used everywhere

#include <vector>
#include "math.h"

namespace vtr {

    // addition of 2 vectors
    Vector add(Vector u, Vector v);

    // scalar multiplication
    Vector scalarMult(Vector u, float k);

    // dot product
    float dotProd(Vector u, Vector v);

    // cross product
    Vector crossProd(Vector u, Vector v);

    // norm/magnitude of a Vector
    double norm(Vector u);

    // angle between 2 vectors in degrees
    float angle(Vector u, Vector v);

    // checks if 2 vectors are perpindicular
    bool isPerpindicular(Vector u, Vector v);

    // checks if 2 vectors are parallel
    bool isParallel(Vector u, Vector v);

    // projection vector of one vector onto another
    Vector proj(Vector u, Vector v);

    // orthagonal projection of one vector onto another
    Vector orthagProj(Vector u, Vector v);

    // find slope of a vector between 2 coordinates
    float slope(Vector p1, Vector p2);

    // checks if the vector is a unit vector
    bool isUnitVector(Vector u);

    //
    Vector stdUnitVector();

    // generates a 0 vector based on the dimensions given
    Vector zeroVector(int dim);

    void printVector(Vector u);

}

#endif //MATRIX_MATH_VECTOR_UTILS_H
