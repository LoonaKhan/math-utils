/*
 * Module implementing vector_utils.h
 *
 * Created by loona on 14/06/22.

*/

#include <stdexcept>
#include <cmath>
#include <iostream>

#include "vector_utils.h"

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
    float dotProd = 0;
    for (int i=0; i< u.size(); i++)
        dotProd += u[i] * v[i];
    return dotProd;
}

std::vector<float> vtr::crossProd(std::vector<float> u, std::vector<float> v) {
    // need a mathematical way to represent the right hand rule
    // vtr::norm(u) * vtr::norm(v) * degrees(sin(vtr::angle(u,v)))
    // multiply that by the unit vector.
}

double vtr::norm(const Vector u){
    /*
     * Calculates the norm of a vector.
     *
     * The norm is also the magnitude.
     *
     * Calculated by taking the sqrt of the norm of all elements squared.
     *
     * Ex:
     * u = {2,2,2}
     * >>> sqrt(2**2 + 2**2 + 2**2)
     * */
    double norm = 0; // calculates the norm of all squares
    for (auto i : u)
        norm += i * i;

    return sqrt(norm); // returns the square root
}

float vtr::angle(std::vector<float> u, std::vector<float> v) {
    /*
     * finds the slope of each line
     * then we can use trigonometry to solve for the angle.
     *
     * where 1 line is the hypotenuse, the other is adjacent.
     * we can use: cos(theta) = a/h to solve for the angle
     *
     * rearranging for the angle, we get: theta = cos^-1(a/h)
     *
     * cos^-1 has a domain of [-1, 1], so the hypotenuse will always have a larger slope.
     *
     * todo: this is in radians atm. convert it to degrees.
     * */

    return acos((vtr::dotProd(u,v))/(vtr::norm(u)*vtr::norm(v)));


}

float vtr::slope(std::vector<float> p1, std::vector<float> p2) {
    return ((p2[1] - p1[1])/(p2[0] - p1[0]));
}

bool vtr::isUnitVector(Vector u){
    /*
     * A vector is a unit vector if it's norm ==1
     * */
    return (norm(std::move(u)) == 1);
}

Vector vtr::zeroVector(int dim){
    /*
     * returns the zero vector of a certain dimension.
     *
     * Technically, we can just return an empty vector since every accessed element will default to 0.
     * However, the size would not be correct.
     * Many of our calculations require vectors of the same size.
     * Thus, in order for our zero vector to have the appropriate size, we must use push_back()
     * */
    Vector zeroVector;

    // allocates the matrix with 0's
    for (int i=0; i< dim; i++)
        zeroVector.push_back(0);

    return zeroVector;
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

void vtr::printVector(std::vector<float> u) {
    /*
     * Prints out a vector.
     *
     * Useful.
     * */
    std::cout << "[";

    for (int i=0; i<u.size(); i++){
        std::cout << u[i];
        if (i != u.size()-1) // if it is not the last element, add a comma
            std::cout << ", ";
    }
    std::cout << "]" <<std::endl;
}
