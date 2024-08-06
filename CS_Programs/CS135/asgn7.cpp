/*
 * Alec Him
 * CS 135 - Assignment 7
 * Description: Program that plays a game of codewords
 * Input: Strings
 * Output: Code and Win/Loss
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Function Prototypes
void setupGame();
void foldCase(std::string&);
void startGame(std::string);
void displayHelp();

// Function Definitions
// - foldCase
void foldCase(std::string& lower)
{
    for(unsigned int i = 0; i < lower.length(); i++)
        lower[i] = tolower(lower[i]);
}

// - displayHelp
void displayHelp()
{
    std::cout << "\nType in Easy, Medium, or Hard after selecting Start in the Main Menu.\nEach Number entered will require a space between each other in order to work.\nThe End of each coding will require Main to be entered to return to Menu.\n" << std::endl;
}

// - setupGame
void setupGame()
{
    std::string difficulty = "";
    do{
        std::cout << "+--------------------+\n";
        std::cout << "| Select Difficulty  |\n";
        std::cout << "+--------------------+\n";
        std::cout << "| [Easy]             |\n";
        std::cout << "| [Medium]           |\n";
        std::cout << "| [Hard]             |\n";
        std::cout << "+--------------------+\n";
        std::cout << "| [Help]             |\n";
        std::cout << "| [Main] Menu        |\n";
        std::cout << "+--------------------+\n\n";

        do{
            std::cout << "Select a menu option: ";
            std::cin >> difficulty;
            foldCase(difficulty);
            if(difficulty == "easy" || difficulty == "medium" || difficulty == "hard")
            {
                startGame(difficulty);
                break;
            } else if(difficulty == "help"){
                displayHelp();
                break;
            } else if(difficulty == "main")
                break;
            else 
                std::cout << "Invalid Difficulty Selection.\n";
        } while(true);
    } while(difficulty != "main");
}

// - startGame
void startGame(std::string level)
{
    // Variables
    int attempt = 0, high = 0, low = 0, correct = 0, passcode1 = 0, passcode2 = 0, passcode3 = 0, passcode4 = 0, passcode5 = 0;
    int totalDig[5] = {0};
    int passcode[5] = {0};

    // Message Prompt
    std::cout << "+--------------------+\n";
    std::cout << "| Additional Options |\n";
    std::cout << "+--------------------+\n";
    std::cout << "| [Help]             |\n";
    std::cout << "| [Main] Menu        |\n";
    std::cout << "+--------------------+\n\n";

    // Game Logic
    if(level == "easy")
    {
        for(int i = 0; i < 3; i++)
            totalDig[i] = rand() % 3 + 1;
        attempt = 10;
        do{
            std::cout << "Guess Code (3 Digits, 1-3) {Attempts: [" << attempt << "/10]}: ";
            std::cin >> passcode[0] >> passcode[1] >> passcode[2]; 

            if(std::cin.fail() == true || passcode[0] < 1 || passcode[0] > 3 || passcode[1] < 1 || passcode[1] > 3 || passcode[2] < 1 || passcode[2] > 3)
            {
                std::cin.clear();
                std::cin.ignore(3, '\n');
                std::cout << "Error: Invalid Code Format" << std::endl;
            } else {
                for(int i = 0; i < 3; i++)
                {
                    if(totalDig[i] != passcode[i])
                    {
                        if(totalDig[i] < passcode[i])
                            high++;
                        else if(totalDig[i] > passcode[i])
                            low++;
                    } else
                        correct++;
                }
                std::cout << "+--------------------+\n";
                std::cout << "|      Correct |    " << correct << " |\n";
                std::cout << "|     Too High |    " << high << " |\n";
                std::cout << "|      Too Low |    " << low << " |\n";
                std::cout << "+--------------------+\n";

                correct = high = low = 0;
                attempt--;

                if(passcode[0] == totalDig[0] && passcode[1] == totalDig[1] && passcode[2] == totalDig[2])
                {
                    std::cout << "\nCode Found Successfully: " << totalDig[0] << totalDig[1] << totalDig[2] << std::endl;
                    break;
                } else if (attempt == 0){
                    std::cout << "Abort Mission: Imperial security alerted to intrusion." << std::endl;
                    std::cout << "Code was " << totalDig[0] << totalDig[1] << totalDig[2] << std::endl;
                    break;
                }
            }
        } while(attempt != 0);
    } else if(level == "medium"){
        for(int i = 0; i < 4; i++)
            totalDig[i] = rand() % 5 + 1;
        attempt = 15;
        do{
            std::cout << "Guess Code (4 Digits, 1-5) {Attempts: [" << attempt << "/15]}: ";
            std::cin >> passcode[0] >> passcode[1] >> passcode[2] >> passcode[3]; 

            if(std::cin.fail() == true || passcode[0] < 1 || passcode[0] > 5 || passcode[1] < 1 || passcode[1] > 5 || passcode[2] < 1 || passcode[2] > 5 || passcode[3] < 1 || passcode[3] > 5)
            {
                std::cin.clear();
                std::cin.ignore(4, '\n');
                std::cout << "Error: Invalid Code Format" << std::endl;
            } else {
                for(int i = 0; i < 4; i++)
                {
                    if(totalDig[i] != passcode[i])
                    {
                        if(totalDig[i] < passcode[i])
                            high++;
                        else if(totalDig[i] > passcode[i])
                            low++;
                    } else
                        correct++;
                }
                std::cout << "+--------------------+\n";
                std::cout << "|      Correct |    " << correct << " |\n";
                std::cout << "|     Too High |    " << high << " |\n";
                std::cout << "|      Too Low |    " << low << " |\n";
                std::cout << "+--------------------+\n";

                correct = high = low = 0;
                attempt--;

                if(passcode[0] == totalDig[0] && passcode[1] == totalDig[1] && passcode[2] == totalDig[2] && passcode[3] == totalDig[3])
                {
                    std::cout << "\nCode Found Successfully: " << totalDig[0] << totalDig[1] << totalDig[2] << totalDig[3] << std::endl;
                    break;
                } else if (attempt == 0){
                    std::cout << "Abort Mission: Imperial security alerted to intrusion." << std::endl;
                    std::cout << "Code was " << totalDig[0] << totalDig[1] << totalDig[2] << totalDig[3] << std::endl;
                    break;
                }
            }
        } while(attempt != 0);
    } else if(level == "hard"){
        for(int i = 0; i < 5; i++)
            totalDig[i] = rand() % 9 + 1;
        attempt = 20;
        do{
            std::cout << "Guess Code (5 Digits, 1-9) {Attempts: [" << attempt << "/20]}: ";
            std::cin >> passcode[0] >> passcode[1] >> passcode[2] >> passcode[3] >> passcode[4]; 

            if(std::cin.fail() == true || passcode[0] < 1 || passcode[0] > 9 || passcode[1] < 1 || passcode[1] > 9 || passcode[2] < 1 || passcode[2] > 9 || passcode[3] < 1 || passcode[3] > 9 || passcode[4] < 1 || passcode[4] > 9)
            {
                std::cin.clear();
                std::cin.ignore(5, '\n');
                std::cout << "Error: Invalid Code Format" << std::endl;
            } else {
                for(int i = 0; i < 5; i++)
                {
                    if(totalDig[i] != passcode[i])
                    {
                        if(totalDig[i] < passcode[i])
                            high++;
                        else if(totalDig[i] > passcode[i])
                            low++;
                    } else
                        correct++;
                }
                std::cout << "+--------------------+\n";
                std::cout << "|      Correct |    " << correct << " |\n";
                std::cout << "|     Too High |    " << high << " |\n";
                std::cout << "|      Too Low |    " << low << " |\n";
                std::cout << "+--------------------+\n";

                correct = high = low = 0;
                attempt--;

                if(passcode[0] == totalDig[0] && passcode[1] == totalDig[1] && passcode[2] == totalDig[2] && passcode[3] == totalDig[3] && passcode[4] == totalDig[4])
                {
                    std::cout << "\nCode Found Successfully: " << totalDig[0] << totalDig[1] << totalDig[2] << totalDig[3] << totalDig[4] << std::endl;
                    break;
                } else if (attempt == 0){
                    std::cout << "Abort Mission: Imperial security alerted to intrusion." << std::endl;
                    std::cout << "Code was " << totalDig[0] << totalDig[1] << totalDig[2] << totalDig[3] << totalDig[4] << std::endl;
                    break;
                }
            }
        } while(attempt != 0);
    }
}

int main(int argc, char *argv[])
{
    // Variables
    std::string choice = "";

    // Check cli commands for debug mode
    // - Normal
    switch(argc)
    {
        case 1:
            srand(time(NULL));
            break;
        case 2:
            if(argv[1] == "debug")
                srand(0);
            break;
        default:
            std::cout << "To start program in debug mode: \n";
            std::cout << argv[0] << " debug" << std::endl;
            return -1;
    }

    // Main Menu
    do{
        std::cout << "+--------------------+\n";
        std::cout << "| Main Menu          |\n";
        std::cout << "+--------------------+\n";
        std::cout << "| [Start] Simulation |\n";
        std::cout << "| [Help] Guide       |\n";
        std::cout << "| [Quit]             |\n";
        std::cout << "+--------------------+\n";
        std::cout << std::endl;

        do{
            std::cout << "Select a menu option: ";
            std::cin >> choice;
            foldCase(choice);
            if(choice == "start")
            {
                setupGame();
                break;
            } else if(choice == "help") {
                displayHelp();
                break;
            } else if(choice == "quit")
                break;
            else
                std::cout << "Invalid Menu Selection.\n";
        } while(true);

    } while(choice != "quit");

    return 0;
}