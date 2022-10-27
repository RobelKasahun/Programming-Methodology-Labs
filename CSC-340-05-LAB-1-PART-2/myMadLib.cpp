#include<iostream>
#include<ctype.h>
/*your C++ code starts below ...
  Your code needs to 
  
  1. Use the following function prototype to implement your algorithm:

///returns "[firstName] went to [placeName] to buy [number] different types of [pluralNoun]"
//Note. To keep this game simple, there is no need to check whether the input information meets the expectations. 
std::string myMadLib(const std::string& firstName, const std::string& placeName, int number, const std::string& pluralNoun);  

 2.  include three unit tests test1( ), test2(), and test3(), each of which returns true 
     if myMadLib( ) returns the correct result 
     
     For example: 
     
     bool test1()
     {
        //if you wish, you can print out a message here e.g., "my first test ...\n".
       //call myMadLib() ;
       //check the result
     }
*/

// Function Prototypes
std::string myMadLib(const std::string&, const std::string&, int, const std::string&);
bool checkString(const std::string&);
bool test1();
bool test2();
bool test3();

int main(){
   std::cout << std::boolalpha;
   
   std::string firstName, placeName, pluralName;
   int number;
   
   getline(std::cin, firstName);
   getline(std::cin, placeName);
   std::cin >> number;
   std::cin.ignore();
   getline(std::cin, pluralName);
   std::cout << myMadLib(firstName, placeName, number, pluralName) << std::endl;
   
   bool result_test_1 = test1();
   std::cout << result_test_1 << std::endl;
   bool result_test_2 = test2();
   std::cout << result_test_2 << std::endl;
   bool result_test_3 = test3();
   std::cout << result_test_3 << std::endl;
   
   
   return 0;
}

// Function definitions

/*
   Checks the each string for emptyiness or whitespaces and returns 
   [firstName] went to [placeName] to buy [number] different types of [pluralName]
   if all strings are not empty otherwise it returns "" empty string.
*/
std::string myMadLib(const std::string& firstName, const std::string& placeName, int number, const std::string& pluralName){
   if(checkString(firstName) || checkString(placeName) || checkString(pluralName)){
      std::cerr << "There exist an empty string." << std::endl;
      return "";
   }
   return firstName + " went to " + placeName + " to buy " + std::to_string(number) + " different types of " + pluralName
   + ".";
}

/*
   Checks whether string is empty or whitespace
   it returns false if the string is empty or whitespace. 
   Otherwise, it returns true.
*/
bool checkString(const std::string& str){
   unsigned int counter = 0;
   for(unsigned int letter = 0; letter < str.length(); ++letter){
      if(isspace(str.at(letter))){
         ++counter;
      }
   }
   return (counter == str.length()) ? true : false;
}

// Testing for strings that do not have whitespace or empty string
bool test1(){
   std::string firstName = "Robel", placeName = "Asmara", pluralName = "houses";
   int number = 15;
   std::string expected_result = firstName + " went to " + placeName + " to buy " + std::to_string(number) + " different types of " + pluralName + ".";
   return (myMadLib(firstName, placeName, number, pluralName) == expected_result);
}

// Testing for strings that have at least one string with whitespaces
bool test2(){
   std::string firstName = "     ", placeName = "London", pluralName = "cars";
   int number = 20;
   std::string expected_result = "";
   return (myMadLib(firstName, placeName, number, pluralName) == expected_result);
}

// Testing with empty string
bool test3(){
   std::string firstName = "Karina", placeName="", pluralName = "Robots";
   int number = 34;
   std::string expected_result = "";
   return (myMadLib(firstName, placeName, number, pluralName) == expected_result);
}