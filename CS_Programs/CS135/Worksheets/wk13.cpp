/*
 * Alec Him
 * CS 135 - Worksheet 13
 * Description: Simple program that compares two numbers and strings
 * Input: char, int, and string
 * Output: Larger Number or String
 */
#include <iostream>

int larger(int, int);
std::string larger(std::string, std::string);

int larger(int num1, int num2)
{
    int large = 0;
    if(num1 > num2)
        large = num1;
    else
        large = num2;
    return large;
}

std::string larger(std::string str1, std::string str2)
{
    std::string large = "";
    if(str1.length() > str2.length())
        large = str1;
    else
        large = str2;
    return large;
}

int main()
{
    // Variables
    char c;
    int num1 = 0, num2 = 0, largeNum = 0;
    std::string str1 = "", str2 = "", largeStr = "";

    std::cout << "Please select i/I/S/s: ";
    std::cin >> c;
    switch(c)
    {
        case 'i':
        case 'I':
            std::cout << "Please enter two integers: ";
            std::cin >> num1 >> num2;
            largeNum = larger(num1, num2);
            std::cout << "The larger number is: " << largeNum << std::endl;
            break;
        case 's':
        case 'S':
            std::cout << "Please enter two strings: ";
            std::cin >> str1 >> str2;
            largeStr = larger(str1, str2);
            std::cout << "The larger string is: " << largeStr << std::endl;
            break;
        default:
            std::cout << "Invalid input." << std::endl;
    }

    return 0;
}