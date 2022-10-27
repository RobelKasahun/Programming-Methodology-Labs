//This file is for documenting purpose only. It will be ignored by the compiler.
//Our Teaching Assistant will check this file manually and grade it for 3 points. 

/* Design Doc: communicate your thought process in English.  
-------------Problem analysis and algorithm design------------

What's the input data of this problem?    
   - The input data of this problem is a phone number.

What's the output data of this problem?
 - Assuming the input data is 4086578829
 - The output data of this problem is StructuredPhoneNumber{"408", "657", "8829"};

List 3 or more sample inputs  and their corresponding outputs
   - Input: 6577586627
      - Output: StructuredPhoneNumber{"657", "758", "6627"};
   - Input: -4084458990
      - Output: StructuredPhoneNumber{"000", "000", "0000"};
   - Input: 665756890
      - Output: StructuredPhoneNumber{"000", "000", "0000"};


What's your algorithm (described in pseudocode)?
   - Get the phone number.
   - Convert the phone number to a string.
   - Check if the phone number is negative or has a size of less than 10. If so, 
      - return StructuredPhoneNumber{"000", "000", "0000"};
   - If the phone number is valid
      - Insert white space at positions 3 and 7.
      - Push the substring from 0 up to 3 to the vector.
      - Push the substring from 4 up to 7 to the vector.
      - Push the substring from 8 up to phoneNumber.size() to the vector.
   - After pushing the data to the vector. Assign each element of the vector to each property of the StructuredPhoneNumber in phoneNumBreakdown() function.


Using the above sample inputs, does your algorithm produce the expected outputs?
   - Yes, my algorithm produces the expected output.


What's the time complexity of your algorithm?  
   - I have not used any loop, therefor the time complexity of my algorithm is constant time.

------------Implementation strategies in C++: example questions----------------------
What built-in and/or user-defined data types are you going to use and why?
   - we are going to design a data structure to encapsulate the three segments into one object. 
   - I am going to use boolean for testing purposes
   - I am going to use a string to hold the coveted phone number.
   - I am also going to use a vector data structure for storing each segment of the phone number.
   
What will be the function prototype?
   - StructuredPhoneNumber phoneNumBreakdown(long long);
   - std::vector<std::string> getBrokenDownPhoneNumber(std::string);
   - bool operator==(const StructuredPhoneNumber&, const StructuredPhoneNumber&); 
*/

/*
-----------Code Review by Yourself ----------------------
1. Have you included comments to enhance your code's readability?
   - Yes, I have. I included comments to just explain what the particular function does.

2. Have you included three distinct test cases (negative and positive cases) in your own unit tests?
   - I have included a test with a valid phone number.
   - I have included a test with a negative phone number.
   - I have included a test with a phone number that has a size of fewer than 10 digits.

3. Have you hard-coded the input and output pair to "fool" the unit tests?  (The correct answer is "No, I value academic integrity.") 
   - No, I value academic Integrity.

4. Have you followed [these core guidelines](https://docs.google.com/document/d/16OoMJK0DkuGRw-7v3YERYdaQ3IeOwTzD18JO5S_B_Iw/edit?usp=sharing)?
   - I would say, I followed the core guidelines.
*/

