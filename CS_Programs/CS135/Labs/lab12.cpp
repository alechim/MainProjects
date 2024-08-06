/*
 * Alec Him
 * CS 135 - Lab 12
 * Description: Takes in a 
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

// Function Prototypes
void readRoster(std::string[], std::string[], int[], int&, std::string&);
int toCentimeters(int, int);
int getIndex(std::string[], std::string[], int, std::string, std::string);
void recordPlay(int[], int[], int[], int[], int[], int[], int[], int, std::string, std::string);
void openFin(std::ifstream&, std::string);
void outputOnePlayer(std::string[], std::string[], int[], int[], int[], int[], int[], int[], int[], int[], int);
void printHeader(std::string, int);
void outputChar(int, char);
int getSum(int[], int);
void bubbleSort(std::string[], std::string[], int[], int[], int[], int[], int[], int[], int[], int[], int);

// Function Definitions
// - readRoster
void readRoster(std::string firsts[], std::string lasts[], int heights[], int& rosterSize, std::string& teamName)
{
    std::ifstream fin;
    openFin(fin, "Enter team roster file name: ");
    rosterSize = 0;
    int feet, inches;
    getline(fin, teamName);

    while(fin >> firsts[rosterSize])
    {
        fin >> lasts[rosterSize];
        fin >> feet;
        fin.ignore(1, ' ');
        fin >> inches;
        fin.ignore(1, ' ');
        heights[rosterSize] = toCentimeters(feet, inches);
        rosterSize++;
    }

    fin.close();
}

// - getIndex
int getIndex(std::string firstNames[], std::string lastNames[], int size, std::string first, std::string last)
{
    for(int i = 0; i < size; i++)
    {
        if(first == firstNames[i] && last == lastNames[i])
            return i;
    }
    return -1;
}

// - openFin
void openFin(std::ifstream& fin, std::string prompt)
{
    std::string fileName;
    do{
        std::cout << prompt;
        std::cin >> fileName;
        fin.open(fileName.c_str());
        if(!fin.is_open())
            std::cout << "Error: unable to open " << fileName << std::endl << std::endl;
    } while(!fin.is_open());
    std::cout << fileName << " opened.\n\n";
}

// - outputOnePlayer
void outputOnePlayer(std::string firsts[], std::string lasts[], int heights[], int att2s[], int md2s[], int att3s[], int md3s[], int attFTs[], int mdFTs[], int points[], int i)
{
    std::cout << std::setw(WIDTH) << std::left << firsts[i] << std::setw(WIDTH + 8) << std::left << lasts[i];
    std::cout << std::setw(WIDTH - 1) << std::left << std::to_string(md2s[i]) + "-" + std::to_string(att2s[i]);
    std::cout << std::setw(WIDTH + 1) << std::left << std::to_string(md3s[i]) + "-" + std::to_string(att3s[i]);
    std::cout << std::setw(WIDTH) << std::left << std::to_string(mdFTs[i]) + "-" + std::to_string(attFTs[i]);
    std::cout << std::setw(WIDTH) << std::left << points[i] << std::endl;
}

// - printHeader
void printHeader(std::string teamName, int teamScore)
{
    std::cout << std::endl << teamName << " " << teamScore << std::endl;
    outputChar(WIDTH * 6, '-');
    std::cout << std::endl << std::setw(WIDTH * 2) << std::left << "PLAYERS";
    std::cout << std::setw(WIDTH) << std::right << "FG";
    std::cout << std::setw(WIDTH) << "3PT";
    std::cout << std::setw(WIDTH) << "FT";
    std::cout << std::setw(WIDTH) << "PTS" << std::endl;
    outputChar(WIDTH * 6, '-');
    std::cout << std::endl;
}

// - bubbleSort
void bubbleSort(std::string firsts[], std::string lasts[], int heights[], int att2s[], int md2s[], int att3s[], int md3s[], int attFTs[], int mdFTs[], int points[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(points[j] < points[j + 1])
            {
                std::swap(firsts[j], firsts[j + 1]);
                std::swap(lasts[j], lasts[j + 1]);
                std::swap(heights[j], heights[j + 1]);
                std::swap(att2s[j], att2s[j + 1]);
                std::swap(md2s[j], md2s[j + 1]);
                std::swap(att3s[j], att3s[j + 1]);
                std::swap(md3s[j], md3s[j + 1]);
                std::swap(attFTs[j], attFTs[j + 1]);
                std::swap(mdFTs[j], mdFTs[j + 1]);
                std::swap(points[j], points[j + 1]);
            }
        }
    }
}

// - recordPlay
void recordPlay(int att2s[], int md2s[], int att3s[], int md3s[], int attFTs[], int mdFTs[], int points[], int i, std::string attempt, std::string shot)
{
    if(shot == " Dunk." || shot == " Layup." || shot == " Jumper." || shot == " Two Point Tip Shot.")
    {
        att2s[i]++;
        if(attempt == "made")
        {
            md2s[i]++;
            points[i] += 2;
        }
    } else if(shot == " Three Point Jumper."){
        att3s[i]++;
        if(attempt == "made")
        {
            md3s[i]++;
            points[i] += 3;
        }
    } else if(shot == " Free Throw."){
        attFTs[i]++;
        if(attempt == "made")
        {
            mdFTs[i]++;
            points[i] += 1;
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

// - getSum
int getSum(int list[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += list[i];
    return sum;
}

int main()
{
    // Variables
    const int MAX_ROSTER_SIZE = 20;

    // - Away Team
    std::string awayTeamFirstNames[MAX_ROSTER_SIZE];
    std::string awayTeamLastNames[MAX_ROSTER_SIZE];
    int awayTeamHeights[MAX_ROSTER_SIZE] = {0};
    int awayTeamAtt2s[MAX_ROSTER_SIZE] = {0};
    int awayTeamMd2s[MAX_ROSTER_SIZE] = {0};
    int awayTeamAtt3s[MAX_ROSTER_SIZE] = {0};
    int awayTeamMd3s[MAX_ROSTER_SIZE] = {0};
    int awayTeamAttFTs[MAX_ROSTER_SIZE] = {0};
    int awayTeamMdFTs[MAX_ROSTER_SIZE] = {0};
    int awayTeamPoints[MAX_ROSTER_SIZE] = {0};
    int awayTeamRosterSize = 0;
    int awayTeamScore = 0;
    std::string awayTeamName;

    // - Home Team
    std::string homeTeamFirstNames[MAX_ROSTER_SIZE];
    std::string homeTeamLastNames[MAX_ROSTER_SIZE];
    int homeTeamHeights[MAX_ROSTER_SIZE] = {0};
    int homeTeamAtt2s[MAX_ROSTER_SIZE] = {0};
    int homeTeamMd2s[MAX_ROSTER_SIZE] = {0};
    int homeTeamAtt3s[MAX_ROSTER_SIZE] = {0};
    int homeTeamMd3s[MAX_ROSTER_SIZE] = {0};
    int homeTeamAttFTs[MAX_ROSTER_SIZE] = {0};
    int homeTeamMdFTs[MAX_ROSTER_SIZE] = {0};
    int homeTeamPoints[MAX_ROSTER_SIZE] = {0};
    int homeTeamRosterSize = 0;
    int homeTeamScore = 0;
    std::string homeTeamName;

    readRoster(awayTeamFirstNames, awayTeamLastNames, awayTeamHeights, awayTeamRosterSize, awayTeamName);
    readRoster(homeTeamFirstNames, homeTeamLastNames, homeTeamHeights, homeTeamRosterSize, homeTeamName);

    // Read from file
    std::ifstream fin;
    openFin(fin, "Enter Play-by-Play File Name: ");
    std::string first, last, attempt, shot;
    while(fin >> first)
    {
        fin >> last >> attempt;
        getline(fin, shot);
        int i = getIndex(awayTeamFirstNames, awayTeamLastNames, awayTeamRosterSize, first, last);
        if(i >= 0)
        {
            recordPlay(awayTeamAtt2s, awayTeamMd2s, awayTeamAtt3s, awayTeamMd3s, awayTeamAttFTs, awayTeamMdFTs, awayTeamPoints, i, attempt, shot);
        } else {
            int j = getIndex(homeTeamFirstNames, homeTeamLastNames, homeTeamRosterSize, first, last);
            if(j >= 0){
                recordPlay(homeTeamAtt2s, homeTeamMd2s, homeTeamAtt3s, homeTeamMd3s, homeTeamAttFTs, homeTeamMdFTs, homeTeamPoints, j, attempt, shot);
            } else {
                std::cout << "Error: " << first << " " << last << " is not on any team\n";
            }
        }
    }
    // Close file
    fin.close();

    // Calculate sum of scores and bubble sort
    awayTeamScore = getSum(awayTeamPoints, awayTeamRosterSize);
    homeTeamScore = getSum(homeTeamPoints, homeTeamRosterSize);
    bubbleSort(awayTeamFirstNames, awayTeamLastNames, awayTeamHeights, awayTeamAtt2s, awayTeamMd2s, awayTeamAtt3s, awayTeamMd3s, awayTeamAttFTs, awayTeamMdFTs, awayTeamPoints, awayTeamRosterSize);
    bubbleSort(homeTeamFirstNames, homeTeamLastNames, homeTeamHeights, homeTeamAtt2s, homeTeamMd2s, homeTeamAtt3s, homeTeamMd3s, homeTeamAttFTs, homeTeamMdFTs, homeTeamPoints, homeTeamRosterSize);
    std::cout << std::endl;

    // Display roster
    printHeader(awayTeamName, awayTeamScore);
    for(int i = 0; i < awayTeamRosterSize; i++)
        outputOnePlayer(awayTeamFirstNames, awayTeamLastNames, awayTeamHeights, awayTeamAtt2s, awayTeamMd2s, awayTeamAtt3s, awayTeamMd3s, awayTeamAttFTs, awayTeamMdFTs, awayTeamPoints, i);
    std::cout << std::endl;

    printHeader(homeTeamName, homeTeamScore);
    for(int i = 0; i < homeTeamRosterSize; i++)
        outputOnePlayer(homeTeamFirstNames, homeTeamLastNames, homeTeamHeights, homeTeamAtt2s, homeTeamMd2s, homeTeamAtt3s, homeTeamMd3s, homeTeamAttFTs, homeTeamMdFTs, homeTeamPoints, i);
    std::cout << std::endl;

    return 0;
}