/*
 * Alec Him
 * CS 135 - Assignment 3
 * Description: A program that takes in diameter, height, efficiency, and wave length and calculates respective values 
 * Input: Doubles
 * Output: Slant Height, Laterla Surface, Surface Area, Volume, Focal Point, Wave Length
*/
#include <iostream>     // For console input and output
#include <cmath>        // Gives the program access to sin(), cos(), sqrt(), pow()

int main()
{
    // Variables
    const double PI = 3.141592653589;
    double height, diameter, radius, slantHeight, lateralSurface, surfaceArea, volume, focalPoint, k, waveLength, gain = 0;
    
    std::cout << "\n*******************************************\n";
	std::cout << "** Rebel Alliance Computational Division **\n";
	std::cout << "*******************************************\n\n";
    
    // Prompt user for diameter and height
    std::cout << "Enter the diameter of the super laser lens(km): ";
    std::cin >> diameter;

    std::cout << "Enter the height of the lens(km): ";
    std::cin >> height;

    std::cout << "\n--------------------------------------------\n";
    std::cout << "Specifciations for Super Laser\n";
    std::cout << "Height: " << height <<" km\n";
    std::cout << "Diameter: " << diameter << " km\n";
    std::cout << "--------------------------------------------\n";

    // Calculate variables based on prior input
    radius = diameter / 2.0;
    slantHeight = sqrt(pow(height, 2.0) + pow(radius, 2.0));
    lateralSurface = radius * slantHeight * PI;
    surfaceArea = radius * PI * (radius + slantHeight);
    volume = 1.0 / 3.0 * pow(radius, 2.0) * PI * height;
    focalPoint = (pow((2.0 * radius), 2.0)) / (16.0 * height);

    // Output calculations
    std::cout << "Slant Height: " << slantHeight << " km\n";
    std::cout << "Lateral Surface: " << lateralSurface << " km\n";
    std::cout << "Area: " << surfaceArea << " km^2\n";
    std::cout << "Volume: " << volume << " km^3\n";
    std::cout << "Focal Point: " << focalPoint << " km\n\n";

    // Prompt user for efficiency and wave length
    std::cout << "Enter the efficiency of the lens/antenna: ";
    std::cin >> k;

    std::cout << "Enter the wave length (meters): ";
    std::cin >> waveLength;

    // Calculate gain
    gain = 10 * log10(k * pow((PI * diameter / waveLength), 2.0));

    std::cout << "The Super Laser lens gain is: " << gain << " dB\n\n";

    std::cout << "<<<<<<<<<<< - >>>>>>>>>>>\n";
	std::cout << "May the Force be with you!\n";
	std::cout << "<<<<<<<<<<< - >>>>>>>>>>>\n";

    return 0;
}