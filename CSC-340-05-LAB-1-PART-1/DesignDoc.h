/* Design Doc: communicate your thought process in English.  
-------------Problem analysis and algorithm design------------

What's the input data of this problem? 
   - The input data of this problem are positive years such as 1600, 1712, and so on.
   
What's the output data of this problem? 
   - The output data of this problem is true or false.
   
List 3 or more sample inputs  and their corresponding output 
     input    output
   - 1600     true
   - 1700     false
   - 1800     false
   - 2000     true
   - 1712     true
   - 2016     true
   
What's your algorithm (described in pseudocode)?
   - Check if the year is divisible by 4 but not by 100
      - if true, the year is a leap year
   - Also, check if the year is divisible by 400
      - if true, the year is leap year
   - Otherwise
      - the year is not a leap year
      
Using the above sample inputs, does your algorithm produce the expected outputs?
   - I tested my algorithm with many sample data, and it produces expected outputs.
   
What's the time complexity of your algorithm?  
   - It is O(1) or Constant time

------------Implementation strategies in C++: example questions----------------------
What built-in and/or user-defined data types are you going to use and why?
   - I am going to use built-in data types such as unsigned int and bool because the
   inputs that we expect are only positive numbers and using the inputs we must produce
   boolean result, thus unsigned int and bool built-in data types are the best fit.
What will be the function prototype if applicable? 
   - bool isLeapYear(unsigned int);

*/
/*
-----------Unit tests----------------------
Have you written at least three unit tests for each function?   
   - Yes, I have written three unit tests and passed the test.

-----------Code Review----------------------
1. Have you included comments to enhance your code's readability?
   - Yes, I have included comments for the function isLeapYear()
   - And the comments will help anyone how the function works.
   
2. Have  you hard-coded the input and output pair to "fool" the unit tests?  (The correct answer is "No, I value academic integrity.") 
   - No, I value academic integrity.
3. Have you followed these core guidelines listed at ...?
   - Yes, I have.
*/