/*
 * Alec Him
 * CS 135 - Lab 8
 * Description: Function to calculate base to the power of exponent
 * Input: Integers
 * Output: Sum of the exponent
 */
#include <iostream>

// Function Prototype
double calc(int, int);

// Function Definition
double calc(int baseCalc, int expCalc)
{
    double total = 1.0;
    if(expCalc == 0)
    {
        total = 1.0;
    } else if(expCalc > 0){
        while(expCalc > 0)
        {
            total *= baseCalc;
            expCalc--;
        }
    } else if(expCalc < 0){
        while(expCalc < 0)
        {
            total *= baseCalc;
            expCalc++;
        }
        total = 1 / total;
    }

    return total;
}

int main()
{
    // Variables
    bool notDone = true;
    int base = 0, exp = 0;
    double sum = 0.0;

    do{
        std::cout << "Base: ";
        std::cin >> base;
        if(std::cin.fail() == true){
            std::cin.clear();
            std::cin.ignore(40, '\n');
            std::cout << "Error - Non-integer input detected - Please try again." << std::endl;
        } else {
            notDone = false;
        }
    } while(notDone);
    
    notDone = true;
    do{
        std::cout << "Exponent: ";
        std::cin >> exp;
        if(std::cin.fail() == true){
            std::cin.clear();
            std::cin.ignore(40, '\n');
            std::cout << "Error - Non-integer input detected - Please try again." << std::endl;
        } else {
            notDone = false;
        }
    } while(notDone);

    std::cout << std::endl;
    sum = calc(base, exp);
    std::cout << base << "^" << exp << " = " << sum << std::endl;

    return 0;
}