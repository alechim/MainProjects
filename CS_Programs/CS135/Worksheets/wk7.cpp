/*
 * Alec Him
 * CS 135 - Worksheet 7
 * Description: Simple program that demonstrates for, while, and do-while loops
 * Input: None
 * Output: Outputs of for, while, and do-while
 */
#include <iostream>

int main()
{
    int limit = 0;

    std::cout << "For Loop\n";
    for(limit = 0; limit < 5; limit++)
        std::cout << "Hello ";

    limit = 0;
    std::cout << "\n\nWhile Loop\n";
    while(limit < 5)
    {
        std::cout << "Hello ";
        limit++;
    }

    limit = 0;
    std::cout << "\n\nDo-While Loop\n";
    do{
        std::cout << "Hello ";
        limit++;
    } while(limit < 5);

    std::cout << std::endl;

    return 0;
}