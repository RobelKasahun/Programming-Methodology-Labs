//This file is for documentation purposes only. It will be ignored by the compiler.
//Our Teaching Assistant will manually grade this file.


//Please make sure that you include the entire content of this file as comments.


/* Design Doc: communicate your thought process in English.
 
-------------Problem analysis and algorithm design------------
Answer the following questions for each of the following functions: (1) operator<= for TokenFreq objects,  (2) operator+ for TokenFreq objects, (3) getTokenFreqVec(), and (4) the sorting function  (you only need to do one. pick either one):




1. What's the input data of this problem?
   - The input data of the problem is a string.
   
2. What's the output data of this problem?
   - The output data of this problem is a TokenFreq that has the word and its frequency.
   
3. List two sample inputs and their corresponding outputs
   - "Hello I am Hello"
      - (token = "Hello", freq = 2)
      - (token = "I", freq = 1)
      - (token = "am", freq = 1)
      
   - "Java is good but java best"
      - (token = "java", freq = 2)
      - (token = "is", freq = 1)
      - (token = "good", freq = 1)
      - (token = "but", freq = 1)
      - (token = "best", freq = 1)
      
4. For the getTokenFreq() only, what's your algorithm? Please describe your algorithm in pseudocode.
   - Algorithm
      - Change the string to lower case.
      - push individual words to a vector.
      - using nested for loop count the number of occurence for each word.
      - Assign each word and its frequence to a TokenFreq and push the TokenFreq to a vector of TokenFreq.
      
5. Apply the above 2 sample inputs to your getTokenFreq() algorithm, does your algorithm produce the expected outputs?
   - After applying the 2 sample inputs, I got expected result.
   
6. For the getTokenFreq() only: what's the time complexity of your algorithm?
   - n + n^2 + n^2 = 2n^2 + n --> thus it's O(N^2)

------------Implementation strategies in C++: example questions----------------------
7. What built-in and/or user-defined data types are you going to use and why?
   - I have used many of the built-in data types such as int, long, and so on
   - I also used user-defined data types such as TokenFreq and string.
   
8. What will be the function prototype of the overloaded operator<= and operator+?  
*/
   /*
      - void matrixInit(std::vector<std::vector<int>>&, int, int);
      - bool operator<=(const TokenFreq&, const TokenFreq&);
      - TokenFreq operator+(const TokenFreq&, const TokenFreq&);
      - std::ostream& operator<<(std::ostream&, const TokenFreq&);
      - void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec);
      - void selectionSort(std::vector<TokenFreq>&);
      - void insertionSort(std::vector<TokenFreq>&);
      - bool validate_availability(std::vector<TokenFreq>&, const std::string&);
      - void swapping(TokenFreq&, TokenFreq&);
   */

/*
-----------Code Review by yourself as you are coding and after you finish coding ----------------
1. Have you included comments to enhance your code's readability?
   - Yes, I have included some comment where needed.
   
2. Have you included three distinct test cases (negative and positive cases) in your own unit tests?
   - My used negative and positive cases, and my test cases has passed but for some reason zybook is killing me.
   
3. Have  you hard-coded the input and output pair to "fool" the unit tests?  (The correct answer is "No, I value academic integrity.")
   - No, I value academic integrity.
   
4. Have you followed these core guidelines ((find the URL on iLearn))
   - Yes, I have
*/