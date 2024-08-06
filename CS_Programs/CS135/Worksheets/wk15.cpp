/*
 * Alec Him
 * CS 135 - Worksheet 15
 * Description: Simple program that demonstrates calling a function within another function
 * Input: Integer
 * Output: Chars and Reverse Chars
 */
#include <iostream>

void readChars(int, char data[25], int);
void printReverse(char data[25], int);

void readChars(int max, char data[25], int count)
{
    std::cout << "How many chars: ";
    std::cin >> count;
    if(max < count)
        std::cout << "Error - Max Chars is 25." << std::endl;
    else {
        for(int i = 0; i < count; i++)
            std::cout << data[i] << ' ';
        std::cout << std::endl;
    }
    printReverse(data, count);
}

void printReverse(char data[25], int count)
{
    for(int i = count - 1; i >= 0; i--)
        std::cout << data[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    int charCount = 0;
    char data[25] = {'a', '1', 'b', '2', 'c', '3', 'd', '4', 'e', '5', 'f', '6', 'g', '7', 'h', '8', 'i', '9', 'j', '1', 'k', '2', 'l', '3', 'm'};
    readChars(25, data, charCount);

    return 0;
}