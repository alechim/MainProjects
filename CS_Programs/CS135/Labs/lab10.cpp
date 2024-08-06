/*
 * Alec Him
 * CS 135 - Lab 10
 * Description: Fortnite-inspired map generator with players and randomly generated shrinkstorms
 * Input: F/B/H & Enter key
 * Output: Display of map and players
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>

// Global Constants
const int MAX_MAP_HEIGHT = 50;
const int MAX_MAP_WIDTH = 50;

// Function Prototypes
int getNumPlayers(char[][MAX_MAP_WIDTH], int, int);
void load(char[][MAX_MAP_WIDTH], int&, int&, int&, int&, int&);
void drop(char[][MAX_MAP_WIDTH], int, int, int);
void shrinkStorm(char[][MAX_MAP_WIDTH], int, int, int, int, int&);
void render(char[][MAX_MAP_WIDTH], int, int);

// Function Definitions
// Render: Creates the outline/screen space for the map
void render(char screenSpace[][MAX_MAP_WIDTH], int rows, int cols)
{
    std::string border;
    border.append(cols + 2, '_');

    std::cout << border << std::endl;
    for(int r = 0; r < rows; r++)
    {
        std::cout << "|";
        for(int c = 0; c < cols; c++)
            std::cout << screenSpace[r][c];
        std::cout << "|\n";
    }
    std::cout << border << std::endl;
}

// Load: Decides how many players and size of the map are executed based on user input
void load(char map[][MAX_MAP_WIDTH], int& rows, int& cols, int& playerCount, int& eyeR, int& eyeC)
{
    // Variables
    const int FL_HEIGHT = 20;       // size of Farmland
    const int FL_WIDTH = 40;
    const int BY_HEIGHT = 15;       // size of Boneyard
    const int BY_WIDTH = 30;
    const int HP_HEIGHT = 10;       // size of Hospital
    const int HP_WIDTH = 20;

    const int FL_PC = 26;       // players in Farmland
    const int BY_PC = 15;       // players in Boneyard
    const int HP_PC = 10;       // players in Hospital

    char marker;

    // Display and prompt user for input
    std::cout << "Where we droppin bois?\n";
    std::cout << "[F]armland\n";
    std::cout << "[B]oneyard\n";
    std::cout << "[H]ospital\n";
    std::cout << "Enter your choice: ";
    std::cin >> marker;
    std::cin.ignore(256, '\n');

    switch(marker)
    {
        case 'F':
        case 'f':
            rows = FL_HEIGHT;
            cols = FL_WIDTH;
            playerCount = FL_PC;
            break;
        case 'B':
        case 'b':
            rows = BY_HEIGHT;
            cols = BY_WIDTH;
            playerCount = BY_PC;
            break;
        case 'H':
        case 'h':
        default:
            rows = HP_HEIGHT;
            cols = HP_WIDTH;
            playerCount = HP_PC;
            break;
    }

    eyeR = rand() % rows;
    eyeC = rand() % cols;

    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            map[r][c] = ' ';
        }
    }
}

// getNumPlayers: Detects how many players are left in the map
int getNumPlayers(char map[][MAX_MAP_WIDTH], int rows, int cols)
{
    int count = 0;
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(map[r][c] != ' ' && map[r][c] != '*')
            {
                count++;
            }
        }
    }

    return count;
}

// Drop: Sets random position of players on the map
void drop(char map[][MAX_MAP_WIDTH], int rows, int cols, int playerCount)
{
    char player = 'A';
    int drops = 0;

    while(drops < playerCount)
    {
        int r = rand() % rows;
        int c = rand() % cols;

        if(map[r][c] == ' ')
        {
            map[r][c] = player;
            player++;
            drops++;
        }
    }
}

// shrinkStorm: encloses the size of the map by creating a radius
void shrinkStorm(char map[][MAX_MAP_WIDTH], int rows, int cols, int eyeR, int eyeC, int& radius)
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(map[r][c] != '*')
            {
                double distance = sqrt(pow(c - eyeC, 2) + pow(r - eyeR, 2));
                if(distance > radius)
                    map[r][c] = '*';
            }
        }
    }
    radius--;
}

int main()
{
    // Variables
    srand(time(0));
    char map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
    int height, width, playerCount, eyeR, eyeC, radius;
    char tmp;

    load(map, height, width, playerCount, eyeR, eyeC);
    render(map, height, width);
    drop(map, height, width, playerCount);
    radius = width;

    while(playerCount > 1)
    {
        std::cout << "Hit enter to continue";
        std::cin.get(tmp);
        shrinkStorm(map, height, width, eyeR, eyeC, radius);
        playerCount = getNumPlayers(map, height, width);
        render(map, height, width);
    }

    return 0;
}