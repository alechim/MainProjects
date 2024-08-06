/*
 * Alec Him
 * CS 135 - Worksheet 14
 * Description: Simple program that reads off a file of integers and calculates the average
 * Input: None
 * Output: Average
 */
#include <iostream>
#include <fstream>

int main()
{
    // Variables
    std::string file = "w14Data.txt";
    std::ifstream iFile;
    double num = 0.0, avg = 0.0, sum = 0.0;
    int count = 0;
    double num2[100]; 

    iFile.open(file);
    if(!iFile.is_open())
        std::cout << "Error - File did not open." << std::endl;
    for(int i = 0; !iFile.eof(); i++)
    {
        iFile >> num;
        num2[i] = num;
        sum += num2[i];
        count++;
    } 
    
    avg = sum / count;
    std::cout << "The average is: " << avg << std::endl;

    return 0;
}