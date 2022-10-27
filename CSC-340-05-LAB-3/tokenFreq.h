//This is a header file: to declare the TokenFreq data structure, the getTokenFreq() prototype, 
//and other relevant function prototypes such as the overloaded operators for the TokenFreq datatype 

//-include the above in the namespace NS_TOKEN_FREQ

//Note: please include <algorithm> in this file. The instructor's unit tests will need this library.
#ifndef TOKEN_FREQ_H_
#define TOKEN_FREQ_H_
#include<iostream>
#include<algorithm>
#include<ostream>
#include<vector>


namespace NS_TOKEN_FREQ {
    struct TokenFreq {
        std::string token;
        int freq;
    };

    bool operator<=(const TokenFreq&, const TokenFreq&);
    TokenFreq operator+(TokenFreq&, TokenFreq&);
    std::ostream& operator<<(std::ostream&, const TokenFreq&);
    void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec);
    void selectionSort(std::vector<TokenFreq>&);
    void insertionSort(std::vector<TokenFreq>&);
    bool validate_availability(std::vector<TokenFreq>&, const std::string&);
    void swapping(TokenFreq&, TokenFreq&);
}
#endif