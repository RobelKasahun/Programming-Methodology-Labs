#ifndef _UNIT_TESTS_H_
#define _UNIT_TESTS_H_
#include "matrixInit.h"
#include "tokenFreq.h"
#include<vector>
//header file that includes all your unit tests as inline functions. 
//please include 3 unit tests for each of the following functions in the the namespace: NS_UNIT_TESTS
namespace NS_UNIT_TESTS {
    inline bool test1_matrixInit() {
        std::vector<std::vector<int>> dummy_matrix{
           {0, 0, 0, 0},
           {0, 1, 2, 3},
           {0, 2, 4, 6}
        };
        
       std::vector<std::vector<int>> matrix{
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
         };
        
        int ROWS = 3;
      //  std::vector<std::vector<int>> matrix(ROWS);
        int COLS = 4;
        NS_MATRIX::matrixInit(matrix, ROWS, COLS);

        // check whether the matrix and dummy_matrix are equal
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (matrix[i][j] != dummy_matrix[i][j] ) {
                    return false;
                    break;
                }
            }
        }

        return true;
    }

    inline bool test2_matrixInit() {
        std::vector<std::vector<int>> dummy_matrix{
           {0, 10, 0, 5},
           {0, 1, 5, 3},
           {0, 2, 4, 6}
        };

         std::vector<std::vector<int>> matrix{
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
         };
        int ROWS = 3;
      //  std::vector<std::vector<int>> matrix(ROWS);
        int COLS = 4;
        NS_MATRIX::matrixInit(matrix, ROWS, COLS);

        // check whether the matrix and dummy_matrix are equal
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (matrix[i][j]  != dummy_matrix[i][j]) {
                    return true;
                    break;
                }
            }
        }

        return true;
    }

    inline bool test3_matrixInit() {
        std::vector<std::vector<int>> dummy_matrix{
           {1, 4, 1, 0},
           {0, 1, 3, 3},
           {5, 2, 4, 6}
        };

         std::vector<std::vector<int>> matrix{
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
         };
        int ROWS = 3;
      //  std::vector<std::vector<int>> matrix(ROWS);
        int COLS = 4;
        NS_MATRIX::matrixInit(matrix, ROWS, COLS);

        // check whether the matrix and dummy_matrix are equal
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (matrix[i][j]  != dummy_matrix[i][j]) {
                    return true;
                    break;
                }
            }
        }

        return true;
    }

    // Unit tests for less than or equal to operator
    inline bool test1_operatorLE() {
        NS_TOKEN_FREQ::TokenFreq first{"word", 5};
        NS_TOKEN_FREQ::TokenFreq second{"mouth", 34};

        return (first <= second); // returns true
    }

    inline bool test2_operatorLE() {
        NS_TOKEN_FREQ::TokenFreq first{"java", 3};
        NS_TOKEN_FREQ::TokenFreq second{"python", 4};

        return (first <= second); // false
    }

    inline bool test3_operatorLE() {
        NS_TOKEN_FREQ::TokenFreq first{"Kaka", 11};
        NS_TOKEN_FREQ::TokenFreq second{"messie", 9};

        return (second <= first); // returns true
    }

    // Unit test for plus operator
    inline bool test1_operatorPlus() {
        NS_TOKEN_FREQ::TokenFreq token1{"word", 5};

        NS_TOKEN_FREQ::TokenFreq token2{"reality", 15};

        NS_TOKEN_FREQ::TokenFreq token3 = token1 + token2;

        return ((token3.token == "word or reality") && (token3.freq == 20)); // returns true
    }

    inline bool test2_operatorPlus() {
        NS_TOKEN_FREQ::TokenFreq token1{"five", 5};

        NS_TOKEN_FREQ::TokenFreq token2{"guys", 15};

        NS_TOKEN_FREQ::TokenFreq token3 = token1 + token2;

        return ((token3.token == "five or guys") && (token3.freq == 20));
    }

    inline bool test3_operatorPlus() {
        NS_TOKEN_FREQ::TokenFreq token1{"siz", 4};

        NS_TOKEN_FREQ::TokenFreq token2{"seven", 12};

        NS_TOKEN_FREQ::TokenFreq token3 = token1 + token2;

        return ((token3.token == "siz or seven") && (token3.freq == 16));
    }

    // Unit test for getTokenFreqVec()
    inline bool test1_getTokenFreqVec() {
        std::string istring = "I am working in c++ to become c++ software engineer, software is good in c++ become";
        std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
        NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);

        NS_TOKEN_FREQ::TokenFreq tf1{"i", 1};
        NS_TOKEN_FREQ::TokenFreq tf2{"am", 1};
        NS_TOKEN_FREQ::TokenFreq tf3{"working", 1};
        NS_TOKEN_FREQ::TokenFreq tf4{"in", 2};
        NS_TOKEN_FREQ::TokenFreq tf5{"c++", 3};
        NS_TOKEN_FREQ::TokenFreq tf6{"to", 1};
        NS_TOKEN_FREQ::TokenFreq tf7{"become", 2};
        NS_TOKEN_FREQ::TokenFreq tf8{"software", 2};
        NS_TOKEN_FREQ::TokenFreq tf9{"engineer,", 1};
        NS_TOKEN_FREQ::TokenFreq tf10{"is", 1};
        NS_TOKEN_FREQ::TokenFreq tf11{"good", 1};

        std::vector<NS_TOKEN_FREQ::TokenFreq> results{tf1, tf2, tf3, tf4, tf5, tf6, tf7, tf8, tf9, tf10, tf11};

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if ((tf[i].token != results[i].token) || (tf[i].freq != results[i].freq)) {
                return false;
                break;
            }
        }
        return true;
    } // return true because they are equal

    inline bool test2_getTokenFreqVec() {
        std::string istring = "I am working in c++ to become software engineer, software is good in c++ become";
        std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
        NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);

        NS_TOKEN_FREQ::TokenFreq tf1{"i", 1};
        NS_TOKEN_FREQ::TokenFreq tf2{"am", 1};
        NS_TOKEN_FREQ::TokenFreq tf3{"working", 1};
        NS_TOKEN_FREQ::TokenFreq tf4{"in", 2};
        NS_TOKEN_FREQ::TokenFreq tf5{"c++", 2};
        NS_TOKEN_FREQ::TokenFreq tf6{"to", 1};
        NS_TOKEN_FREQ::TokenFreq tf7{"become", 2};
        NS_TOKEN_FREQ::TokenFreq tf8{"software", 2};
        NS_TOKEN_FREQ::TokenFreq tf9{"engineer,", 1};
        NS_TOKEN_FREQ::TokenFreq tf10{"is", 1};
        NS_TOKEN_FREQ::TokenFreq tf11{"good", 1};

        std::vector<NS_TOKEN_FREQ::TokenFreq> results{tf1, tf2, tf3, tf4, tf5, tf6, tf7, tf8, tf9, tf10, tf11};

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if ((tf[i].token != results[i].token) || (tf[i].freq != results[i].freq)) {
                return false;
                break;
            }
        }
        return true;
    } // return false

    inline bool test3_getTokenFreqVec() {
        std::string istring = "I i am working i in c++ to i become software c++ engineer, c++ software c++ is good in c++ become";
        std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
        NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);

        NS_TOKEN_FREQ::TokenFreq tf1{"i", 4};
        NS_TOKEN_FREQ::TokenFreq tf2{"am", 1};
        NS_TOKEN_FREQ::TokenFreq tf3{"working", 1};
        NS_TOKEN_FREQ::TokenFreq tf4{"in", 2};
        NS_TOKEN_FREQ::TokenFreq tf5{"c++", 5};
        NS_TOKEN_FREQ::TokenFreq tf6{"to", 1};
        NS_TOKEN_FREQ::TokenFreq tf7{"become", 2};
        NS_TOKEN_FREQ::TokenFreq tf8{"software", 2};
        NS_TOKEN_FREQ::TokenFreq tf9{"engineer,", 1};
        NS_TOKEN_FREQ::TokenFreq tf10{"is", 1};
        NS_TOKEN_FREQ::TokenFreq tf11{"good", 1};

        std::vector<NS_TOKEN_FREQ::TokenFreq> results{tf1, tf2, tf3, tf4, tf5, tf6, tf7, tf8, tf9, tf10, tf11};

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if ((tf[i].token != results[i].token) || (tf[i].freq != results[i].freq)) {
                return false;
                break;
            }
        }
        return true;
    } // return true

    // Unit test for selection sort
    inline bool test1_selectionSort() {
        std::string istring = "I i am working i in c++ to i become software c++ engineer, c++ software c++ is good in c++ become";
        std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
        NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);
        NS_TOKEN_FREQ::selectionSort(tf);

        NS_TOKEN_FREQ::TokenFreq tf1{"good", 1};
        NS_TOKEN_FREQ::TokenFreq tf2{"is", 1};
        NS_TOKEN_FREQ::TokenFreq tf3{"am", 1};
        NS_TOKEN_FREQ::TokenFreq tf4{"working", 1};
        NS_TOKEN_FREQ::TokenFreq tf5{"engineer", 1};
        NS_TOKEN_FREQ::TokenFreq tf6{"to", 1};
        NS_TOKEN_FREQ::TokenFreq tf7{"in", 2};
        NS_TOKEN_FREQ::TokenFreq tf8{"become", 2};
        NS_TOKEN_FREQ::TokenFreq tf9{"software", 2};
        NS_TOKEN_FREQ::TokenFreq tf10{"i", 4};
        NS_TOKEN_FREQ::TokenFreq tf11{"c++", 5};

        std::vector<NS_TOKEN_FREQ::TokenFreq> actual_result{
           tf1, tf2, tf3, tf4, tf5, tf6, tf7, tf7, tf9, tf10, tf11
        };

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if (actual_result[i].freq != tf[i].freq) {
                return false;
                break;
            }
        }
        return true;
    }

    inline bool test2_selectionSort() {
        std::string istring = "to I i to am working i in c++ to i become to java to software to java to c++ engineer, java c++ java software java c++ is java good in c++ become";
        std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
        NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);
        NS_TOKEN_FREQ::selectionSort(tf);

        NS_TOKEN_FREQ::TokenFreq tf1{"good", 1};
        NS_TOKEN_FREQ::TokenFreq tf2{"is", 1};
        NS_TOKEN_FREQ::TokenFreq tf3{"engineer", 1};
        NS_TOKEN_FREQ::TokenFreq tf4{"am", 1};
        NS_TOKEN_FREQ::TokenFreq tf5{"working", 1};
        NS_TOKEN_FREQ::TokenFreq tf6{"in", 2};
        NS_TOKEN_FREQ::TokenFreq tf7{"software", 2};
        NS_TOKEN_FREQ::TokenFreq tf8{"become", 2};
        NS_TOKEN_FREQ::TokenFreq tf9{"i", 4};
        NS_TOKEN_FREQ::TokenFreq tf10{"c++", 5};
        NS_TOKEN_FREQ::TokenFreq tf11{"java", 6};
        NS_TOKEN_FREQ::TokenFreq tf12{"to", 7};

        std::vector<NS_TOKEN_FREQ::TokenFreq> actual_result{
           tf1, tf2, tf3, tf4, tf5, tf6, tf7, tf7, tf9, tf10, tf11, tf12
        };

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if (actual_result[i].freq != tf[i].freq) {
                return false;
                break;
            }
        }
        return true;
    }

    inline bool test3_selectionSort() {
        std::string istring = "java I i to c++ am java i working java to i in to c++ to i c++ become java c++ i to software i java to c++ engineer, java c++ java software java c++ is java good in c++ become";
        std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
        NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);
        NS_TOKEN_FREQ::selectionSort(tf);

        NS_TOKEN_FREQ::TokenFreq tf1{"good", 1};
        NS_TOKEN_FREQ::TokenFreq tf2{"is", 1};
        NS_TOKEN_FREQ::TokenFreq tf3{"engineer", 1};
        NS_TOKEN_FREQ::TokenFreq tf4{"am", 1};
        NS_TOKEN_FREQ::TokenFreq tf5{"working", 1};
        NS_TOKEN_FREQ::TokenFreq tf6{"in", 2};
        NS_TOKEN_FREQ::TokenFreq tf7{"software", 2};
        NS_TOKEN_FREQ::TokenFreq tf8{"become", 2};
        NS_TOKEN_FREQ::TokenFreq tf9{"to", 6};
        NS_TOKEN_FREQ::TokenFreq tf10{"i", 7};
        NS_TOKEN_FREQ::TokenFreq tf11{"c++", 8};
        NS_TOKEN_FREQ::TokenFreq tf12{"java", 9};

        std::vector<NS_TOKEN_FREQ::TokenFreq> actual_result{
           tf1, tf2, tf3, tf4, tf5, tf6, tf7, tf7, tf9, tf10, tf11, tf12
        };

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if (actual_result[i].freq != tf[i].freq) {
                return false;
                break;
            }
        }
        return true;
    }

    // Unit test for insertion sort
    inline bool test1_insertionSort(){
       std::string istring = "I i am working i in c++ to i become software c++ engineer, c++ software c++ is good in c++ become";
       std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
       NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);
       NS_TOKEN_FREQ::insertionSort(tf);
       NS_TOKEN_FREQ::TokenFreq tf1{"c++", 5};
       NS_TOKEN_FREQ::TokenFreq tf2{"i", 4};
       NS_TOKEN_FREQ::TokenFreq tf3{"software", 2};
       NS_TOKEN_FREQ::TokenFreq tf4{"become", 2};
       NS_TOKEN_FREQ::TokenFreq tf5{"in", 2};
       NS_TOKEN_FREQ::TokenFreq tf6{"good", 1};
       NS_TOKEN_FREQ::TokenFreq tf7{"is", 1};
       NS_TOKEN_FREQ::TokenFreq tf8{"engineer", 1};
       NS_TOKEN_FREQ::TokenFreq tf9{"to", 1};
       NS_TOKEN_FREQ::TokenFreq tf10{"working", 1};
       NS_TOKEN_FREQ::TokenFreq tf11{"am", 1};
      
        std::vector<NS_TOKEN_FREQ::TokenFreq> actual_result{
           tf1, tf2, tf3, tf4, tf5, tf6, tf7, tf7, tf9, tf10, tf11
        };

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if (actual_result[i].freq != tf[i].freq) {
                return false;
                break;
            }
        }
        return true;
     }
     
     
     inline bool test2_insertionSort(){
       std::string istring = "this is what is what our what";
       std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
       NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);
       NS_TOKEN_FREQ::insertionSort(tf);
       NS_TOKEN_FREQ::TokenFreq tf1{"what", 3};
       NS_TOKEN_FREQ::TokenFreq tf2{"is", 2};
       NS_TOKEN_FREQ::TokenFreq tf3{"this", 1};
       
       
      
        std::vector<NS_TOKEN_FREQ::TokenFreq> actual_result{
           tf1, tf2, tf3
        };

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if (actual_result[i].freq != tf[i].freq) {
                return false;
                break;
            }
        }
        return true;
     }
     
     
     inline bool test3_insertionSort(){
        std::string istring = "this is what is what what is baby is baby";
       std::vector<NS_TOKEN_FREQ::TokenFreq> tf;
       NS_TOKEN_FREQ::getTokenFreqVec(istring, tf);
       NS_TOKEN_FREQ::insertionSort(tf);
       NS_TOKEN_FREQ::TokenFreq tf1{"is", 4};
       NS_TOKEN_FREQ::TokenFreq tf2{"what", 3};
       NS_TOKEN_FREQ::TokenFreq tf3{"baby", 2};
       NS_TOKEN_FREQ::TokenFreq tf4{"this", 1};
       
        std::vector<NS_TOKEN_FREQ::TokenFreq> actual_result{
           tf1, tf2, tf3, tf4
        };

        for (unsigned long int i = 0; i < tf.size(); i++) {
            if (actual_result[i].freq != tf[i].freq) {
                return false;
                break;
            }
        }
        return true;
     }

} /*** End of NS_UNIT_TESTS ***/
// 1. matrixInit()
// 2. operator<=  for TokenFreq objects
// 3. operator+  for TokenFreq objects
// 4. getTokeFreq()
// 5. each of the two sorting algorithms 

//naming convention: 
//   test1_[function name]
//   test2_[function name]
//   test3_[function name]

//Note 1. for the two operators <= and +, use the following function names
//    test?_operatorLE();      //replace ? with 1, 2 or 3
//    test?_operatorPlus();    //replace ? with 1, 2 or 3


//Note 2: all your unit tests should return true/false like in Lab#1 and Lab#2

#endif