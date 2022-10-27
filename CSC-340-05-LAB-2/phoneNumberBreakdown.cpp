#include<iostream>
#include<string>
#include<vector>

/*your C++ code starts below ...
  Your code needs to
*/


struct StructuredPhoneNumber {
    std::string areaCode = "000";  //3 digits
    std::string prefix = "000"; //3 digits
    std::string lineNo = "0000"; // 4 digits
};

// Function prototypes
StructuredPhoneNumber phoneNumBreakdown(long long);
std::vector<std::string> getBrokenDownPhoneNumber(std::string);
bool operator==(const StructuredPhoneNumber&, const StructuredPhoneNumber&);

//converts a phone number from a 10-digit long long to {area code, prefix, lineNo}
//returns a StructuredPhoneNumber object {"000", "000", "0000"} if the input number is negative or less than 10 digits. 

// 3.  include three unit tests test1( ), test2(), and test3(), each of which returns true 
//     if phoneNumBreakdown( ) correctly calculates the three piceces of info

//     For example: 

// First test with valid phone number
bool test1() {
    //if you wish, you can print out a message here e.g., "my first test ...\n".
    //call phoneNumBreakdown(8005551212) ;
    //check the result
    StructuredPhoneNumber phoneNumber = phoneNumBreakdown(8456578892);
    if ((phoneNumber.areaCode == "845") && (phoneNumber.prefix == "657") && (phoneNumber.lineNo == "8892")) {
        return true;
    }
    return false;
}

// Second test with negative phone number
bool test2() {
    StructuredPhoneNumber p = phoneNumBreakdown(-6478597747);
    if ((p.areaCode == "000") && (p.prefix == "000") && (p.lineNo == "0000")) {
        return true;
    }
    return false;
}

// Third test with less than 10 digits of phone number
bool test3() {
    StructuredPhoneNumber p = phoneNumBreakdown(65783994);
    if ((p.areaCode == "000") && (p.prefix == "000") && (p.lineNo == "0000")) {
        return true;
    }
    return false;
}

// 4.  overload the operator== to compare whether two StructuredPhoneNumber objects 
   //  contain exactly the same phone number.
// 5. include two unit tests to test the above overloaded operator==

// Testing overloaded operator ==
bool test_operator1() {
    StructuredPhoneNumber p1 = phoneNumBreakdown(6578947584);
    StructuredPhoneNumber p2 = phoneNumBreakdown(4089381534);
    return (!(p1 == p2));
}

// Testing overloaded operator
bool test_operator2() {
    //call the overloaded operator==
    //check if it produces the expected result
    StructuredPhoneNumber p1 = phoneNumBreakdown(4086578849);
    StructuredPhoneNumber p2 = phoneNumBreakdown(4086578849);
    return ((p1 == p2)) ? true : false;
}



int main() {
    long long phoneNumber = 4086578848;
    StructuredPhoneNumber n = phoneNumBreakdown(phoneNumber);
    std::cout << "areaCode: " << n.areaCode << std::endl;
    std::cout << "prefix: " << n.prefix << std::endl;
    std::cout << "lineNo: " << n.lineNo << std::endl;

    std::cout << std::boolalpha;
    // Unit test
    std::cout << "Expected result: true, Actual result: " << test1() << std::endl;
    std::cout << "Expected result: true, Actual result: " << test2() << std::endl;
    std::cout << "Expected result: true, Actual result: " << test3() << std::endl;

    std::cout << "\n";

    // Operator test
    std::cout << "Expected result: false, Actual result: " << test_operator1() << std::endl;
    std::cout << "Expected result: true, Actual result: " << test_operator2() << std::endl;

    return 0;
} // End of main function

StructuredPhoneNumber phoneNumBreakdown(long long phoneNum_ll) {
    StructuredPhoneNumber tempPhoneNumber;
    tempPhoneNumber.areaCode = "000";
    tempPhoneNumber.prefix = "000";
    tempPhoneNumber.lineNo = "0000";

    const int SIZE = 10;
    std::string stringPhoneNumber = std::to_string(phoneNum_ll);
    /* Check whether the phone number is less than 10 digits or negative number */
    if ((stringPhoneNumber.size() < SIZE) || (phoneNum_ll < 0)) {
        return tempPhoneNumber;
    }

    std::vector<std::string> segments = getBrokenDownPhoneNumber(stringPhoneNumber);
    tempPhoneNumber.areaCode = segments.at(0);
    tempPhoneNumber.prefix = segments.at(1);
    tempPhoneNumber.lineNo = segments.at(2);
    return tempPhoneNumber;
}

/* Break down the phone number and push them back to a vector */
std::vector<std::string> getBrokenDownPhoneNumber(std::string phoneNumber) {
    std::vector<std::string> segments;
    phoneNumber.insert(3, " ");
    phoneNumber.insert(7, " ");
    long startingPosition = 0;
    long find = 0;
    segments.push_back(phoneNumber.substr(startingPosition, phoneNumber.find(" ")));
    startingPosition = phoneNumber.find(" ") + 1;
    find = phoneNumber.find(" ", startingPosition);
    segments.push_back(phoneNumber.substr(startingPosition, find - startingPosition));
    startingPosition = find + 1;
    segments.push_back(phoneNumber.substr(startingPosition, phoneNumber.size() - startingPosition));
    return segments;
}

bool operator==(const StructuredPhoneNumber& p1, const StructuredPhoneNumber& p2) {
    if ((p1.areaCode == p2.areaCode) && (p1.prefix == p2.prefix) && (p1.lineNo == p2.lineNo)) {
        return true;
    }
    return false;
}

