/*
 * Alec Him
 * CS 135 - Lab 5
 * Description: RPS Game with computer opponent
 * Input: R/P/S/E
 * Output: Computer R/P/S and Victor
 */
#include <iostream>     // For console input and output
#include <cstdlib>      // For rand(), srand()
#include <ctime>        // We will use the current time as a seed

int main()
{
    // Variables
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;
    char playerInput;
    std::string result = "";

    while(true)
    {
        srand(time(0));     // Initialize random seed
        int computerMove = rand() % 3; // 0, 1, 2
        int playerMove = 0;

        // Display and prompt user for input
        std::cout << "[R]ock\n";
        std::cout << "[P]aper\n";
        std::cout << "[S]cissors\n";
        std::cout << "[E]xit\n";
        std::cout << "Your Move: ";
        std::cin >> playerInput;

        // Player Variables
        switch(playerInput)
        {
            case 'R':
            case 'r':
                playerMove = ROCK;
                break;
            case 'P':
            case 'p':   
                playerMove = PAPER;
                break;
            case 'S':
            case 's':   
                playerMove = SCISSORS;
                break;
            case 'E':   
            case 'e':           
                std::cout << "Exiting Program\n";
                return 0;
            default:    
                break;
        }

        // Computer Variables
        std::string moveDisplay = "";
        switch(computerMove)
        {
            case ROCK:
                moveDisplay = "[R]ock";
                break;
            case PAPER:
                moveDisplay = "[P]aper";
                break;
            case SCISSORS:
                moveDisplay = "[S]cissors";
                break;
            default:
                break;
        }
        std::cout << "Computer Move: " << moveDisplay << std::endl;

        // Determine winner
        if((playerMove == SCISSORS && computerMove == PAPER) || (playerMove == PAPER && computerMove == ROCK) || (playerMove == ROCK && computerMove == SCISSORS))
        {
            result = "You win!";
        } else if((playerMove == PAPER && computerMove == SCISSORS) || (playerMove == SCISSORS && computerMove == ROCK) || (playerMove == ROCK && computerMove == PAPER)){
            result = "You lose!";
        } else {
            result = "Tie!";
        }
    
        std::cout << result << std::endl;

    }

    return 0;
}