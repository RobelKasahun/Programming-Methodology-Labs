//This file is for documenting purpose only. It will be ignored by the compiler.
//Our Teaching Assistant will check this file manually and grade it for 10 points. 

/* Design Doc: communicate your thought process in English.  
-------------Problem analysis and algorithm design------------

What's the input data of this problem? 
   - The input data of this problem are 3 strings and 1 integer.
   
What's the output data of this problem?
   - The desire output of this problem is 
   - [firstName] went to [placeName] to buy [number] different types of [pluralName]
   
List 3 or more sample inputs  and their corresponding outputs
   - input: firstName = "Robel", placeName = "Asmara", number = 20, pluralName = "houses"
      - output: Robel went to Asmara to buy 20 different types of houses
      
   - input: firstName = "Kani", placeName = "    ", number = 20, pluralName = "houses"
      - output: Empty string ("")
      
   - input: firstName = "", placeName = "London", number = 20, pluralName = "houses"
      - output: Empty string ("");
      
What's your algorithm (described in pseudocode)?
   - Check each string for empty string or whitespaces
   - if there is no any string that is whitespace or empty string
   - display the desired string. Otherwise, display a message 
     stating that there is an empty or whitespace string.
   - and return an empty string.
   
Using the above sample inputs, does your algorithm produce the expected outputs?
   - Yes, it does produce the desired output.
   
What's the time complexity of your algorithm?  
   - There is an algorithm that I wrote to check for empty string and whitespaces, thus
     the time complexity is O(n).

------------Implementation strategies in C++: example questions----------------------
What built-in and/or user-defined data types are you going to use and why?
   - The data types that I am going to use are string, int, and bool.
   - The reason that I am using these data types is because the function myMadLib()
     accepts three strings and one integer, and I use bool data type for testing 
     pupose.
     
What will be the function prototype if applicable?
   - std::string myMadLib(const std::string&, const std::string&, int, const std::string&);
   - bool checkString(const std::string&);
   - bool test1();
   - bool test2();
   - bool test3();
*/

/*
-----------Code Review by Yourself ----------------------
1. Have you included comments to enhance your code's readability?
   - Yes, I have included an explanation that each function does.
   
2. Have you included three distinct test cases (negative and positive cases) in your own unit tests?
   - I have included one unit test without any empty or whitespace string, one with whitespace string 
     , and one with an empty string.
     
3. Have  you hard-coded the input and output pair to "fool" the unit tests?  (The correct answer is "No, I value academic integrity.") 
   - No, I value academic integrity.
   
4. Have you followed [these core guidelines](https://docs.google.com/document/d/16OoMJK0DkuGRw-7v3YERYdaQ3IeOwTzD18JO5S_B_Iw/edit?usp=sharing)?
   - Yes, I have.
*/