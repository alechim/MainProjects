/*
 * Alec Him
 * CS 202 - Assignment 2
 * Description:
 * Input:
 * Output:
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// Classes
// - passenger
class passenger
{
    private:
        std::string Name, passengerType;
    public:
        void setName(std::string name, std::string last);
        std::string getName() const;
        void getPassengerType(std::string);
};
// - rocket
class rocket 
{
    private:
        int ticketPrice, seats, bookedSeat;
        double timeReq;
        std::string rocketType;
        // Rocket Specs
        std::string propellant;
        double acceleration, velocity, fuelCapacity, thrust;
    public:
        rocket();       // Constructor
        void setSeats(int);
        int getSeats() const;
        void setTicketPrice(int);
        int getTicketPrice() const;
        int checkRocketAvailability();
        void setRocketType(std::string);
        void purchaseTicket();
        int getBookedSeats() const;
        void setVelocity(double);
        double getVelocity() const;
        void setFuelCapacity(int);
        void setRocketSpecs(std::string, double, double);
        void getRocketSpecs() const;
        void setTimeReq(double);
        double getTimeReq() const;
};

// - Menu
class Menu
{
    private:
        int choice;
    public:
        Menu(std::string);    // Constructor
        int showRocketMenu();
};

// Function Definitions
/*
 * - Rocket(): Constructor for the rocket class
 */
rocket::rocket()
{
    bookedSeat = 0;
}

/*
 * - getRocketSpecs(): Displays the specifications of the rocket
 */
void rocket::getRocketSpecs() const
{
    std::cout << "Your Rocket Specs" << std::endl;
    std::cout << "Propellant Type: " << propellant << std::endl;
    std::cout << "Acceleration: " << acceleration << std::endl;
    std::cout << "Thrust: " << thrust << std::endl;
    std::cout << "Fuel Capacity: " << fuelCapacity << std::endl;
    std::cout << "Velocity: " << velocity << std::endl;
}

/*
 * - Menu(): Constructor for the Menu class
 * @param std::string msg
 */
Menu::Menu(std::string msg)
{
    std::cout << "\n\n********************************\n";
    std::cout << msg << std::endl;
    std::cout << "********************************\n\n";
}

// - showRocketMenu(): Displays the rocket menu
int showRocketMenu()
{
    int select = 0;
    
    // Rocket Menu Prompt
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "   | Please select a rocket                        |  " << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "1. | Cold Gas and the ticket price is $10000       |  " << std::endl;
    std::cout << "2. | Chemical and the ticket price is $12000       |  " << std::endl;
    std::cout << "3. | Thermoelectric and the ticket price is $15000 |  " << std::endl;
    std::cout << "4. | Hybrid and the ticket price is $16000         |  " << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Test User Input
    while(std::cin.fail() || select < 1 || select > 4)
    {
        std::cout << "Please make a selection: ";
        std::cin >> select;

        switch(select)
        {
            case 1:
                std::cout << "<===============================>" << std::endl;
                std::cout << "You have chosen - Cold Gas Rocket" << std::endl;
                std::cout << "The price is: $10000" << std::endl;
                std::cout << "<===============================>" << std::endl;
                break;
            case 2:
                std::cout << "<===============================>" << std::endl;
                std::cout << "You have chosen - Chemical Rocket" << std::endl;
                std::cout << "The price is: $12000" << std::endl;
                std::cout << "<===============================>" << std::endl;
                break;
            case 3:
                std::cout << "<===============================>" << std::endl;
                std::cout << "You have chosen - Thermoelectric Rocket" << std::endl;
                std::cout << "The price is: $15000" << std::endl;
                std::cout << "<===============================>" << std::endl;
                break;
            case 4:
                std::cout << "<===============================>" << std::endl;
                std::cout << "You have chosen - Hybrid Rocket" << std::endl;
                std::cout << "The price is: $16000" << std::endl;
                std::cout << "<===============================>" << std::endl;
                break;
            default:
                std::cout << "Error - Choice is not within parameter." << std::endl;
                break;
        }
    }
    
    return select;
}

