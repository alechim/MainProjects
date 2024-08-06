/*
 * Alec Him
 * CS 135 - Worksheet 3
 * Description: Simple program that demonstrates sin() and cos()
 * Input: Double
 * Output: Sin and Cos of Degrees in Radians
 */
#include <iostream>
#include <cmath>

int main()
{
    const double PI = 3.141592653589;
    double degrees = 0, radians = 0;

    std::cout << "Enter an angle value, in degrees: ";
    std::cin >> degrees;
    radians = degrees * PI / 180;

    std::cout << "sin(" << degrees << ") = " << sin(radians) << std::endl;
    std::cout << "cos(" << degrees << ") = " << cos(radians) << std::endl;
    
    return 0;
}