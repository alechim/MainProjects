/*
 * Alec Him
 * CS 135 - Assignment 10
 * Description: Program that plays a game where there are four main variables that decide the winner
 * Input: 1a-e, 2a-e, 3a-e, 4a-e, 5a-e
 * Output: Wilderness, Popularity, Ecology, Commerce, Industry
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Constant Variables
const int RESOURCE_TYPES = 4, UPGRADE_COUNT = 6;
enum resourceTypes{POPULARITY, ECOLOGY, COMMERCE, INDUSTRY};
// - Colony Array is Height x Width
const int COLONY_HEIGHT = 4, COLONY_WIDTH = 5;

// Structs
// - improvement: Used to represent improvement that can be placed in a sector.
struct improvement
{
    std::string name;
    // Hold values for the 4 resource types & descibes how much of a resource this improvement can extract from its sector.
    int collects[RESOURCE_TYPES];
    // Holds values for the 4 resource types & describes how much of a bonus or penalty is applied to the sector when constructed.
    int develops[RESOURCE_TYPES];
};

// - sector
struct sector
{
    // Tracks how much of the four resources are available in the sector.
    int resources[RESOURCE_TYPES];
    improvement zone;
};

improvement zone;
sector colony[COLONY_HEIGHT][COLONY_WIDTH];

// Function Prototypes
void printColony(const sector[][COLONY_WIDTH]);
void getResourceTotals(sector[][COLONY_WIDTH], int[], int);
int getScore(int resources[], int resourceCount);
void placeImprovement(sector[][COLONY_WIDTH], improvement, int, int);

// Function Definitions
// - printColony
void printColony(const sector colony[][COLONY_WIDTH])
{
    for(int i = 0; i < COLONY_HEIGHT; i++)
    {
        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            std::cout << "+----" << i + 1 << static_cast<char>('A' + j);
            std::cout << "----+ ";
        }
        std::cout << std::endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            std::cout << "|";
            unsigned int spaces = 10 - colony[i][j].zone.name.length();
            for(unsigned int k = 0; k < spaces / 2; k++)
                std::cout << " ";

            std::cout << colony[i][j].zone.name;
            for(unsigned int k = 0; k < spaces / 2; k++)
                std::cout << " ";
            std::cout << "| ";
        }
        std::cout << std::endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            std::cout << "|POP: " << colony[i][j].zone.collects[POPULARITY];
            std::cout << " x" << std::setw(2) << colony[i][j].resources[POPULARITY] << "| ";
        }
        std::cout << std::endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            std::cout << "|ECO: " << colony[i][j].zone.collects[ECOLOGY];
            std::cout << " x" << std::setw(2) << colony[i][j].resources[ECOLOGY] << "| ";
        }
        std::cout << std::endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            std::cout << "|COM: " << colony[i][j].zone.collects[COMMERCE];
            std::cout << " x" << std::setw(2) << colony[i][j].resources[COMMERCE] << "| ";
        }
        std::cout << std::endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            std::cout << "|IND: " << colony[i][j].zone.collects[INDUSTRY];
            std::cout << " x" << std::setw(2) << colony[i][j].resources[INDUSTRY] << "| ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < COLONY_WIDTH; i++)
        std::cout << "+----------+ ";
    std::cout << std::endl;
}

// - getResourceTotals
void getResourceTotals(sector colony[][COLONY_WIDTH], int resourceTotals[], int resourceCount)
{
    for(int i = 0; i < resourceCount; i++)
        resourceTotals[i] = 0;
    
    for(int r = 0; r < COLONY_HEIGHT; r++)
        for(int c = 0; c < COLONY_WIDTH; c++)
            for(int i = 0; i < resourceCount; i++)
                resourceTotals[i] += colony[r][c].zone.collects[i] * colony[r][c].resources[i];
}

// - getScore
int getScore(int resources[], int resourceCount)
{
    int finalScore = 0, lowestResource = 10000;
    if(resources[POPULARITY] < 0)
        resources[POPULARITY] = 0;
    
    for(int i = 0; i < resourceCount; i++)
        if(resources[i] < 0)
        {
            lowestResource = 0;
            break;
        } else if(resources[i] < lowestResource){
            lowestResource = resources[i];
        }
    
    finalScore = resources[POPULARITY] * lowestResource;

    return finalScore;
}

// - placeImprovement
void placeImprovement(sector colony[][COLONY_WIDTH], improvement newZone, int x, int y)
{
    for(int k = 0; k < RESOURCE_TYPES; k++)
        colony[y][x].zone.develops[k] = 0;
    
    for(int k = 0; k < RESOURCE_TYPES; k++)
        for(int i = y - 1; i <= y + 1; i++)
            for(int j = x - 1; j <= x + 1; j++)
                if(i >= 0 && i < COLONY_HEIGHT && j >= 0 && j < COLONY_WIDTH)
                    colony[i][j].resources[k] += newZone.develops[k];
    colony[y][x].zone = newZone;
}

int main()
{
    // Variables
    sector colony[COLONY_HEIGHT][COLONY_WIDTH];
    int resourceTotals[RESOURCE_TYPES];

    // Sector Improvements
    improvement upgrades[UPGRADE_COUNT];
    upgrades[0] = {"Wilderness", {0, 0, 0, 0}, {0, 0, 0, 0}};
    upgrades[1] = {"Settlement", {1, 1, 1, 1}, {0, 0, 0, 0}};
	upgrades[2] = {"Farm", {0, 2, 0, 0}, {1, 1, -1, -1}};
	upgrades[3] = {"Mine", {0, 0, 0, 2}, {-1, -1, 1, 1}};
	upgrades[4] = {"City", {0, 0, 2, 0}, { 0, -1, 2, -1}};
	upgrades[5] = {"Resort", {2, 0, 0, 0}, { 1, 1, 0, -2}};

    // Seed Random Number Generator
    srand(time(NULL));

    // Initialize sector resource values to random amounts from 0-3
    for(int i = 0; i < COLONY_HEIGHT; i++)
        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            colony[i][j].zone = upgrades[0];
            for(int k = 0; k < RESOURCE_TYPES; k++)
            {
                int randomAmount = rand() % 100;
                if(randomAmount >= 95)
                    colony[i][j].resources[k] = 3;
                else if(randomAmount >= 80)
                    colony[i][j].resources[k] = 2;
                else if(randomAmount >= 50)
                    colony[i][j].resources[k] = 1;
                else
                    colony[i][j].resources[k] = 0;
            }
        }
    
    // Allows user to select 12 improvements to the colony then provides a final score
    for(int i = 12; i > 0; i--)
    {
        // Colony Status
        printColony(colony);
        getResourceTotals(colony, resourceTotals, RESOURCE_TYPES);

        std::cout << "Colony Status: ";
        std::cout << "[" << resourceTotals[POPULARITY] << " Popularity] ";
        std::cout << "[" << resourceTotals[ECOLOGY] << " Ecology] ";
        std::cout << "[" << resourceTotals[COMMERCE] << " Commerce] ";
        std::cout << "[" << resourceTotals[INDUSTRY] << " Industry]";
        std::cout << "\nCurrent Score: " << getScore(resourceTotals, RESOURCE_TYPES) << std::endl;

        // Improvement Selection Menu
        std::cout << "Place Improvement (" << i << "/12)\n";
        std::cout << "[1] Settlement (Px1 Ex1 Cx1 Ix1)(P 0 E 0 C 0 I 0)\n";
        std::cout << "[2] Farm       (Px0 Ex2 Cx0 Ix0)(P+1 E+1 C-1 I-1)\n";
        std::cout << "[3] Mine       (Px0 Ex0 Cx0 Ix2)(P-1 E-1 C+1 I+1)\n";
        std::cout << "[4] City       (Px0 Ex0 Cx2 Ix0)(P 0 E-1 C+2 I-1)\n";
        std::cout << "[5] Resort     (Px2 Ex0 Cx0 Ix0)(P+1 E+1 C 0 I-2)\n";
    
        // User Selects Improvement to Build
        int zoneType = 0;
        do{
            std::cout << "Select improvement to construct (1-" << UPGRADE_COUNT - 1 << "): ";
            std::cin >> zoneType;

            if(std::cin.fail())
            {
                std::cout << "Invalid improvement type, please try again.\n";
                std::cin.clear();
                std::cin.ignore(40, '\n');
            }
        } while(zoneType <= 0 || zoneType > UPGRADE_COUNT);
        std::cin.ignore(100000, '\n');

        // User Selects Location to Build Improvement
        std::string location;
        int x, y;
        do{
            std::cout << "Construct " << upgrades[zoneType].name << " location: ";
            std::cin >> location;

            if(location.length() == 2)
            {
                // Allows location to be selected with either lower or upper case coordinate value
                if(location[1] >= 'a' && location[1] <= 'z')
                    location[1] -= 'a' - 'A';
                
                // Converts user input to coordinates
                x = location[1] - 'A';
                y = location[0] - '1';

                // Ensures coordinates are within the colony bounds
                if(y >= 0 && y < COLONY_HEIGHT && x >= 0 && x < COLONY_WIDTH)
                    break;
                else
                    std::cout << "Invalid location, please try again.\n";
            } else
                std::cout << "Invalid location, please try again.\n";
        } while(true);
        std::cin.ignore(100000, '\n');

        placeImprovement(colony, upgrades[zoneType], x, y);
    }

    // Final Status of Colony
    printColony(colony);
    getResourceTotals(colony, resourceTotals, RESOURCE_TYPES);

    std::cout << "\nFinished Colony: ";
	std::cout << "[" << resourceTotals[POPULARITY] << " Popularity] ";
	std::cout << "[" << resourceTotals[ECOLOGY] << " Ecology] ";
	std::cout << "[" << resourceTotals[COMMERCE] << " Commerce] ";
	std::cout << "[" << resourceTotals[INDUSTRY] << " Industry] ";
	std::cout << "\nFinal Score: " << getScore(resourceTotals, RESOURCE_TYPES) << std::endl;

    return 0;
}