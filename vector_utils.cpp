/*
 * Module implementing vector_utils.h
 *
 * Created by loona on 14/06/22.

*/

#include "vector_utils.h"
#include <stdexcept>
#include <cmath>

float vtr::dotProd(Vector u, Vector v){
    /*
     * Calculates the dot product of 2 vectors.
     *
     * both vectors must be the same size.
     * if so, multiply the components of each by eachother
     *
     * Ex:
     * u = {1,2,3}
     * v = {7,8,9}
     * >>> u1*v1 + u2*v2 + u3*v3 = 1*7 + 2*8 + 3*9
     * */
    if (u.size() != v.size())
        throw::std::invalid_argument("Vectors must be the same size.");

    // for every element in u and v, add them to the return value
    float dotProd;
    for (int i=0; i< u.size(); i++)
        dotProd += u[i] * v[i];
    return dotProd;
}

float vtr::norm(Vector u){
    /*
     * Calculates the norm of a vector.
     *
     * The norm is also the magnitude.
     *
     * Calculated by taking the sqrt of the sum of all elements squared.
     *
     * Ex:
     * u = {2,2,2}
     * >>> sqrt(2**2 + 2**2 + 2**2)
     * */
    float sum; // calculates the sum of all squares
    for (auto i : u)
        sum += i*i;

    return sqrt(sum); // returns the square root
}

bool vtr::isUnitVector(Vector u){
    /*
     * A vector is a unit vector if it's norm ==1
     * */
    return (norm(u) == 1);
}

Vector vtr::zeroVector(int dim){
    /*
     * technically, since vectors elements default to 0
     * we can just return an empty vector.
     * */
    return std::vector<int> zeroVector;
}

Vector vtr::add(Vector u, Vector v){
    /*
     * Adds 2 vectors.
     *
     * The 2 vectors must be the same size.
     *
     * if so, adds each of the 2nd vector's elements to the 1st.
     * then returns the 1st vector
     * */
    if (u.size() != v.size())
        throw::std::invalid_argument("Vectors must be the same size.");

    for (int i=0; i<u.size(); i++)
        u[i] += v[i];
    return u;
}

Vector vtr::scalarMult(Vector u, float k){
    /*
     * Scalar multiplication.
     *
     * Multiplies every element ofa vector by a constant.
     * */
    for (int i=0; i<u.size();i++)
        u[i] *= k;
    return u;
}

