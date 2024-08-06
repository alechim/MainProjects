/*
 * Alec Him
 * CS 135 - Lab 2
 * Description: Converts Fahrenheit into other measurements of energy
 * Input: Double
 * Output: Celsius, Kelvin, Rankine, Romer
 */
#include <iostream>

int main()
{
    // Variables
    double fahrenheit = 0.0, celsius = 0.0, kelvin = 0.0, rankine = 0.0, romer = 0.0;
    
    // Prompt user for input
    std::cout << "Please enter the temperature in Fahrenheit: ";
    std::cin >> fahrenheit;
    
    // Calculate Celsius, Kelvin, Rankine, and Romer
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    kelvin = celsius + 273.15;
    rankine = fahrenheit + 459.67;
    romer = (fahrenheit - 7.5) * 40.0 / 21.0;

    // Display results
    std::cout << "Fahrenheit: " << fahrenheit << std::endl;
    std::cout << "Celsius: " << celsius << std::endl;
    std::cout << "Kelvin: " << kelvin << std::endl;
    std::cout << "Rankine: " << rankine << std::endl;
    std::cout << "Romer: " << romer << std::endl;
    
    return 0;
}