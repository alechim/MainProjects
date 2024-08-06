/*
 * Alec Him
 * CS 135 - Worksheet 12
 * Description: Introduction to multiple functions (void and double)
 * Input: Doubles
 * Output: Product
 */
#include <iostream>

void readValues(double&, double&);
double multiply(double, double);

// Function Definitions
// - readValues
void readValues(double& fValue, double& sValue)
{
    std::cout << "Enter two numbers: ";
    std::cin >> fValue >> sValue;
    return;
}

// - multiply
double multiply(double fValue, double sValue)
{
    double total = 0.0;
    total = fValue * sValue;
    return total;
}

int main()
{
    double fValue = 0.0, sValue = 0.0, calc = 0.0;

    readValues(fValue, sValue);
    calc = multiply(fValue, sValue);
    std::cout << fValue << " * " << sValue << " = " << calc << std::endl;

    return 0;
}