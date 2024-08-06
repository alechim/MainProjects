/*
 * Alec Him
 * CS 135 - Lab 4
 * Description: Simple Arithmetic Calculator
 * Input: Integers and Operand
 * Output: Results of Adding, Subtracting, Multiplying, and Dividing
 */
#include <iostream>

int main()
{
    double num1 = 0.0, num2 = 0.0;
    char operand;

    // Prompt user for input 1
    std::cout << "Input first value: ";
    std::cin >> num1;
    if(std::cin.fail())
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    // Prompt user for input 2
    std::cout << "Input second value: ";
    std::cin >> num2;
    if(std::cin.fail())
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    // Prompt user for operand
    std::cout << "Operation to perform (+, -, *, /): ";
    std::cin >> operand;

    switch(operand)
    {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
            break;
        case '/':
            std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            return 1;
    }

    return 0;
}