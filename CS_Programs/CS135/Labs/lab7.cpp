/*
 * Alec Him
 * CS 135 - Lab 7
 * Description: Creates a triangle based on inputs of shape and dimension
 * Input: Integer (Shape: body of triangle, dimension: height of triangle)
 * Output: Triangle with shape and dimension
 */
#include <iostream>

// Function Prototype
void triangle(char, int);

// Function Definition
void triangle(char s, int characterCount)
{
    int counter;
    for(counter = 1; counter <= characterCount; counter++)
        std::cout << s;
    std::cout << std::endl;
}

int main()
{
    // Variables
    char s;
    int dimension, count = 0;

    // Input
    std::cin >> s;
    std::cin >> dimension;

    while(std::cin)
    {
        if(count == 0)
        {
            std::cout << "Shape: " << s << std::endl;
            std::cout << "Dimension: " << dimension << std::endl;
        }
        while(count <= dimension)
        {
            triangle(s, count);
            count++;
        }
        std::cin >> s;
        std::cin >> dimension;
        count = 0;
        std::cout << std::endl;
    }

    return 0;
}