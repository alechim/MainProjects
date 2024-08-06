/*
 * Alec Him
 * CS 135 - Lab 13
 * Description:
 * Input:
 * Output:
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

// Global Constants
const int WIDTH = 10;

struct basketballPlayer
{
    std::string firstName, lastName;
    int att2s, md2s, att3s, md3s, attFTs, mdFTs, height,points;
};

// Function Prototypes
void readRoster(basketballPlayer[], int&, std::string&);
int toCentimeters(int, int);
int getIndex(basketballPlayer[], int, std::string, std::string);
void recordPlay(basketballPlayer&, std::string, std::string);
void openFin(std::ifstream&, std::string);
void outputOnePlayer(basketballPlayer);
void printHeader(std::string, int);
void outputChar(int, char);
int tallyPoints(basketballPlayer[], int);
void bubbleSort(basketballPlayer[], int);

// Function Definitions
// - readRoster
void readRoster(basketballPlayer team[], int& rosterSize, std::string& teamName)
{
    std::ifstream fin;
    openFin(fin, "Enter team roster file name: ");
    rosterSize = 0;
    int feet, inches;
    getline(fin, teamName);
    while(fin >> team[rosterSize].firstName)
    {
        fin >> team[rosterSize].lastName;
        fin >> feet;
        fin.ignore(1, ' ');
        fin >> inches;
        fin.ignore(1, ' ');
        team[rosterSize].height = toCentimeters(feet, inches);
        team[rosterSize].md2s = 0;
        team[rosterSize].att2s = 0;
        team[rosterSize].md3s = 0;
        team[rosterSize].att3s = 0;
        team[rosterSize].mdFTs = 0;
        team[rosterSize].attFTs = 0;
        team[rosterSize].points = 0;
        rosterSize++;
    }
    fin.close();
}

// - getIndex
int getIndex(basketballPlayer team[], int size, std::string first, std::string last)
{
    for(int i = 0; i < size; i++)
    {
        if(first == team[i].firstName && last == team[i].lastName)
            return i;
    }
    return -1;
}

// - openFin
void openFin(std::ifstream& fin, std::string prompt)
{
    std::string fileName;
    do
    {
        std::cout << prompt;
        std::cin >> fileName;
        fin.open(fileName.c_str());
        if(!fin.is_open())
            std::cout << "Error: unable to open " << fileName << std::endl;
    } while(!fin.is_open());
    std::cout << fileName << " opened.\n\n";
}

// - outputOnePlayer
void outputOnePlayer(basketballPlayer player)
{
    std::cout << std::setw(WIDTH) << std::left << player.firstName << std::setw(WIDTH + 4) << std::left << player.lastName;
    std::cout << std::setw(WIDTH) << std::left << player.height;
    std::cout << std::setw(WIDTH) << std::left << std::to_string(player.md2s) + "-" + std::to_string(player.att2s);
    std::cout << std::setw(WIDTH) << std::left << std::to_string(player.md3s) + "-" + std::to_string(player.att3s);
    std::cout << std::setw(WIDTH) << std::left << std::to_string(player.mdFTs) + "-" + std::to_string(player.attFTs);
    std::cout << std::setw(WIDTH) << std::left << player.points << std::endl;
}

// - printHeader
void printHeader(std::string teamName, int teamScore)
{
    std::cout << std::endl << teamName << " " << teamScore << std::endl;
    outputChar(WIDTH * 7, '-');
    std::cout << std::endl << std::setw((WIDTH * 2) + 4) << std::left << "PLAYERS";
    std::cout << std::setw(WIDTH) << std::left << "HT";
    std::cout << std::setw(WIDTH) << std::left << "FG";
    std::cout << std::setw(WIDTH) << std::left << "3PT";
    std::cout << std::setw(WIDTH) << std::left << "FT";
    std::cout << std::setw(WIDTH) << std::left << "PTS" << std::endl;
    outputChar(WIDTH * 7, '-');
    std::cout << std::endl;
}

// - bubbleSort
void bubbleSort(basketballPlayer team[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(team[j].height < team[j + 1].height)
            {
                std::swap(team[j], team[j + 1]);
            }
        }
    }
}

// - recordPlay
void recordPlay(basketballPlayer& player, std::string attempt, std::string shot)
{
    if(shot == " Dunk." || shot == " Layup." || shot == " Jumper." || shot == " Two Point Tip Shot.")
    {
        player.att2s += 1;
        if(attempt == "made")
        {
            player.md2s += 1;
            player.points += 2;
        }
    } else if(shot == " Three Point Jumper."){
        player.att3s += 1;
        if(attempt == "made")
        {
            player.md3s += 1;
            player.points += 3;
        }
    } else if(shot == " Free Throw."){
        player.attFTs += 1;
        if(attempt == "made")
        {
            player.mdFTs += 1;
            player.points += 1;
        }
    }
}

// - toCentimeters
int toCentimeters(int feet, int inches)
{
    int ftToIn, cm;
    ftToIn = feet * 12;
    inches += ftToIn;
    cm = inches * 2.54;
    return cm;
}

// - outputChar
void outputChar(int count, char c)
{
    for(int i = 0; i < count; i++)
        std::cout << c;
}

// - tallyPoints
int tallyPoints(basketballPlayer team[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += team[i].points;
    return sum;
}

int main()
{
    // Variables
    // - Constant
    const int MAX_ROSTER_SIZE = 20;
    // - Away Team
    basketballPlayer awayTeam[MAX_ROSTER_SIZE];
    int awayTeamRosterSize = 0, awayTeamScore = 0;
    std::string awayTeamName;
    // - Home Team
    basketballPlayer homeTeam[MAX_ROSTER_SIZE];
    int homeTeamRosterSize = 0, homeTeamScore = 0;
    std::string homeTeamName;

    readRoster(awayTeam, awayTeamRosterSize, awayTeamName);
    readRoster(homeTeam, homeTeamRosterSize, homeTeamName);

    std::ifstream fin;
    openFin(fin, "Enter Play-by-Play file name: ");
    std::string first, last, attempt, shot;

    while(fin >> first)
    {
        fin >> last >> attempt;
        getline(fin, shot);
        int i = getIndex(awayTeam, awayTeamRosterSize, first, last);
        if(i >= 0)
        {
            recordPlay(awayTeam[i], attempt, shot);
        } else {
            int j = getIndex(homeTeam, homeTeamRosterSize, first, last);
            if(j >= 0)
            {
                recordPlay(homeTeam[j], attempt, shot);
            } else {
                std::cout << "Error: " << first << " " << last << " is not on any team.\n";
            }
        }
    }
    fin.close();

    awayTeamScore = tallyPoints(awayTeam, awayTeamRosterSize);
    homeTeamScore = tallyPoints(homeTeam, homeTeamRosterSize);
    bubbleSort(awayTeam, awayTeamRosterSize);
    bubbleSort(homeTeam, homeTeamRosterSize);
    std::cout << std::endl;

    // Display Results
    printHeader(awayTeamName, awayTeamScore);
    for(int i = 0; i < awayTeamRosterSize; i++)
        outputOnePlayer(awayTeam[i]);   
    std::cout << std::endl;

    printHeader(homeTeamName, homeTeamScore);
    for(int i = 0; i < homeTeamRosterSize; i++)
        outputOnePlayer(homeTeam[i]);   

    return 0;
}