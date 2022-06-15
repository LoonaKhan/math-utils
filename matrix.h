/*
 * Matrix mathematics module.
 *
 * Contains the Matrix type and basic functionality.
 *
 * Created by loona on 14/06/22.
*/

#ifndef MATRIX_MATH_MATRIX_H
#define MATRIX_MATH_MATRIX_H
#include <vector>

namespace mtx {

    struct Matrix { // the matrix struct.

        // the actual matrix itself.
        // we use floats instead of ints
        // this is because REF/RREF can sometimes involve floats
        std::vector<std::vector<float>> matrix;

        Matrix(std::vector<std::vector<float>> matrix);

        int rows(); // getter for rows

        int cols(); // getter for cols



    private:
        // the num_rows and columns
        int num_rows;
        int num_cols;
    };

    // addition
    Matrix add(Matrix u, Matrix v);

    // scalar multiplication
    Matrix scalarMult(Matrix u, float k);

    // determinant
    float determinant();

    // is triangular?
    bool isTriangular(Matrix u);

    // is diagonal
    bool isDiagonal(Matrix u);

    // is elementary?
    bool isElementary(Matrix u);

    // returns the 0 vector given a size
    Matrix zeroMatrix(int rows, int cols);

    // returns the identity matrix of a given size
    Matrix identityMatrix(int row, int cols);

    // REF
    Matrix gaussianElimination(Matrix u);

    // RREF
    Matrix gaussJordanElimination(Matrix u);

    // Transpose
    Matrix transpose(Matrix u);

    // Inverse
    Matrix inverse(Matrix u);

    // Print Matrix
    void print(Matrix u);

}



#endif //MATRIX_MATH_MATRIX_H
