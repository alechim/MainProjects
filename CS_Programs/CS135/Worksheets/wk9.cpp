/*
 * Alec Him
 * CS 135 - Worksheet 9
 * Description: Simple program that demonstrates reading from a file and error handling
 * Input: Integers
 * Output: Sum
 */
#include <iostream>
#include <fstream>

int main()
{
    // Variables
    std::string file = "w12Data.txt";
    std::ifstream iFile;
    int num1 = 0, num2 = 0;

    do{
        std::cout << "Enter filename: ";
        std::cin >> file;
        iFile.open(file);

        if(!iFile.is_open())
            std::cout << "Error - File did not open." << std::endl;
    } while(!iFile.is_open());

    while(!iFile.eof())
    {
        iFile >> num1 >> num2;
        if(iFile.fail())
        { 
            iFile.clear();
            iFile.ignore(40, '\n');
            std::cout << "Error - Non-integer input detected." << std::endl;
        } else {
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
        }

        if(iFile.eof())
            std::cout << "End of file reached, Exiting...\n";
    }

    return 0;
}