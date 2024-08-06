/*
 * Alec Him
 * CS 135 - Worksheet 4
 * Description: Simple program that calculates the circumference of a circle based on user input
 * Input: Double
 * Output: Circumference
 */
#include <iostream>
#include <iomanip>

int main()
{
    const double PI = 3.141592653589;
    double radius = 0, circumference = 0;

    std::cout << "Enter radius: ";
    std::cin >> radius;
    circumference = 2 * PI * radius;

    std::cout << std::fixed << std::setprecision(2) << "Circumference of a circle with a radius of " << radius << " is " << circumference << std::endl;

    return 0;
}