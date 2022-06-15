/*
 * Module implementing matrix.h
 *
 * Created by loona on 14/06/22.
*/

#include "matrix.h"
#include <iostream>

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




mtx::Matrix mtx::zeroMatrix(const int rows, const int cols) {
    /*
     * Generates a matrix of 0's based on the sizes given.
     *
     * num_rows being the # of num_rows and num_cols the num_cols
     *
     * Ex: num_rows x num_cols where num_rows=3, num_cols=2
     *  num_rows=3
     *  num_cols=2
     *  [
     *      [0   0]
     *      [0   0]
     *      [0   0]
     *  ]
     *  a matrix containing *num_rows* vectors each with *num_cols* elements
     * */

    std::vector<std::vector<float>> zeroMatrix;

    for (int r=0; r<rows; r++){
        zeroMatrix.emplace_back();
        for (int c=0; c<cols; c++)
            zeroMatrix[r].push_back(0);
    }

    return {zeroMatrix};

}

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
