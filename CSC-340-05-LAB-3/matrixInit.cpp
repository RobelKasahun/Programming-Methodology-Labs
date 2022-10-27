#include "matrixInit.h"
#include<vector>
//implement your matrixInit() function here.

void NS_MATRIX::matrixInit(std::vector<std::vector<int>>& matrix, int rows, int cols) {
   matrix.resize(rows);   
   for(int row = 0; row < rows; row++){
      matrix[row] = std::vector<int>(cols, 0);
      for(int col = 0; col < cols; col++){
         matrix[row][col] = (row * col);
      }
   }
}