/*
 * Alec Him
 * CS 135 - Worksheet 2
 * Description: Learn how to input data and use data for calculation output
 * Input: Two Integers
 * Output: Sum
 */
#include <iostream>

int main()
{
    int a = 0, b = 0, ans = 0;
    std::cout << "Enter two integers to sum: ";
    std::cin >> a >> b;

    ans = a + b;
    std::cout << "The sum of " << a << " + " << b << " = " << ans << std::endl;

    return 0;
}