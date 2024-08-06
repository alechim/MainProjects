/*
 * Alec Him
 * CS 135 - Worksheet 10
 * Description: Simple program that introduces functions
 * Input: Integer and String
 * Output: Name
 */
#include <iostream>

void writeName(int, std::string);

void writeName(int count, std::string name)
{
    while(count > 0)
    {
        std::cout << name << " ";
        count--;
    }
    std::cout << std::endl;
    return;
}

int main()
{
    // Variables
    int count = 0;
    std::string name = "";

    std::cout << "Enter a number and a name: ";
    std::cin >> count >> name;

    writeName(count, name);

    return 0;
}