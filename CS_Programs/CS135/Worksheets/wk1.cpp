/*
 * Alec Him
 * CS 135 - Worksheet 1
 * Description: Show results of integer and double operations
 * Input: None
 * Output: Results of integer and double operations
 */
#include <iostream>

int main()
{
    // Variables
    const double dbFV = 5.0;
    const double dbTW = 2.0;
    const int intFV = 5;
    const int intTW = 2;

    // Output
    std::cout << "int 5/2 is " << intFV / intTW << std::endl;
    std::cout << "int 5%2 is " << intFV % intTW << std::endl;
    std::cout << "double 5/2 is " << dbFV / dbTW << std::endl;
    
    return 0;
}