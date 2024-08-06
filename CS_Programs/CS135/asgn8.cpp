/*
 * Alec Him
 * CS 135 - Assignment 8
 * Description: Creates shapes based on content from input file
 * Input: AS8Data.txt
 * Output: oFiles that contain shapes
 */
#include <iostream>
#include <iomanip>
#include <fstream>

// Function Prototypes
void openInputFile(std::ifstream&, std::string);
bool openOutputFile(std::ofstream&, std::string);
void outputChar(std::ofstream&, int, char);
void makeEight(std::ofstream&, int, char);
void makeTriangle(std::ofstream&, int, char);
void makeSlash(std::ofstream&, int, char);
std::string createOutputFilename(std::string, int);
bool readRecord(std::ifstream&, std::string&, int&, char&);

// Function Definitions
// - readRecord: reads iFile inputs and tests whether or not hte eof is true
bool readRecord(std::ifstream& iFile, std::string& typeString, int& lSize, char& c)
{
    bool confirm = true;
    iFile >> typeString >> lSize >> c;
    if(iFile.eof())
        confirm = false;
    return confirm;
}

// - createOutputFilename: combines both type and size into string to create oFile name
std::string createOutputFilename(std::string typeString, int labelSize)
{
    std::string outputFile = "", numStr = std::to_string(static_cast<long long>(labelSize));
    outputFile = typeString + "_" + numStr + ".txt";
    return outputFile;
}

// - openInputFile: prompts user for input file name until correct iFile is opened
void openInputFile(std::ifstream& iFile, std::string prompt)
{
    prompt = "AS8Data.txt";
    do{
        iFile.open(prompt);
        if(!iFile.is_open())
            std::cout << "Error - File did not open.\n";
    } while(!iFile.is_open());
}

// - openOutputFile: verifies whether oFile is opened
bool openOutputFile(std::ofstream& oFile, std::string fname)
{
    bool confirm = true;
    oFile.open(fname);
    if(!oFile.is_open())
        confirm = false;
    return confirm;
}

// - makeEight: creates a figure 8 shape based on iFile and displays it in oFile 
void makeEight(std::ofstream& oFile, int size, char c)
{
    int height = size, width = size;
    int edgeWidth = size / 10;
    int rowCount = edgeWidth / 2;

    oFile << "Symbol: Figure Eight";
    oFile << "  Size: " << size;
    oFile << "  Character: \'" << c << "\'";
    oFile << std::endl;
    oFile << "    ";

    // Print header row with numbers
    for(int w = 1; w <= width; w++)
        oFile << w % 10;
    oFile << std::endl << std::endl;

    // Print figure eight shape
    for(int h = 1; h <= height; h++)
    {
        // Print number row
        oFile << std::setw(2) << h % 10 << "  ";
        
        // Print line for figure eight
        if(h == 1 || h == (height / 2) || h == height)
        {
            oFile << " ";
            outputChar(oFile, height - (edgeWidth * 2), c);
        // Print edges for figure eight
        } else {
            outputChar(oFile, edgeWidth, c);
            oFile << std::setw(width - edgeWidth);
            outputChar(oFile, edgeWidth, c);
        }
        oFile << std::endl;
    }

    oFile << std::endl;
    oFile << "    ";

    // Print footer row with numbers
    for(int w = 1; w <= width; w++)
        oFile << w % 10;
}

// - outputChar: determines which character and the amount that is used in each file
void outputChar(std::ofstream& oFile, int count, char c)
{
    for(int i = 0; i < count; i++)
        oFile << c;
} 

