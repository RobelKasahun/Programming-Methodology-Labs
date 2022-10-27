/*your C++ code starts below ...
  Your code needs to include 
  - a function isLeapYear( ) that returns true/false given a year.
  - Three unit tests test1( ), test2(), and test3(), each of which returns true 
     if isLeapYear() returns the correct answer on three different inputs of your choice.
     
     For example: 
     
     bool test1()
     {
        return (isLeapYear(2000)==true);
     }
*/
#include<iostream>

// Function Prototype
bool isLeapYear(unsigned int);

bool test1() { // Testing the function using value of 1900
   return (isLeapYear(1900) == false); // Must return true
}

bool test2(){ // Testing the function using value of 1600
   return (isLeapYear(1600) == true); // Must return true
}

bool test3(){ // Testing the function using value od 1700
   return (isLeapYear(1700) == false); // Must return true;
}

int main() {
   std::cout << std::boolalpha;
   
   std::cout << "Result: true, Expected result: " << test1() << std::endl; 
   std::cout << "Result: true, Expected result: " << test2() << std::endl;
   std::cout << "Result: true, Expected result: " << test3() << std::endl;
   return 0;
}

/*
   Return true if the year is divisible by 4 but not by 100. 
   Also, return true if the year is divisible by 400. 
   Otherwise, return false.
*/
bool isLeapYear(unsigned int year){
   if((year % 4 == 0) && (year % 100 != 0)){
      return true;
   }
   else if((year % 400 == 0)){
      return true;
   }
   else {
      return false;
   }
}

