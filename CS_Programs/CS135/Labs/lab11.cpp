/*
 * Alec Him
 * CS 135 - Lab 11
 * Description:
 * Input:
 * Output:
 */
#include <iostream>
#include <fstream>
#include <string>

struct station
{
    std::string callsign;
    double frequency;
    std::string genre;
    std::string nowPlaying;
};

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: ./lab11.exe [RADIO_FILENAME]\n";
        return 0;
    }

    // Variables
    station currentStation[15];
    std::string filename = argv[1];
    std::ifstream infile;
    infile.open(filename.c_str());
    std::string junk;
    double freq;

    // Error checking
    if(!infile)
    {
        std::cout << "No reception. Hope you have an aux cable!\n";
        return 0;
    }

    // Read from inputs
    for(int i = 0; i < 15; i++)
    {
        getline(infile, currentStation[i].callsign);
        infile >> currentStation[i].frequency;
        getline(infile, junk);
        getline(infile, currentStation[i].genre);
        getline(infile, currentStation[i].nowPlaying);
        getline(infile, junk);
    }

    infile.close();

    // Prompt user for input
    std::cout << "Enter a frequency: \n";
    std::cin >> freq;

    // Find station
    for(int i = 0; i < 15; i++)
    {
        if(freq == currentStation[i].frequency)
        {
            std::cout << "Now Playing: " << currentStation[i].nowPlaying << std::endl;
            std::cout << "Station Type: " << currentStation[i].genre << std::endl;
            std::cout << "Callsign: " << currentStation[i].callsign << std::endl;
            break;
        } else if(i == 15){
            std::cout << "Nothing but static\n";
            std::cout << "Try Again\n";
            std::cin >> freq;
            i = 0;
        }
    }

    return 0;
}