int main()
{
    // Variables
    int pSize = 0, choice = 0, seat = 0, pType = 0;
    double travelDistance = 238855, totalPrice = 0.0, discount = 0.0, toPay = 0.0;
    char ch;
    double remainingDistance = 0.0, time = 0.0;
    rocket Obj1, Obj2, Obj3, Obj4;
    passenger psg[pSize];
    std::string fName, lName;

    Menu menu("Welcome Admin- Set seats to \n YOU CAN FLY TO SPACE");

    // - Passenger Variables
    int cgSeats = 0, cSeats = 0, tSeats = 0, hSeats = 0;
    int cgCount = 0, cCount = 0, tCount = 0, hCount = 0;
    std::string first[500], last[500];
    int miles = 0, price = 0;

    // - Rocket Variables
    std::string propellant = "";
    double acceleration = 0.0, velocity = 0.0, fuelCapacity = 0.0, thrust = 0.0;

    // Prompt User to set the amount of seats available in each rocket
    std::cout << "Enter the number of seats in Cold-Gas Rocket: ";
    std::cin >> cgSeats;
    std::cout << "Enter the number of seats in Chemical Rocket: ";
    std::cin >> cSeats;
    std::cout << "Enter the number of seats in Thermoelectric Rocket: ";
    std::cin >> tSeats;
    std::cout << "Enter the number of seats in Hybrid Rocket: ";
    std::cin >> hSeats;

    do{
        Menu("Welcome to YOU CAN FLY TO SPACE");

        // Display Availability of the Seats
        std::cout << "Status of seats availability: " << std::endl;
        std::cout << "Cold-Gas Rocket is available with: " << cgSeats << "Passengers" << std::endl;
        std::cout << "Chemical Rocket is available with: " << cSeats << "Passengers" << std::endl;
        std::cout << "Thermoelectric Rocket is available with: " << tSeats << "Passengers" << std::endl;
        std::cout << "Hybrid Rocket is available with: " << hSeats << "Passengers" << std::endl;

        choice = showRocketMenu();

        std::cout << "Checking seat availability..." << std::endl;
        if(cgSeats <= 0 && choice == 1)
        {
            std::cout << "The Cold-Gas Rocket is unavailable" << std::endl;
            choice = showRocketMenu();
        }
        if(cSeats <= 0 && choice == 2)
        {
            std::cout << "The Chemical Rocket is unavailable" << std::endl;
            choice = showRocketMenu();
        }
        if(tSeats <= 0 && choice == 3)
        {
            std::cout << "The Thermoelectric Rocket is unavailable" << std::endl;
            choice = showRocketMenu();
        }
        if(hSeats <= 0 && choice == 4)
        {
            std::cout << "The Hybrid Rocket is unavailable" << std::endl;
            choice = showRocketMenu();
        }

        // Based on choice, sets the seat availability to the selected seat availability
        switch(choice)
        {
            case 1:
                seat = cgSeats;
                price = 10000;
                propellant = "Hydrogen";
                acceleration = 12.9;
                velocity = 25000;
                fuelCapacity = 773000;
                thrust = 12.1;
                break;
            case 2:
                seat = cSeats;
                price = 12000;
                propellant = "Hypergolic";
                acceleration = 12.1;
                velocity = 21000;
                fuelCapacity = 759320;
                thrust = 12.2;
                break;
            case 3:
                seat = tSeats;
                price = 15000;
                propellant = "Hydrazine";
                acceleration = 38.1;
                velocity = 21000;
                fuelCapacity = 657200;
                thrust = 15.1;
                break;
            case 4:
                seat = hSeats;
                price = 16000;
                propellant = "Oxidizers";
                acceleration = 90.2;
                velocity = 28000;
                fuelCapacity = 521400;
                thrust = 35.1;
                break;
            default:
                break;
        }

        // Displays how many seats are available to book and loops until input is correct
        do{
            // Displays max amount of seats that can be reserved
            std::cout << "Available seats are : " << seat << std::endl;
            std::cout << "Enter number of tickets [Between the range of 1 - " << seat << "] : ";
            std::cin >> pSize;

            // Displays error message if input is not within range
            if(pSize < 1 || pSize > seat)
                std::cout << "Error - Input is not within the parameters." << std::endl;
        } while(pSize < 1 || pSize > seat);
        
        // Subtracts the seat selection from tickets to "reserve" the seats
        switch(choice)
        {
            case 1:
                cgCount = pSize;
                seat = cgSeats - pSize;
                break;
            case 2:
                cCount = pSize;
                seat = cSeats - pSize;
                break;
            case 3:
                tCount = pSize;
                seat = tSeats - pSize;
                break;
            case 4:
                hCount = pSize;
                seat = hSeats - pSize;
                break;
            default:
                break;
        }

        // Loops until all passengers previously inputted have been reserved
        for(int i = 0; i < pSize; i++)
        {
            std::cout << "Enter details of Passenger " << i + 1 << std::endl << std::endl;
            std::cout << "----------------------------" << std::endl;
            std::cout << "Enter your First Name: ";
            std::cin >> first[i];

            std::cout << "Enter your Last Name: ";
            std::cin >> last[i];

            std::cout << "----------------------------\n";
            std::cout << "<= Saving Passenger =>\n\n";

            // Display prompt for Passenger Type
            std::cout << "---------------------------------\n";
            std::cout << "   | Select your passenger type\n";
            std::cout << "---------------------------------\n";
            std::cout << "1. | Veteran\n";
            std::cout << "2. | Nonveteran\n\n";

            // Reads user input for Passenger type and continues to prompt if Input is not within range
            do{
                std::cout << "Enter your selection : ";
                std::cin >> pType;
                if(pType < 1 || pType > 2)
                    std::cout << "Error - Incorrect Selection. Please try again.\n";
            } while(pType < 1 || pType > 2);

            // Calculates the price based on previous input
            switch(pType)
            {
                case 1:
                    discount = price * 0.1;
                    toPay = price - discount;
                    std::cout << "Your ticket price with 10% discount is $" << toPay << std::endl;
                    break;
                case 2:
                    totalPrice = price;
                    std::cout << "Your ticket price is $" << totalPrice << std::endl;
                    break;
                default:
                    break;
            }

            // Displays that inputted user name has successfully reserved seats
            std::cout << "\nDear " << first[i] << " " << last[i] << " - your seat is reserved successfully." << std::endl;

            // Displays rocket specs based on rocket type
            std::cout << "\nYour Rocket Specs" << std::endl;
            std::cout << "Propellant Type: " << propellant << std::endl;
            std::cout << "Acceleration: " << acceleration << " m/s^2" << std::endl;
            std::cout << "Thrust: " << thrust << " Newtons" << std::endl;
            std::cout << "Fuel Capacity: " << fuelCapacity << " gallons" << std::endl;
            std::cout << "Velocity: " << velocity << " mph" << std::endl;
        }

        // Prompts user whether or not to reserve any other seats
        std::cout << "Do you want to book more seats? (y/n) : ";
        std::cin >> ch;
        std::cout << std::endl;

    } while(ch == 'y' || ch == 'Y');

    // Display booked seats
    if(cgCount > 0)
        std::cout << "Booked seats for Cold-Gas Rocket: " << cgCount << std::endl;
    if(cCount > 0)
        std::cout << "Booked seats for Chemical Rocket: " << cCount << std::endl;
    if(tCount > 0)
        std::cout << "Booked seats for Thermoelectric Rocket: " << tCount << std::endl;
    if(hCount > 0)  
        std::cout << "Booked seats for Hybrid Rocket: " << hCount << std::endl;

    // Display the travelling distance
    if(cgCount > 0)
    {
        miles = 25000;
        for(time = 0; remainingDistance <= 0; time++)
        {
            remainingDistance = travelDistance - miles;
            std::cout << "Dear Cold-Gas Rocket passengers..." << std::endl;

            std::cout << "Dear Cold-Gas Rocket passengers..." << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Distance travelled after " << time << " hours is " << miles << " miles" << std::endl;
            std::cout << "Remaining distance is " << remainingDistance << " miles" << std::endl;

            miles += miles;
        }
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Dear Cold-Gas Rocket passengers, we are landing on destination\n\n";
    }

    if(cCount > 0)
    {
        miles = 21000;
        for(time = 0; remainingDistance <= 0; time++)
        {
            remainingDistance = travelDistance - miles;
            std::cout << "Dear Chemical Rocket passengers..." << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Distance travelled after " << time << " hours is " << miles << " miles" << std::endl;
            std::cout << "Remaining distance is " << remainingDistance << " miles" << std::endl;
            miles += miles;
        }
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Dear Chemical Rocket passengers, we are landing on destination\n\n";  
    }

    if(tCount > 0)
    {
        miles = 23000;
        for(time = 0; remainingDistance <= 0; time++)
        {
            remainingDistance = travelDistance - miles;
            std::cout << "Dear Thermoelectric Rocket passengers..." << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Distance travelled after " << time << " hours is " << miles << " miles" << std::endl;
            std::cout << "Remaining distance is " << remainingDistance << " miles" << std::endl;
            miles += miles;
        }
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Dear Thermoelectric Rocket passengers, we are landing on destination\n\n";
    }

    if(hCount > 0)
    {
        miles = 28000;
        for(time = 0; remainingDistance <= 0; time++)
        {
            remainingDistance = travelDistance - miles;
            std::cout << "Dear Hybrid Rocket passengers..." << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Distance travelled after " << time << " hours is " << miles << " miles" << std::endl;
            std::cout << "Remaining distance is " << remainingDistance << " miles" << std::endl;
            miles += miles;
        }
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Dear Hybrid Rocket passengers, we are landing on destination\n\n";
    }

    return 0;
} 

