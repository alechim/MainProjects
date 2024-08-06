/*
 * Alec Him
 * CS 135 - Assignment 5
 * Description: Create a game against a computer with simple input
 * Input: Enter Key
 * Output: Body, Head, Eye, Wing, Leg, Tail
 */
#include <iostream>    // For console input and output
#include <cstdlib>     // For rand(), srand()
#include <ctime>       // Used and Initializes srand()

int main(int argc, char *argv[])
{
    // Variables
    std::string answer, part, missing = "";
    int counter = 1;
    std::string option;
    bool debugMode = false;
    // - Player
    int body = 0, head = 0, wing = 0, leg = 0, eye = 0, tail = 0;
    // - Computer
    int bodyCom = 0, headCom = 0, wingCom = 0, legCom = 0, eyeCom = 0, tailCom = 0;

    std::cout << "***************************\n";
    std::cout << "    Welcome to Can-cell    \n";
    std::cout << "***************************\n";

    if(argc > 1)
    {
        option = argv[1];
        if(option == "debug")
        {
            debugMode = true;
            std::cout << "\n<<<<<<<<<<< Debug Mode Active >>>>>>>>>>>>>\n";
            
            while(true){
                std::cout << "################\n";
                std::cout << "Round #" << counter << std::endl << std::endl;

                counter++;

                // Number Generator
                srand(time(0));
                int rand(void);
                int playerMove = rand() % 6+1;
                int computerMove = rand() % 6+1;

                std::cout << "Hit enter to roll die: ";
                getline(std::cin, answer);
                
                // Player Variables
                switch(playerMove)
                {
                    case 1:
                        part = "1 BODY";
                        if(body < 1)
                        {
                            body++;
                        } else {
                            part = "1 duplicate BODY";
                        }
                        break;
                    case 2:
                        part = "2 HEAD";
                        if(body != 0 && head < 1){
                            head++;
                        } else {
                            part = "2 duplicate HEAD";
                        }
                        break;
                    case 3:
                        part = "3 WING";
                        if(body != 0 && wing < 4)
                        {
                            wing++;
                        } else {
                            part = "3 duplicate WING";
                        }
                        break;
                    case 4:
                        part = "4 LEG";
                        if(body != 0 && leg < 6)
                        {
                            leg++;
                        } else {
                            part = "4 duplicate LEG";
                        }
                        break;
                    case 5:
                        part = "5 EYE";
                        if(body != 0 && head != 0 && eye < 2){
                            eye++;
                        } else if (body != 0 && head == 0){
                            missing = "HEAD";
                        } else {
                            part = "5 duplicate EYE";
                        }
                        break;
                    case 6:
                        part = "6 TAIL";
                        if(body != 0 && tail < 1){
                            tail++;
                        } else {
                            part = "6 duplicate TAIL";
                        }
                        break;
                }
                if(body == 0){
                    missing = "BODY";
                }
                if(body == 0 || playerMove == 5 && head == 0){
                    std::cout << "Player one roll is " << part << ", must have " << missing << " first\n";
                } else {
                    std::cout << "Player one roll is " << part << std::endl;
                }

                // Display Player Inventory
                std::cout << "---------------------\n";
                std::cout << "Player 1 Inventory\n";
                std::cout << "Body:       " << body << std::endl;
                std::cout << "Head:       " << head << std::endl;
                std::cout << "Eye:        " << eye << std::endl;
                std::cout << "Wing:       " << wing << std::endl;
                std::cout << "Leg:        " << leg << std::endl;
                std::cout << "Tail:       " << tail << std::endl << std::endl;

                // Computer Variables
                switch(computerMove)
                {
                    case 1:
                        part = "1 BODY";
                        if(bodyCom < 1)
                        {
                            bodyCom++;
                        } else {
                            part = "1 duplicate BODY";
                        }
                        break;
                    case 2:
                        part = "2 HEAD";
                        if(bodyCom != 0 && headCom < 1){
                            headCom++;
                        } else {
                            part = "2 duplicate HEAD";
                        }
                        break;
                    case 3:
                        part = "3 WING";
                        if(bodyCom != 0 && wingCom < 4)
                        {
                            wingCom++;
                        } else {
                            part = "3 duplicate WING";
                        }
                        break;
                    case 4:
                        part = "4 LEG";
                        if(bodyCom != 0 && legCom < 6)
                        {
                            legCom++;
                        } else {
                            part = "4 duplicate LEG";
                        }
                        break;
                    case 5:
                        part = "5 EYE";
                        if(bodyCom != 0 && headCom != 0 && eyeCom < 2){
                            eyeCom++;
                        } else if (bodyCom != 0 && headCom == 0){
                            missing = "HEAD";
                        } else {
                            part = "5 duplicate EYE";
                        }
                        break;
                    case 6:
                        part = "6 TAIL";
                        if(bodyCom != 0 && tailCom < 1){
                            tailCom++;
                        } else {
                            part = "6 duplicate TAIL";
                        }
                        break;
                }
                if(bodyCom == 0){
                    missing = "BODY";
                }
                if(bodyCom == 0 || computerMove == 5 && headCom == 0){
                    std::cout << "Player two roll is " << part << ", must have " << missing << " first\n";
                } else {
                    std::cout << "Player two roll is " << part << std::endl;
                }

                // Display Computer Inventory
                std::cout << "---------------------\n";
                std::cout << "Player 2 Inventory\n";
                std::cout << "Body:       " << bodyCom << std::endl;
                std::cout << "Head:       " << headCom << std::endl;
                std::cout << "Eye:        " << eyeCom << std::endl;
                std::cout << "Wing:       " << wingCom << std::endl;
                std::cout << "Leg:        " << legCom << std::endl;
                std::cout << "Tail:       " << tailCom << std::endl << std::endl;

                // Victory Display
                if(body == 1 && head == 1 && wing == 4 && leg == 6 && eye == 2 && tail == 1)
                {
                    std::cout << "*******************\n";
                    std::cout << "Player one has won\n";
                    std::cout << "               Game Results\n";
                    std::cout << "------------------------------------------\n";
                    std::cout << "Player 1 Inventory     Player 2 Inventory\n";
                    std::cout << "Body:       " << body << "          Body:       " << bodyCom << std::endl;
                    std::cout << "Head:       " << head << "          Head:       " << headCom << std::endl;
                    std::cout << "Eye:        " << eye << "           Eye:       " << eyeCom << std::endl;
                    std::cout << "Wing:       " << wing << "          Wing:       " << wingCom << std::endl;
                    std::cout << "Leg:        " << leg << "           Leg:       " << legCom << std::endl;
                    std::cout << "Tail:       " << tail << "          Tail:       " << tailCom << std::endl;

                    return 0;
                } else if(bodyCom == 1 && headCom == 1 && wingCom == 4 && legCom == 6 && eyeCom == 2 && tailCom == 1)
                {
                    std::cout << "*******************\n";
                    std::cout << "Player two has won\n";
                    std::cout << "               Game Results\n";
                    std::cout << "------------------------------------------\n";
                    std::cout << "Player 1 Inventory     Player 2 Inventory\n";
                    std::cout << "Body:       " << body << "          Body:       " << bodyCom << std::endl;
                    std::cout << "Head:       " << head << "          Head:       " << headCom << std::endl;
                    std::cout << "Eye:        " << eye << "           Eye:       " << eyeCom << std::endl;
                    std::cout << "Wing:       " << wing << "          Wing:       " << wingCom << std::endl;
                    std::cout << "Leg:        " << leg << "           Leg:       " << legCom << std::endl;
                    std::cout << "Tail:       " << tail << "          Tail:       " << tailCom << std::endl;
                    
                    return 0;
                }

            }
        } else {
            std::cout << "\n<<<<<<<<<<<  Silent Mode Active >>>>>>>>>>>>>\n";
            while(true)
            {
                std::cout << "################\n";
                std::cout << "Round #" << counter << std::endl << std::endl;
                counter++;

                // Number Generator
                srand(time(NULL));
                int rand(void);
                int playerMove = rand() % 6+1;
                int computerMove = rand() % 6+1;

                std::cout << "Hit enter to roll die: ";
                getline(std::cin, answer);
                
                // Player Variables
                switch(playerMove)
                {
                    case 1:
                        part = "1 BODY";
                        if(body < 1)
                        {
                            body++;
                        } else {
                            part = "1 duplicate BODY";
                        }
                        break;
                    case 2:
                        part = "2 HEAD";
                        if(body != 0 && head < 1){
                            head++;
                        } else {
                            part = "2 duplicate HEAD";
                        }
                        break;
                    case 3:
                        part = "3 WING";
                        if(body != 0 && wing < 4)
                        {
                            wing++;
                        } else {
                            part = "3 duplicate WING";
                        }
                        break;
                    case 4:
                        part = "4 LEG";
                        if(body != 0 && leg < 6)
                        {
                            leg++;
                        } else {
                            part = "4 duplicate LEG";
                        }
                        break;
                    case 5:
                        part = "5 EYE";
                        if(body != 0 && head != 0 && eye < 2){
                            eye++;
                        } else if (body != 0 && head == 0){
                            missing = "HEAD";
                        } else {
                            part = "5 duplicate EYE";
                        }
                        break;
                    case 6:
                        part = "6 TAIL";
                        if(body != 0 && tail < 1){
                            tail++;
                        } else {
                            part = "6 duplicate TAIL";
                        }
                        break;
                }
                if(body == 0){
                    missing = "BODY";
                }
                if(body == 0 || playerMove == 5 && head == 0){
                    std::cout << "Player one roll is " << part << ", must have " << missing << " first\n";
                } else {
                    std::cout << "Player one roll is " << part << std::endl;
                }

                // Display Player Inventory
                std::cout << "---------------------\n";
                std::cout << "Player 1 Inventory\n";
                std::cout << "Body:       " << body << std::endl;
                std::cout << "Head:       " << head << std::endl;
                std::cout << "Eye:        " << eye << std::endl;
                std::cout << "Wing:       " << wing << std::endl;
                std::cout << "Leg:        " << leg << std::endl;
                std::cout << "Tail:       " << tail << std::endl << std::endl;

                // Computer Variables
                switch(computerMove)
                {
                    case 1:
                        part = "1 BODY";
                        if(bodyCom < 1)
                        {
                            bodyCom++;
                        } else {
                            part = "1 duplicate BODY";
                        }
                        break;
                    case 2:
                        part = "2 HEAD";
                        if(bodyCom != 0 && headCom < 1){
                            headCom++;
                        } else {
                            part = "2 duplicate HEAD";
                        }
                        break;
                    case 3:
                        part = "3 WING";
                        if(bodyCom != 0 && wingCom < 4)
                        {
                            wingCom++;
                        } else {
                            part = "3 duplicate WING";
                        }
                        break;
                    case 4:
                        part = "4 LEG";
                        if(bodyCom != 0 && legCom < 6)
                        {
                            legCom++;
                        } else {
                            part = "4 duplicate LEG";
                        }
                        break;
                    case 5:
                        part = "5 EYE";
                        if(bodyCom != 0 && headCom != 0 && eyeCom < 2){
                            eyeCom++;
                        } else if (bodyCom != 0 && headCom == 0){
                            missing = "HEAD";
                        } else {
                            part = "5 duplicate EYE";
                        }
                        break;
                    case 6:
                        part = "6 TAIL";
                        if(bodyCom != 0 && tailCom < 1){
                            tailCom++;
                        } else {
                            part = "6 duplicate TAIL";
                        }
                        break;
                }
                if(bodyCom == 0){
                    missing = "BODY";
                }
                if(bodyCom == 0 || computerMove == 5 && headCom == 0){
                    std::cout << "Player two roll is " << part << ", must have " << missing << " first\n";
                } else {
                    std::cout << "Player two roll is " << part << std::endl;
                }

                // Display Computer Inventory
                std::cout << "---------------------\n";
                std::cout << "Player 2 Inventory\n";
                std::cout << "Body:       " << bodyCom << std::endl;
                std::cout << "Head:       " << headCom << std::endl;
                std::cout << "Eye:        " << eyeCom << std::endl;
                std::cout << "Wing:       " << wingCom << std::endl;
                std::cout << "Leg:        " << legCom << std::endl;
                std::cout << "Tail:       " << tailCom << std::endl << std::endl;

                // Victory Display
                if(body == 1 && head == 1 && wing == 4 && leg == 6 && eye == 2 && tail == 1)
                {
                    std::cout << "*******************\n";
                    std::cout << "Player one has won\n";
                    std::cout << "               Game Results\n";
                    std::cout << "------------------------------------------\n";
                    std::cout << "Player 1 Inventory     Player 2 Inventory\n";
                    std::cout << "Body:       " << body << "          Body:       " << bodyCom << std::endl;
                    std::cout << "Head:       " << head << "          Head:       " << headCom << std::endl;
                    std::cout << "Eye:        " << eye << "           Eye:       " << eyeCom << std::endl;
                    std::cout << "Wing:       " << wing << "          Wing:       " << wingCom << std::endl;
                    std::cout << "Leg:        " << leg << "           Leg:       " << legCom << std::endl;
                    std::cout << "Tail:       " << tail << "          Tail:       " << tailCom << std::endl;

                    return 0;
                } else if(bodyCom == 1 && headCom == 1 && wingCom == 4 && legCom == 6 && eyeCom == 2 && tailCom == 1)
                {
                    std::cout << "*******************\n";
                    std::cout << "Player two has won\n";
                    std::cout << "               Game Results\n";
                    std::cout << "------------------------------------------\n";
                    std::cout << "Player 1 Inventory     Player 2 Inventory\n";
                    std::cout << "Body:       " << body << "          Body:       " << bodyCom << std::endl;
                    std::cout << "Head:       " << head << "          Head:       " << headCom << std::endl;
                    std::cout << "Eye:        " << eye << "           Eye:       " << eyeCom << std::endl;
                    std::cout << "Wing:       " << wing << "          Wing:       " << wingCom << std::endl;
                    std::cout << "Leg:        " << leg << "           Leg:       " << legCom << std::endl;
                    std::cout << "Tail:       " << tail << "          Tail:       " << tailCom << std::endl;
                    
                    return 0;
                }
            }
        }
    }
    return 0;
}