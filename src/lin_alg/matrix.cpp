/*
 * Module implementing matrix.h
 *
 * Created by loona on 14/06/22.
 *
 * TODO: check that this uses push_back()
*/

#include "matrix.h"
#include <iostream>
#include <stdexcept>

mtx::Matrix::Matrix(std::vector<std::vector<float>> matrix) {
    /*
     * Initializes a matrix.
     *
     * All row vectors must be the same length; they have the same number of columns.
     * */

    this->num_rows = matrix.size();
    this->num_cols = matrix[0].size();
    this->matrix = std::move(matrix);

}

// getter and setter for num_rows
int mtx::Matrix::rows() {
    return this->num_rows;
}

// getter and setter for num_cols
int mtx::Matrix::cols() {
    return this->num_cols;
}



// addition
mtx::Matrix mtx::add(Matrix u, Matrix v) {
    /*
     * Adds 2 matrices.
     *
     * For scalar multiplication, we simply add the respective components together.
     * However, this also means both matrices must be the same size.
     *
     * Example: // this works as they are the same size; same # of rows and columns.
     *  u = { {1,1,1}, {1,1,1}, {1,1,1} } // 3x3
     *  v = { {1,1,1}, {1,1,1}, {1,1,1} } // 3x3
     *  return { {2,2,2}, {2,2,2}, {2,2,2} }
     *
     * Example: // here they are not the same size, so it does not work
     *  u = { {1,1,1}, {1,1,1}, {1,1,1} }
     *  v = { {1,1,1,1}, {1,1} }
     *
     * */
    if (u.rows() != v.rows() or u.cols() != v.cols())
        throw::std::invalid_argument("Matrices must be the same size");


    std::vector<std::vector<float>> sum; // creates our matrix

    for (int r=0; r<u.rows(); r++) {
        sum.emplace_back();
        for (int c = 0; c < u.cols(); c++)
            sum[r].push_back( // does the addition
                    u.matrix[r][c] + v.matrix[r][c]
                    );
    }

    return {sum};


}

// scalar multiplication
mtx::Matrix mtx::scalarMult(Matrix u, const float k) {
    /*
     * Scalar multiplication between a matrix and a constant
     *
     * Scalar multiplication works by multiplying all elements in a matrix by a constant.
     *
     * Example:
     *  k = 2
     *  u = { {1,1}, {1,1} }
     *  return { {2,2}, {2,2} }
     * */

    // multiplies all elements by k
    for (int r=0; r<u.rows(); r++)
        for (int c=0; c<u.cols(); c++)
            u.matrix[r][c] *= k;

    return u;
}

// generate the zero matrix
mtx::Matrix mtx::zeroMatrix(const int rows, const int cols) {
    /*
     * Generates a matrix of 0's based on the sizes given.
     *
     * rows being the # of rows and cols the columns
     *
     * Ex: rows x cols where rows=3, cols=2
     *  rows=3
     *  cols=2
     *  [
     *      [0   0]
     *      [0   0]
     *      [0   0]
     *  ]
     *  a matrix containing *rows* vectors each with *cols* elements
     * */

    std::vector<std::vector<float>> zeroMatrix;

    for (int r=0; r<rows; r++){
        zeroMatrix.emplace_back();
        for (int c=0; c<cols; c++)
            zeroMatrix[r].push_back(0);
    }

    return {zeroMatrix};

}

// generates an identity matrix
mtx::Matrix mtx::identityMatrix(int row, int cols) {
    /*
     * Generates the identity matrix given the dimensions.
     *
     * where rows are the number of rows and cols the number of columns.
     *
     * Ex:
     *  rows=3
     *  cols=3
     *  [
     *      [1,0,0],
     *      [0,1,0],
     *      [0,0,1]
     *  ]
     *
     * TODO: this has to be square
     * */

    std::vector<std::vector<float>> i; // our identity vector

    // adds all the elements
    for (int r=0; r<row; r++){
        i.emplace_back();

        for (int c=0; c<cols;c++){

            if (c == r) // if the index is one of the diagonals(col==row), then we place a 1
                i[r].push_back(1);

            else // place a 0 everywhere else
                i[r].push_back(0);

        }
    }

    return {i};
}

// print a matrix
void mtx::print(Matrix u) {
    /*
     * Prints a matrix out.
     *
     * Useful for debugging and stuff.
     * */

    // gets the rows n cols
    int rows = u.rows();
    int cols = u.cols();

    std::cout << "[" << std::endl;

    for (int r=0; r<rows; r++){ // for every row, print a opening bracket tabbed.
        std::cout << "  [";
        for (int c=0; c<cols; c++){ // for every column
            std::cout << u.matrix[r][c]; // print the value

            if (c == cols-1){ // if it is the last value in the column, add a closing bracket
                std::cout << "]";
                if (r != rows-1) // if it isnt the last row, add a comma
                    std::cout << ",";
                std::cout << std::endl; // move to the next line
            }
            else { // if it is not the last element in the column, add a comma
                std::cout << ", ";
            }
        }
    }

    std::cout << "]"<< std::endl;
}
