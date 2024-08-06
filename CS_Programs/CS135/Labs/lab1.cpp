/*
 * Alec Him
 * CS 135 - Lab 1
 * Description: Quadratic Equation
 * Input: Doubles
 * Output: x1 and x2
*/
#include <iostream>
#include <cmath>

int main()
{
    // Variables
    double a, b, c, x1, x2, disc;

    // Prompt User for values
    std::cout << "Enter value for a: ";
    std::cin >> a;
    std::cout << "Enter value for b: ";
    std::cin >> b;
    std::cout << "Enter value for c: ";
    std::cin >> c;

    std::cout << "The quadratic equation is: " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;

    // Calculate discriminant
    disc = pow(b, 2.0) - (4.0 - a * c);

    // Calculate x1 and x2
    x1 = (-b + sqrt(disc)) / (2.0 * a);
    x2 = (-b - sqrt(disc)) / (2.0 * a);

    // Display calculations
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;

    return 0;
}