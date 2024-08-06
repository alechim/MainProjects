/*
 * Alec Him
 * CS 135 - Lab 3
 * Description: Calculates the radius, circumference, volume, and density of planets
 * Input: Integer
 * Output: Earth's radius, circumference, volume, and density
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    // Variables
    const double PI = M_PI;
    const std::string planets[8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    const double planetDiameter[8] = {4879, 12104, 12756, 6792, 142298, 120536, 51118, 49528};
    const double planetMass[8] = {0.330*pow(10,24), 4.87*pow(10,24), 5.97*pow(10,24), 0.642*pow(10,24), 
                                  1898*pow(10,24), 568*pow(10,24), 86.8*pow(10,24), 102*pow(10,24)};
    double diameter = 0.0, mass = 0.0;
    std::string planet = "";
    int userInput = 0;
    double radius = 0.0, circumference = 0.0, volume = 0.0, density = 0.0;

    // Display and prompt user for input
    std::cout << "Mercury[1]\nVenus[2]\nEarth[3]\nMars[4]\nJupiter[5]\nSaturn[6]\nUranus[7]\nNeptune[8]\n";
    std::cout << "Welcome to planetary statistics, enter a number corresponding to the planet above to continue: ";
    std::cin >> userInput;

    // Tests for valid inputs
    while(std::cin.fail())
    {
        std::cout << "Not an integer, try again\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> userInput;
    }
    if(userInput < 1 || userInput > 8)
    {
        std::cout << "Invalid input, try again\n";
        std::cin >> userInput;
    }

    // Set local variables to user input
    diameter = planetDiameter[userInput - 1];
    mass = planetMass[userInput - 1];
    planet = planets[userInput - 1];

    // Calculate variables
    radius = diameter / 2.0;
    circumference = PI * radius;
    volume = (4.0 / 3.0) * PI * pow(radius, 3.0) * pow(1000.0, 3.0);
    density = mass / volume;

    // Display results
    std::cout << "Earth Statistics: " << std::endl;
    std::cout << "Earth Radius: " << std::fixed << std::setprecision(2) << radius << " km" << std::endl;
	std::cout << "Earth Circumference: " << std::fixed << std::setprecision(2) << circumference << " km" << std::endl;
	std::cout << "Earth Volume: " << std::scientific << volume << " m^3" << std::endl;
	std::cout << "Earth Density: " << std::fixed << std::setprecision(2) << density << " kg/m^3" << std::endl;

    return 0;
}