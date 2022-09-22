/*
 * Testing module for the matrix library.
 *
 * Created by loona on 15/06/22.
 *
 * TODO: also check that these fulfill the properties of vectors in ur textbook.
*/

#include "../vector_utils.h"
#include <vector>
#include <iostream>

void vectorSize(){
    /*
     * C++ vectors dont cause errors when you access an index that does not exist.
     * While this may not seem like an issue, vectors must be the same size for some calculations.
     * if the user accesses an out of range index in a vector, is the size modified?
     *
     * Result: setting an index to a variable does not change the size. but pushing back will.
     *  Thus, we should only push_back()
     * */
    Vector v = {1,1,1}; // size of 3
    std::cout << "size: " << v.size() << std::endl;

    //this sets the 5th element to a number
    v.push_back(1); // uncomment to see if pushing back changes size
    v[3] = 1;       // uncomment to see if setting an index changes size
    std::cout << "element 3: " << v[3] << std::endl;

    std::cout << "size: " << v.size() << std::endl;
}

void dotProdTest(){
    /*
     * Tests the dot product.
     *
     * test scenarios:
     *  dot product = 0 (perpendicular)
     *  dot product is parallel
     *  0 vector
     *  U*V = V*U
     *  different sized matrices
     * */

    // perpendicular
    Vector u1 = {1, 2};
    Vector v1 = {2, -1};
    std::cout << "dot product of perpendicular test: " << vtr::dotProd(u1, v1) << std::endl;

    // parallel
    Vector u2 = {1,2};
    Vector v2 = {2,4};
    std::cout << "dot product of parallel test: " << vtr::dotProd(u2, v2) << std::endl;

    // 0 vector
    Vector u3 = {1,2};
    Vector zeroVector = {0,0};
    std::cout << "dot product of 0 vector test: " << vtr::dotProd(u3, zeroVector) << std::endl;

    // U*V = V*U
    Vector u5 = {2,2};
    Vector v5 = {3,3};
    std::cout << "dot product of V*U test: " << vtr::dotProd(v5, u5) << std::endl;
    std::cout << "dot product of U*V test: " << vtr::dotProd(u5, v5) << std::endl;

    // diff sized matrices
    Vector u4 = {1,2};
    Vector v4 = {1};
    std::cout << "dot product of diff sized test: " << vtr::dotProd(u4, v4) << std::endl;
}

void crossProdTest(){} // remember, uxv != vxu

void zeroVectorTest(){
    /*
     * Tests vtr::zeroVector()
     *
     * tests:
     *  dim = 0
     *  dim = 1
     *  dim = 2+
     *  dim = -1
     * */

    // dim 0
    vtr::printVector(vtr::zeroVector(0));

    // dim 1
    vtr::printVector(vtr::zeroVector(1));

    // dim 2+
    vtr::printVector(vtr::zeroVector(3));

    // dim -1
    vtr::printVector(vtr::zeroVector(-1));

}

void printTest(){
    /*
     * Tests printing of vectors.
     *
     * tests:
     *  0 elements
     *  1 element
     *  2+
     *  null
     * */

    // 0 elements
    Vector u1 = {};
    vtr::printVector(u1);

    // 1 element
    Vector u2 = {1};
    vtr::printVector(u2);

    // 2+ elements
    Vector u3 = {0,0,0};
    vtr::printVector(u3);

    // null
    Vector u4;
    vtr::printVector(u4);
}

void normTest(){
    /*
     * Tests the norm function.
     *
     * tests:
     *  zero vector
     *  empty vector
     *  unit vector
     * */

    // 0 vector
    Vector u1 = vtr::zeroVector(4);
    std::cout << "norm of 0 vector: " << vtr::norm(u1) << std::endl;

    // empty vector
    Vector u2;
    std::cout << "norm of empty vector: " << vtr::norm(u2) << std::endl;

    // negative values
    Vector u3 = {-2,-2};
    std::cout << "norm of negative values vector: " << vtr::norm(u3) << std::endl;

    // unit vector
    Vector u4 = {1,0};
    std::cout << "norm of a unit vector: " << vtr::norm(u4) << std::endl;
}

void isUnitVectorTest(){
    /*
     * Tests to see if vectors are unit vectors.
     *
     * tests:
     *  standard unit vector
     *  non-standard unit vecotr
     *  zero vector
     * */

    // standard unit vector
    Vector u = {1,0,0};
    std::cout << "norm of standard unit vector: " << vtr::norm(u) << std::endl;
    std::cout << vtr::isUnitVector(u) << std::endl;

    // non-standard unit vector
    Vector u2 = {0.707,0,0.707};
    std::cout << "norm of non-standard unit vector: " << vtr::norm(u2) << std::endl;
    std::cout << vtr::isUnitVector(u2) << std::endl;

    // zero vector
    Vector u3 = vtr::zeroVector(3);
    std::cout << "norm of zero vector: " << vtr::norm(u3) << std::endl;
    std::cout << vtr::isUnitVector(u3) << std::endl;

}

void addTest(){
    /*
     * Tests adding vectors.
     *
     * tests:
     *  same size
     *  zero vector
     *  U+V = V+U
     *  U+(-U)
     *  diff size
     * */

    // same size
    Vector u = {1,1};
    Vector v = {2,2};
    vtr::printVector(vtr::add(u,v));

    // zero vector
    Vector u2 = {1, 1};
    Vector v2 = vtr::zeroVector(2);
    vtr::printVector(vtr::add(u2, v2));

    // U*V = V*U
    Vector u3 = {1,1};
    Vector v3 = {2,2};
    vtr::printVector(vtr::add(u3, v3));
    vtr::printVector(vtr::add(v3, u3));

    // U+(-U) == zero vector
    Vector u5 = {1,1};
    Vector v5 = {-1,-1};
    vtr::printVector(vtr::add(u5, v5));

    // diff size
    Vector u4 = {1,1};
    Vector v4 = {1,1,1};
    vtr::printVector(vtr::add(u4, v4));
}

void scalarMultTest(){
    /*
     * Tests scalar multiplication.
     *
     * tests:
     *  k=0
     *  k=1
     *  k=-1
     *  k=5
     */
    Vector u = {1,1};

    // k=0
    int k=0;
    vtr::printVector(vtr::scalarMult(u, k));

    // k=1
    k=1;
    vtr::printVector(vtr::scalarMult(u, k));

    // k=-1
    k=-1;
    vtr::printVector(vtr::scalarMult(u, k));

    //k=5
    k=5;
    vtr::printVector(vtr::scalarMult(u, k));
}

int main(){ // uncomment one of the lines below to run tests
    //vectorSize();

    //printTest();

    //dotProdTest();

    //zeroVectorTest();

    //normTest();

    //isUnitVectorTest();

    //addTest();

    //scalarMultTest();
}
