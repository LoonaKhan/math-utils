# matrix-math
 some basic Linear Algebra utilities. 
 This is mostly used so I can personally understand Linear Algebra better and computation of basic things.
 I dont plan to include more complex topics such as vector spaces at the moment, 
 but if I can think of how to program it, I might eventually add such features.

This can also be used for general usage. 
It does use the vector library, and I believe there is a Matrix() function in C++ rendering this obsolete,
However, it is a personal/school endeavour, so i shall do it anyway.

The docs will take some time to complete, but here is what works so far.
 

## Basic usage:

#### Include
Just include the header files:
```cpp
#include "matrix.h" // for Matrices
#include "vector_utils.h" // for the vector utilities
```

#### Matrix type
Every matrix Has these properties:
- matrix ``vector<vector<float>>``
- rows ``int``
- cols ``int``

To get the rows and collumns, we must use their getters; rows() and cols().

Example:
```cpp
mtx::Matrix m = mtx::Matrix({
    {1,0,0},
    {0,1,0},
    {0,0,1}
});

int rows = m.rows();
int cols = m.cols()
```
Pass in the matrix upon initialization. 

Every row matrix must be the same size. If you fail to do so, it will just use the size of the first row vector as the column size.

Example:
```cpp
mtx::Matrix m1 = mtx::Matrix({ // shorter rows will be filled with 0's
    {1,1,1},
    {1,1},
});
/*
 * m1 = [
 *  [1,1,1],
 *  [1,1,0]
 * ]
 */

mtx::Matrix m2 mtx::Matrix({ // longer rows will be cut off
    {1,1},
    {1,1,1}
})
/*
 * m2 = [
 *  [1,1],
 *  [1,1]
 * ]
 */
```

#### Printing
Call mtx::print()

Example:
```cpp
mtx::Matrix m = mtx::Matrix({
    {1,1,1},
    {1,1,1}
});
mtx::print(m);
/*
 * [
 *  [1,1,1],
 *  [1,1,1]
 * ] 
 */
```

#### Generate the zero Matrix
You can use mtx::zeroMatrix() and specify the dimensions.

args:
- rows: ``int``
- cols: ``int``

Usage:
```cpp
mtx::zeroMatrix(int rows, int cols);
```

Example:
```cpp
// generates a 2x3 matrix. 
// 2 rows, 3 columns 
mtx::Matrix zeroMatrix = mtx::zeroMatrix(2,3); 
```