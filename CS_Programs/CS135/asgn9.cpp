/*
 * Alec Him
 * CS 135 - Assignment 9
 * Description: Read in Files and Display Targets Hit and Missed
 * Input: StormTrooperData.txt & TargetWeights.txt
 * Output: Graph of Targets, Names, Targets Hit, Score, Top 3 Names
 */
#include <iostream>
#include <iomanip>
#include <fstream>

// Global Variables
const int SIZE = 20;
const int TRGTS = 10;

// Function Prototypes
int readData(std::string[], bool[][TRGTS], double[]);
double computeScore(bool[][TRGTS], double[], int);
void outputStormTroopers(std::string[], bool[][TRGTS], double[], int);
void outputOneStormTrooper(std::string, bool[], double);
void lowerCase(std::string&);

// Function Definitions
// - readData
int readData(std::string name[], bool hit[][TRGTS], double weights[])
{
    // Variables
    std::ifstream iFile, iFile2;
    std::string file1 = "StormTrooperData.txt", file2 = "TargetWeights.txt", hit_miss = "";
    int numTroop = 0;

    do {
        std::cout << "\nPlease enter storm trooper results file: ";
        std::cin >> file1;
        iFile.open(file1);
        if(!iFile.is_open())
            std::cout << "Invalid file!\n";
        else 
            std::cout << "Stormtrooper data read successfully.\n";
    } while(!iFile.is_open());
    
    do {
        std::cout << "\nEnter target weights: ";
        std::cin >> file2;
        iFile2.open(file2);
        if(!iFile2.is_open())
            std::cout << "Invalid file!\n";
        else
            std::cout << "Target weights updated!\n";
    } while(!iFile2.is_open());

    for(int i = 0; !iFile2.eof(); i++)
        iFile2 >> weights[i];

    while(!iFile.eof())
    {
        for(int r = 0; r < SIZE; r++)
        {
            iFile >> name[r];
            for(int c = 0; c < TRGTS; c++)
            {
                iFile >> hit_miss;
                lowerCase(hit_miss);
                if(hit_miss == "hit")
                    hit[r][c] = true;
                else
                    hit[r][c] = false;
            }
            if(!iFile.eof())
                numTroop++;
        }
    }

    iFile.close();
    iFile2.close();

    return numTroop;
}

// - lowerCase
void lowerCase(std::string& lower)
{
    for(int i = 0; (unsigned)i < lower.length(); i++)
        lower[i] = std::tolower(lower[i]);
}

// - computeScore
double computeScore(bool hit[][TRGTS], double weights[], int numTroop)
{
    double score = 0.0;
    for(int c = 0; c < TRGTS; c++)
        score += weights[c] * hit[numTroop][c];
    return score;
}

// - outputStormTroopers
void outputStormTroopers(std::string name[], bool hit[][TRGTS], double scores[], int numTroop)
{
    bool confirm[TRGTS];
    std::string oneName = "";
    double score = 0.0;

    std::cout << "NAME";
    std::cout << std::setw(14) << "T1";
    std::cout << std::setw(4) << "T2";
    std::cout << std::setw(4) << "T3";
    std::cout << std::setw(4) << "T4";
    std::cout << std::setw(4) << "T5";
    std::cout << std::setw(4) << "T6";
    std::cout << std::setw(4) << "T7";
    std::cout << std::setw(4) << "T8";
    std::cout << std::setw(4) << "T9";
    std::cout << std::setw(5) << "T10";
    std::cout << std::setw(8) << "TOTAL";
    std::cout << std::setw(10) << "SCORE\n";
    std::cout << "------------------------------------------------------------------------\n";

    for(int r = 0; r <= numTroop; r++)
    {
        oneName = name[r];
        score = scores[r];

        for(int c = 0; c < TRGTS; c++)
            confirm[c] = hit[r][c];

        outputOneStormTrooper(oneName, confirm, score);
    }
}

// - outputOneStormTrooper
void outputOneStormTrooper(std::string name, bool confirm[], double score)
{
    int count = 0;
    std::cout << name;
    for(int i = 0; i < TRGTS; i++)
    {
        if(confirm[i])
        {
            std::cout << std::setw(4) << "X";
            count++;
        } else 
            std::cout << std::setw(4) << " ";
    }

    std::cout << std::setw(8) << score;
    std::cout << std::setw(10) << std::setprecision(4) << score << std::endl;
}

int main()
{
    // Variables
    std::string names[SIZE];
    bool targets[SIZE][TRGTS];
    double targetWeights[TRGTS];
    double scores[SIZE];
    int amtStormTroopers = 0;

    amtStormTroopers = readData(names, targets, targetWeights);

    for(int i = 0; i <= amtStormTroopers; i++)
        scores[i] = computeScore(targets, targetWeights, i);
    
    outputStormTroopers(names, targets, scores, amtStormTroopers);
}