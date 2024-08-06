/*
 * Alec Him
 * CS 135 - Worksheet 6
 * Description: Simple program that counts up from a number to a maximum amount based on user input
 * Input: Integers
 * Output: Sequence of Counted Numbers
 */
#include <iostream>

int main()
{
    // Variables
    int startingNumber = 0, numberCount = 0, maxCount = 0;
    
    std::cout << "Enter the starting number: ";
    std::cin >> startingNumber;

    std::cout << "Enter how many numbers to print: ";
    std::cin >> numberCount;

    while (maxCount < numberCount)
    {
        std::cout << startingNumber << " ";
        startingNumber++;
        maxCount++;
    }
    std::cout << "\nDone!" << std::endl;

    return 0;
}