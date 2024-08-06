/*
 * Alec Him
 * CS 135 - Worksheet 8
 * Description: Simple program that demonstrates input error handling
 * Input: Doubles
 * Output: Sum
 */
#include <iostream>

int main()
{
    bool notDone = true;
    double fNum = 0.0, sNum = 0.0;

    do{
        std::cout << "Enter two numbers: ";
        std::cin >> fNum >> sNum;

        if(std::cin.fail() == true)
        {
            std::cin.clear();
            std::cin.ignore(40, '\n');
            std::cout << "Error - Non-integer input detected - Please try again." << std::endl;
        } else {
            notDone = false;
        }
    } while(notDone);

    std::cout << fNum << " + " << sNum << " = " << fNum + sNum << std::endl;

    return 0;
}