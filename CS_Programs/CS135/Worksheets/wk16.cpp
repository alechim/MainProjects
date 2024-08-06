/*
 * Alec Him
 * CS 135 - Worksheet 16
 * Description: Simple program that handles a 2D array of ints and outputs the sum of each row
 * Input: String
 * Output: Sum of each row
 */
#include <iostream>
#include <iomanip>
#include <fstream>

void rowSumCalculator(int myArrayp[][10], int rowCount, int colCount);
void openFile(std::ifstream& iFile, std::string prompt);

void openFile(std::ifstream& iFile, std::string fileName)
{
    do{
        std::cout << "Enter file to process: ";
        std::cin >> fileName;
        iFile.open(fileName);
        if(!iFile.is_open())
            std::cout << "Error - \"" << fileName << "\" did not open.\n";
    } while(!iFile.is_open());
}

void rowSumCalculator(int array[][10], int row, int col)
{
    // Variables
    int sum = 0;
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            std::cout << array[r][c];
            if(c != col - 1)
                std::cout << " + ";
            sum += array[r][c];
        }
        std::cout << " = " << sum << std::endl;
        sum = 0;
    }
}

int main()
{
    // Variables
    std::ifstream iFile;
    std::string file = "";
    int array[7][10];
    int row = 7, col = 10;

    openFile(iFile, file);
    if(iFile.is_open())
    {
        while(!iFile.eof())
            for(int r = 0; r < row; r++)
                for(int c = 0; c < col; c++)
                    iFile >> array[r][c];
    }
    rowSumCalculator(array, row, col);

    return 0;
}