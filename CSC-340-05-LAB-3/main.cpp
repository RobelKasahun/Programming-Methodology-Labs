//call your unit tests in this program file
#include<iostream>
#include "matrixInit.h"
#include "unitTests.h"
#include "tokenFreq.h"
#include<vector>
#include<string>

int main() {
    std::cout << std::boolalpha;
    std::vector<std::vector<int>> matrix{
       {0, 0, 0, 0},
       {0, 0, 0, 0},
       {0, 0, 0, 0}
    };
   
   int rows = 3;
   int cols = 4;
   
   // std::vector<std::vector<int>> matrix(rows);

    
    NS_MATRIX::matrixInit(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
            // std::cout << "matrix[" << i << "][" << j << "]: " << matrix.at(i).at(j) << std::endl;
            std::cout << matrix.at(i).at(j) << " ";
       }
       std::cout << "\n";
    }

   //  std::cout << "Expected result: true: Actual result: " << NS_UNIT_TESTS::test1_matrixInit() << "\n";
   //  std::cout << "Expected result: false: Actual result: " << NS_UNIT_TESTS::test2_matrixInit() << "\n";
   //  std::cout << "Expected result: false: Actual result: " << NS_UNIT_TESTS::test3_matrixInit() << "\n";

   //  NS_TOKEN_FREQ::TokenFreq freq_1;
   //  freq_1.token = "Hello, World!";
   //  freq_1.freq = 5;

   //  NS_TOKEN_FREQ::TokenFreq freq_2;
   //  freq_2.token = "Java";
   //  freq_2.freq = 10;

   //  NS_TOKEN_FREQ::TokenFreq freq_3 = (freq_1 + freq_2);
   //  std::cout << "three: token: " << freq_3.token << std::endl;
   //  std::cout << "three: freq: " << freq_3.freq << std::endl;
    
   //  std::cout << "\n";
    
   //  std::cout << freq_3;
    
   //  std::cout << "\n";
    
   //  if(freq_1 <= freq_2){
   //     std::cout << "freq_1 is <= freq_2" << std::endl;
   //  }else {
   //     std::cout << "freq_2 is <= freq_1" << std::endl;
   //  }
    
   //  std::cout << "\n";
    
    std::string istring = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
    std::vector<NS_TOKEN_FREQ::TokenFreq> tfVec;
    getTokenFreqVec(istring, tfVec);
   
   
    
   //  std::cout << "\n";
    
   //  std::cout << "Expected result true: Actual result: " << NS_UNIT_TESTS::test1_operatorLE() << std::endl;
   //  std::cout << "Expected result false: Actual result: " << NS_UNIT_TESTS::test2_operatorLE() << std::endl;
   //  std::cout << "Expected result true: Actual result: " << NS_UNIT_TESTS::test3_operatorLE() << std::endl;
   // std::cout << std::boolalpha;
   // std::cout << "test1_operatorLE(): " << NS_UNIT_TESTS::test1_operatorLE() << std::endl; // true
   // std::cout << "test2_operatorLE(): " << NS_UNIT_TESTS::test2_operatorLE() << std::endl; // false
   // std::cout << "test3_operatorLE(): " << NS_UNIT_TESTS::test3_operatorLE() << std::endl; // true
   
   // std::cout << "test1_matrixInit(): " << NS_UNIT_TESTS::test1_matrixInit() << std::endl;
   // std::cout << "test1_matrixInit(): " << NS_UNIT_TESTS::test2_matrixInit() << std::endl;
   // std::cout << "test1_matrixInit(): " << NS_UNIT_TESTS::test3_matrixInit() << std::endl;
   
   // NS_UNIT_TESTS::test1_matrixInit();
   
   std::cout << "\n";
   
   NS_TOKEN_FREQ::TokenFreq tf1{"word", 12};
   NS_TOKEN_FREQ::TokenFreq tf2{"bread", 5};
   NS_TOKEN_FREQ::TokenFreq tf3 = tf1 + tf2;
   std::cout << "token:" << tf3.token << "\nfreq: " << tf3.freq << std::endl;
   
    return 0;
}