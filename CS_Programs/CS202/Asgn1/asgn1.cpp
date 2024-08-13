/*
 * Alec Him
 * CS 202 - Assignment 1
 * Description: Program that reads car data from a sv file, organizes the data and outputs to a new file in a more readable format
 * Input: 0 - 3, 0 - n unique car makes, & name of output file
 * Output: File of cars, file sorted by mpg or hp based on prior selected make
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// Structs
struct Car
{
    std::string make, model, origin;
    double mpg;
    unsigned int cylinders, displacement, horsepower, weight, year;
};

// Function Prototypes
int readFile(std::string, std::vector<Car>&);
void printCar(std::ostream&, const Car);
void sortListByMPG(std::vector<Car>&);
void sortListByHP(std::vector<Car>&);
void listByMakeMPG(const std::vector<Car>);
void listByMakeHP(const std::vector<Car>);
void saveToFile(const std::vector<Car>, std::string);
int selectionMenu();

// Function Definitions
/*
 * - printCar: outputs the file
 * @param std::ostream& out
 * @param const Car car
 */
void printCar(std::ostream& out, const Car car)
{
    out << "Make : " << car.make << "\n";
    out << "Model : " << car.model << "\n";
    out << "Fuel Efficiency (MPG) : " << car.mpg << "\n";
    out << "Cylinders : " << car.cylinders << "\n";
    out << "Displacement (cu) : " << car.displacement << "\n";
    out << "Horsepower (hp) : " << car.horsepower << "\n";
    out << "Model : " << car.year << "\n";
    out << "Origin : " << car.origin << "\n";
    out << "-=======================-\n";
}
/*
 * - readFile: reads in the input file 'car.sv' and stores values into the vector
 * @param string file
 * @param vector<Car>& carVector
 */
int readFile(std::string file, std::vector<Car>& carVector)
{
    std::string str;
    std::ifstream iFile(file);
    if(!iFile)
    {
        std::cout << "Error opening file: " << file << std::endl;
        return -1;
    }

    // Ignore the first line (header)
    std::getline(iFile, str);

    while(std::getline(iFile, str))
    {
        std::stringstream sstream(str);
        Car carType;
        std::getline(sstream, carType.make, ';');
        std::getline(sstream, carType.model, ';');
        sstream >> carType.mpg;
        sstream.ignore();
        sstream >> carType.cylinders;
        sstream.ignore();
        sstream >> carType.displacement;
        sstream.ignore();
        sstream >> carType.horsepower;
        sstream.ignore();
        sstream >> carType.weight;
        sstream.ignore();
        sstream >> carType.year;
        sstream.ignore();
        std::getline(sstream, carType.origin, ';');

        carVector.push_back(carType);
    }

    iFile.close();
    return carVector.size();
}   

/*
 * - selectionMenu: displays the prompt for user input and chooses coding path based on input
 * @return int
 */
int selectionMenu()
{
    int numChoice = 0;

    // Displays the Options for the User
    std::cout << "**** SELECT OPTION ****" << std::endl;
    std::cout << "1.  Sort by MPG" << std::endl;
    std::cout << "2.  Sort by Horsepower" << std::endl;
    std::cout << "3.  Save all cars to file" << std::endl;
    std::cout << "0.  Exit" << std::endl;
    std::cout << "***********************" << std::endl;

    // Prompts the user to end the previous choices
    do{
        std::cout << "Enter number: ";
        std::cin >> numChoice;

        // Checks if input is correct and reprompts user if invalid
        if(std::cin.fail() || numChoice < 0 || numChoice > 3)
        {
            std::cin.clear();
            std::cin.ignore(40, '\n');
            std::cout << "Error - please try again." << std::endl;
        }
    } while(std::cin.fail() || numChoice < 0 || numChoice > 3);

    return numChoice;
}

/*
 * - listByMakeMPG: displays the list of available car manufacturers by MPG and prompts user to select one
 * @param const vector<Car>& carVector
 */
void listByMakeMPG(const std::vector<Car> carVector)
{
    int select = 0;
    char confirm;
    std::vector<std::string> seen;
    std::string file = "";

    // Displays the options for the user
    std::cout << "Select Make:" << std::endl;

    for(int i = 0; i < carVector.size(); i++)
    {
        // If a make has not been seen, display it and store it in the vector
        if(std::find(seen.begin(), seen.end(), carVector[i].make) == seen.end())
        {
            std::cout << seen.size() + 1 << ". : " << carVector[i].make << std::endl;
            seen.push_back(carVector[i].make);
        }
    }
    
    // Prompts the user to enter a number for the make of the car
    do{
        std::cout << "\nEnter number: ";
        std::cin >> select;

        // Checks if input is correct and reprompts user if invalid
        if(std::cin.fail() || select < 1 || select > carVector.size())
        {
            std::cin.clear();
            std::cin.ignore(40, '\n');
            std::cout << "Error - please try again." << std::endl;
        } 
    } while(std::cin.fail() || select < 1 || select > carVector.size());
    
    std::vector<Car> sortVector;
    for(int i = 0; i < carVector.size(); i++)
        // Find all selected makes and add them to the sortVector
        if(carVector[i].make == carVector[select - 1].make)
            sortVector.push_back(carVector[i]);

    // Sort only cars made by the selected make
    sortListByMPG(sortVector);
    std::cout << "All cars made by " << carVector[select - 1].make << " sorted by MPG...\n\n";

    // Prompts user whether or not to save the file
    while(true)
    {
        std::cout << "Save to file? [y/n] : ";
        std::cin >> confirm;

        // Checks if input is correct and reprompts user if invalid
        switch(confirm)
        {
            case 'y':
            case 'Y':
                std::cout << "Enter filename: ";
                std::cin >> file;
                saveToFile(sortVector, file);
                std::cout << "All cars saved to file \"" << file << "\"" << std::endl;
                return;
            // Exits code
            case 'n':
            case 'N':
                return;
            default:
                std::cin.clear();
                std::cin.ignore(40, '\n');
                std::cout << "Error - please try again." << std::endl;
        }
    }
}

