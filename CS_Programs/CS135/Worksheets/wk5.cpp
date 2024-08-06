/*
 * Alec Him
 * CS 135 - Worksheet 5
 * Description: Simple program that demonstrates the size comparisons of double and string
 * Input: Doubles and Strings
 * Output: Larger Number and String or Equal
 */
#include <iostream>

int main()
{
    // Variables
    double fDbl = 0.0, sDbl = 0.0;
    std::string fString = "", sString = "";

    std::cout << "Enter two numbers (double): ";
    std::cin >> fDbl >> sDbl;
    std::cout << "You entered " << fDbl << " and " << sDbl << std::endl;

    if(fDbl > sDbl)
    {
        std::cout << "The larger number is " << fDbl << std::endl;
    } else if(sDbl > fDbl){
        std::cout << "The larger number is " << sDbl << std::endl;
    } else {
        std::cout << "The numbers are equal" << std::endl;
    }

    std::cout << "Enter two strings: ";
    std::cin >> fString >> sString;
    std::cout << "You entered \"" << fString << "\" and \"" << sString << "\"" << std::endl;

    if(fString > sString)
    {
        std::cout << "The larger string is \"" << fString << "\"" << std::endl;
    } else if(sString > fString){
        std::cout << "The larger string is \"" << sString << "\"" << std::endl;
    } else {
        std::cout << "The strings are equal" << std::endl;
    }

    return 0;
}