// - makeTriangle: creates a triangle shape based on iFile and displays it in oFile
void makeTriangle(std::ofstream& oFile, int size, char c)
{
    int height = size, width = (2 * size) - 1;

    // Set minimum size to 10 if it is less than 10
    if(size < 10)
        size = 10;
    
    oFile << "Symbol: Triangle";
    oFile << "  Size: " << size;
    oFile << "  Character: \'" << c << "\'";
    oFile << std::endl;
    oFile << "    ";

    // Print header row with numbers
    for(int w = 1; w <= width; w++)
        oFile << w % 10;
    oFile << std::endl << std::endl;

    // Print triangle shape
    for(int h = 1; h <= height; h++)
    {
        // Print number row
        oFile << std::setw(2) << h % 10 << "  ";

        for(int p = 0; p < ((width - (2 * (h - 1))) / 2); p++)
            oFile << " ";
        outputChar(oFile, (2 * h) - 1, c);
        oFile << std::endl;
    }
    oFile << std::endl;
    oFile << "    ";

    // Print footer row with numbers
    for(int w = 1; w <= width; w++)
        oFile << w % 10;
}

// - makeSlash: creates a slash based on iFile and displays it in oFile
void makeSlash(std::ofstream& oFile, int size, char c)
{
    char slash[100][100];
    int height = size, width = size;
    int count = 1;

    oFile << "Symbol: Slash";
    oFile << "  Size: " << size;
    oFile << "  Character: \'" << c << "\'";
    oFile << std::endl;
    oFile << "    ";

    // Print header row with numbers
    for(int w = 1; w <= width; w++)
        oFile << w % 10;
    oFile << std::endl << std::endl;

    // Print slash shape
    for(int h = 1; h <= height; h++)
    {
        // Print number row
        oFile << std::setw(2) << h % 10 << "  ";

        for(int p = 1; p < h; p++)
            oFile << " ";
        outputChar(oFile, 1, c);
        oFile << std::endl;
    }

    oFile << std::endl;
    oFile << "    ";

    // Print footer row with numbers
    for(int w = 1; w <= width; w++)
        oFile << w % 10;
}

int main()
{
    std::ifstream iFile;
    std::ofstream oFile;
    std::string ofName = "", typeString = "";
    int labelSize = 0, recordCount = 0;
    char labelChar = 0;
    bool done = false;

    std::cout << "Welcome to Rebel Alliance Computational Support\n";
    std::cout << "\t            x\n";
    std::cout << "\t      x    xxx    x\n";
    std::cout << "\t     x    x x x    x\n";
    std::cout << "\t    x      xxx      x\n";
    std::cout << "\t   xx       x       xx\n";
    std::cout << "\t  xxx      xxx      xxx\n";
    std::cout << "\t  xxxx     xxx     xxxx\n";
    std::cout << "\t  xxxxx    xxx   xxxxx\n";
    std::cout << "\t   xxxxxxxxxxxxxxxxxxx\n";
    std::cout << "\t    xxxxxxxxxxxxxxxxx\n";
    std::cout << "\t     xxxxxxxxxxxxxxx\n";
    std::cout << "\t       xxxxxxxxxxx\n\n\n";

    // Open input file
    openInputFile(iFile, "Input Specification File: ");

    // Read all records from the specification file
    while(true)
    {
        // Read all records from the file
        done = readRecord(iFile, typeString, labelSize, labelChar);
        // Verify that it worked, if not exit.
        if(!done)
        {
            std::cout << "Finished processing input file.\n";
            std::cout << recordCount << " Shapes Created \n";
            iFile.close();
            oFile.close();
            exit(0);
        }
        recordCount++;
        // Create the output file
        ofName = createOutputFilename(typeString, labelSize);
        
        // Open the output file
        if(!openOutputFile(oFile, ofName))
        {
            // Report that the file did not open
            std::cout << "Output file \"" << ofName << "\" did not open.\n";
            std::cout << "File \"" << ofName << "\" not generated.\n";
        } else {
            // Report that the file was successfully opened
            std::cout << "File \"" << ofName << "\" successfully opened.\n";
            
            // Call the appropriate function
            if(typeString == "figureEight")
                makeEight(oFile, labelSize, labelChar);
            else if(typeString == "triangle")
                makeTriangle(oFile, labelSize, labelChar);
            else if(typeString == "slash")
                makeSlash(oFile, labelSize, labelChar);
        }
        // Close the shape file so that we can reuse oFile variable
        oFile.close();
    }
    
    return 0;
}