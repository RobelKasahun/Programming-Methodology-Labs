//implement the functions declared in tokenFreq.h
// namely,
// - getTokenFreq()'s prototype
// - the two sorting algorithms' prototypes
#include<iostream>
#include "tokenFreq.h"
#include<algorithm>

using namespace NS_TOKEN_FREQ;

bool NS_TOKEN_FREQ::operator<=(const TokenFreq& lhs, const TokenFreq& rhs) {
    return (lhs.freq <= rhs.freq);
}

TokenFreq NS_TOKEN_FREQ::operator+(TokenFreq& lhs, TokenFreq& rhs) {
    std::string concatenated = lhs.token + " or " + rhs.token;
    int freq_sum = lhs.freq + rhs.freq;
    TokenFreq token_freq{concatenated, freq_sum};
    return token_freq;
}

std::ostream& NS_TOKEN_FREQ::operator<<(std::ostream& output_stream, const TokenFreq& obj) {
    output_stream << obj.token << ", " << obj.freq << std::endl;
    return output_stream;
}

bool NS_TOKEN_FREQ::validate_availability(std::vector<NS_TOKEN_FREQ::TokenFreq>& tf, const std::string& element) {
    for (unsigned long int i = 0; i < tf.size(); i++) {
        if (tf[i].token == element) {
            return true;
            break;
        }
    }
    return false;
}

void NS_TOKEN_FREQ::swapping(NS_TOKEN_FREQ::TokenFreq& tf1, NS_TOKEN_FREQ::TokenFreq& tf2) {
    NS_TOKEN_FREQ::TokenFreq temp = tf1;
    tf1 = tf2;
    tf2 = temp;
}

void NS_TOKEN_FREQ::selectionSort(std::vector<NS_TOKEN_FREQ::TokenFreq>& tf) {
    for (unsigned long int start = 0; start < (tf.size() - 1); ++start) {
        NS_TOKEN_FREQ::TokenFreq min_token_freq = tf[start]; // tf.at(start)
        unsigned long int min_index = start;
        for (unsigned long int j = start + 1; j < tf.size(); j++) {
            if (tf[j] <= min_token_freq) {
                min_token_freq = tf[j];
                min_index = j;
            }
        }
        // swap start and min_index
        swapping(tf[start], tf[min_index]);
    }
}

void NS_TOKEN_FREQ::insertionSort(std::vector<NS_TOKEN_FREQ::TokenFreq>& tf) {
   int size = static_cast<int>(tf.size());
   for(int i = 1; i < size; i++){
      NS_TOKEN_FREQ::TokenFreq current_token_freq = tf[i];
      int j;
      for(j = i - 1; (j >= 0) && (tf[j] <= current_token_freq); j--){
         tf[j + 1] = tf[j];
      }
      tf[j + 1] = current_token_freq;
   }
}

void NS_TOKEN_FREQ::getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec) {
    long int starting_position = 0;
    long int white_space_position = 0;

    std::for_each(istr.begin(), istr.end(), [](char& character) {
        character = static_cast<char>(tolower(character));
        });

    // push each words to this vector
    std::vector<std::string> words;

    while (white_space_position != -1L) {
        white_space_position = istr.find(" ", starting_position);
        std::string substring = istr.substr(starting_position, white_space_position - starting_position);
        starting_position = white_space_position + 1;
        words.push_back(substring);
    }

    int freq_counter = 0;

    for (unsigned long int i = 0; i < words.size(); i++) {
        std::string current_token = words[i];
        for (unsigned long int j = 0; j < words.size(); j++) {
            if (current_token == words[j]) { // words.at(j)
                ++freq_counter;
            }
        }
        NS_TOKEN_FREQ::TokenFreq tf;
        tf.token = current_token;
        tf.freq = freq_counter;
        if (!validate_availability(tfVec, current_token) && (!current_token.empty())) {
            tfVec.push_back(tf);
        }
        freq_counter = 0;
      //  current_token = "";
    };

   //  selectionSort(tfVec);
   // insertionSort(tfVec);

    int counter = 0;
    for (const NS_TOKEN_FREQ::TokenFreq& token_freq : tfVec) {
       std::cout << "[" << counter << "] = (token = " << "\"" << token_freq.token << "\", freq = " << token_freq.freq << ")\n";
       ++counter;
    }
}
