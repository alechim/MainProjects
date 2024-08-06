/*
 * Alec Him
 * CS 135 - Assignment 2
 * Description: A program that takes input of diameter and calculates volume and surface area
 * Input: Doubles
 * Output: Volume and Area
*/
#include <iostream>     // For console input and output
#include <cmath>        // Gives the program access to sin(), sqrt(), pow(), etc.

int main()
{
    // Variables
    double d, vol, area; // Diameter, Volume, Surface Area
    const double PI = 3.14159265358;

    // Prompt User for diameter
    std::cout << "Enter the diameter of the celestial body (km): ";
	std::cin >> d;

    // Calculate volume
    vol = (4.0 / 3.0) * PI * pow(d / 2.0, 3);
    std::cout << "The volume of the celestial body: " << vol << " km" << std::endl;

    // Calculate surface area
    area = 4.0 * PI * pow(d / 2.0, 2);
    std::cout << "The surface area is: " << area << " square km" << std::endl;

    return 0;
}