/*
 * - sortListByMPG: sorts the listByMakeMPG function by using a bubble sort
 * @param std::vector<Car>& carVector
 */
void sortListByMPG(std::vector<Car>& carVector)
{
    for(int i = 0; i < carVector.size() - 1; i++)
        for(int j = 0; j < carVector.size() - i - 1; j++)
            if(carVector[j].mpg > carVector[j + 1].mpg)
                std::swap(carVector[j], carVector[j + 1]);
}

/*
 * - listByMakeHP: displays the list of available car manufacturers by HP and prompts user to select one
 * @param const vector<Car>& carVector
 */
void listByMakeHP(const std::vector<Car> carVector)
{
    int select = 0;
    char confirm;
    std::vector<std::string> seen;
    std::string file = "";

    // Displays the options for the user
    std::cout << "Select Make: " << std::endl;
    for(int i = 0; i < carVector.size(); i++)
    {
        // If a make has not been seen, display it and store it in the vector
        if(std::find(seen.begin(), seen.end(), carVector[i].make) == seen.end())
        {
            std::cout << seen.size() + 1 << ". : " << carVector[i].make << std::endl;
            seen.push_back(carVector[i].make);
        }
    }

    // Prompts the user to enter a number for the make of the car
    do{
        std::cout << "\nEnter number : ";
        std::cin >> select;

        // Checks if input is correct and reprompts user if invalid 
        if(std::cin.fail() || select < 1 || select > 18)
        {
            std::cin.clear();
            std::cin.ignore(40, '\n');
            std::cout << "Error - please try again." << std::endl;
        } 
    } while(std::cin.fail() || select < 1 || select > 18);

    std::vector<Car> sortVector;
    for(int i = 0; i < carVector.size(); i++)
        // Find all selected makes and add them to the sortVector
        if(carVector[i].make == carVector[select - 1].make)
            sortVector.push_back(carVector[i]);

    // Sort only cars made by the selected make
    sortListByHP(sortVector);
    std::cout << "All cars made by " << carVector[select].make << " sorted by HP...\n\n";

    // Prompts user whether or not to save the file
    while(true)
    {
        std::cout << "Save to file? [y/n] : ";
        std::cin >> confirm;

        // Checks if input is correct and reprompts user if invalid
        switch(confirm)
        {
            // Prompts users to save the file, then exits the program
            case 'y':
            case 'Y':
                std::cout << "Enter filename: ";
                std::cin >> file;
                saveToFile(sortVector, file);
                std::cout << "All cars saved to file \"" << file << "\"" << std::endl;
                return;
            // Exits code
            case 'n':   
            case 'N':
                return;
            default:
                std::cin.clear();
                std::cin.ignore(40, '\n');
                std::cout << "Error - please try again." << std::endl;
        }
    }
}

/*
 * - sortListByHP: sorts the listByMakeHP function by using a bubble sort
 * @param std::vector<Car>& carVector
 */
void sortListByHP(std::vector<Car>& carVector)
{
    for(int i = 0; i < carVector.size() - 1; i++)
        for(int j = 0; j < carVector.size() - i - 1; j++)
            if(carVector[j].horsepower > carVector[j + 1].horsepower)
                std::swap(carVector[j], carVector[j + 1]);
}

/*
 * - saveToFile: prompts the user to name the file and saves the file on the computer
 * @param const std::vector<Car>& carVector
 * @param std::string saveFile
 */
void saveToFile(const std::vector<Car> carVector, std::string saveFile)
{
    std::ofstream oFile;
    oFile.open(saveFile);

    oFile << "-=======================-\n";
    for(int i = 0; i < carVector.size(); i++)
        printCar(oFile, carVector[i]);
}

int main(int argc, char *argv[])
{
    std::vector<Car> cars;
    int n_cars, ch;
    std::string filename;

    if(argc != 2)
    {
        std::cout << "ERROR: Invalid Arguments \nUsage: .\\asgn1 <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    n_cars = readFile(std::string(argv[1]), cars);
    std::cout << "Read " << n_cars << " cars from file." << std::endl;

    do{
        ch = selectionMenu();
        switch(ch)
        {
            case 1:
                listByMakeMPG(cars);
                break;
            case 2:
                listByMakeHP(cars);
                break;
            case 3:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                saveToFile(cars, filename);
                std::cout << "All cars saved to file \"" << filename << "\"" << std::endl;
                break;
            default:
                break;
        }
        return EXIT_SUCCESS;
    } while(ch != 0);
}