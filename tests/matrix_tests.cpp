/*
 * Testing module for the matrix library.
 *
 * Created by loona on 14/06/22.
*/

#include "../matrix.h"
#include <vector>
#include <iostream>

using namespace std;

void addTest(){
    // adds 2 matrices together, then prints the output

    mtx::Matrix v1 = mtx::Matrix({
        {1,1},
        {1,1}
    });
    mtx::Matrix v2 = mtx::Matrix({
                                         {-1,0},
                                         {0,-1}
    });

    mtx::print(mtx::add(v1, v2));
}

void scalarMultTest(){
    float k = 0;
    auto u = mtx::Matrix({
                                 {1,1},
                                 {1,1}
    });

    mtx::print(mtx::scalarMult(u, k));
}

void identityMatrixTest(){
    mtx::print(mtx::identityMatrix(2,3));
}

void zeroMatrixTest(){
    mtx::print(mtx::zeroMatrix(3,3));
}

void diffSizedMatrices(){
    // testing different sized matrices
    mtx::Matrix m = mtx::Matrix({
                                        {1,0},
                                        {0,1,0},
                                        {0,0}
                                });
    //mtx::print(m);
}

int main(){
    // The tests for matrix methods.
    // uncomment any line below to test a method

    //zeroMatrixTest();

    //addTest();

    //scalarMultTest();

    //identityMatrixTest();

}