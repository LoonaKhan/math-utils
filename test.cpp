/*
 * Testing module for the matrix library.
 *
 * Created by loona on 14/06/22.
 *
 * TODO:
 *  make seperate methods for all the tests
 *
 * TODO:
 *  organize shit into a
*/

#include "matrix.h"
#include "vector_utils.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){

    // tests the zero vector
    mtx::Matrix zeroMatrix = mtx::zeroMatrix(3,3);

    //cout << zeroMatrix.num_rows <<endl;

    mtx::print(zeroMatrix);


    // testing different sized matrices
    mtx::Matrix m = mtx::Matrix({
        {1,0},
        {0,1,0},
        {0,0}
    });

    mtx::print(m);

    std::cout << m.matrix[0][4] << std::endl;

}