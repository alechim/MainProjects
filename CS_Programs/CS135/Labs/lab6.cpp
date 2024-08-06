/*
 * Alec Him
 * CS 135 - Lab 6
 * Description: Calculates Max, Min, Sum, Average, and Range from a list
 * Input: Get-Content input6.txt | ./lab6.exe
 * Output: Max, Min, Sum, Average, and Range
 */
#include <iostream>
#include <fstream>

int main()
{
    // Variables
    int max = 0, min = 1000, range = 0, n = 0;
    double sum = 0.0, average = 0.0, count = 0.0;

    // Keep track of each number in the list
    std::cin >> n;
    while(std::cin)
    {
        sum += n;
        if(max < n)
            max = n;
        if(min > n)
            min = n;
        count++;
        std::cin >> n;
    }

    // Perform calculations
    average = sum / count;
    range = max - min;

    // Display results
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Range: " << range << std::endl;

    return 0;
}