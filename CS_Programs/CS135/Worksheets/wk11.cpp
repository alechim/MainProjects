/*
 * Alec Him
 * CS 135 - Worksheet 11
 * Description: Simple program that introduces double functions
 * Input: Double
 * Output: Circumference
 */
#include <iostream>

double circle(double);

double circle(double radiusCalc)
{
    const double PI = 3.141592653589;
    double circumferenceCalc = 0.0;

    circumferenceCalc = 2 * PI * radiusCalc;
    return circumferenceCalc;
}

int main()
{
    double radius = 0.0, circumference = 0.0;

    std::cout << "Enter radius: ";
    std::cin >> radius;

    circumference = circle(radius);
    std::cout << "Circumference: " << circumference << std::endl;

    return 0;
}