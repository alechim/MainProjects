/* CS 202 FALL 2020
   This skeleton code was developed by James Piotrowski - UNLV Computer Science */

#include <iostream>
#include <string>
#include <fstream>
#include "WeaponClass.h"

/********************************************************************************************************/
/*                              Super Class                                        */
/********************************************************************************************************/

class PlayerClass
{
    public:
        // Constructors and Destructor
        PlayerClass();
        PlayerClass(char, std::string, int, int);
        ~PlayerClass();

        // Functions
        void EquipWeapon(std::string); // Will alter the Weapon in the WeaponSlot.
        void DoDamage(PlayerClass&);  // Will do damage to another player.
        void TakeDamage(int); // A function to subtract from HealthPoints.

        // Getters
        char GetPlayerType(); // Returns the PlayerType
        std::string GetPlayerName(); // Returns the PlayerName
        static int GetPlayerCount();  // Returns the PlayerCount -- This is Static

  /* Protected Members. Derived class instances will be able to inheret and access
     these members. Protected is not accesible to anything but the Base Class and
     Derived Classes. */
    protected:
        std::string PlayerName;  // PlayerName --> {PlayerType Color} + {PlayerCount} --> i.e. "Red1", "Blue2", "Blue3", "Green4", etc..
        char PlayerType;  // Either 'r', 'b', 'g'
        int Strength; // Strength Level
        int Skill;  // Skill Level
        int HealthPoints; // Health Points --> 25 by default
        WeaponClass WeaponSlot; // Choice of Weapon
        static int PlayerCount; // Keeps track of the number of Players. Should be incremented in Constructors -- Notice it is Static
        std::ofstream out; // For the Player Log
};

// YOUR CODE HERE
// Initializes PlayerCount to 0
int PlayerClass::PlayerCount = 0;

// Constructs PlayerClass
PlayerClass::PlayerClass()
{
    PlayerName = " ";        // Player Name to Empty String
    PlayerType = '\0';      // Player Type to NULL
    Strength = 0;           // Sets Strength to 0
    Skill = 0;              // Sets Skill to 0
    HealthPoints = 25;      // Sets Health to 25
}

// PlayerClass Constructor with Parameters
PlayerClass::PlayerClass(char type, std::string name, int str, int sk)
{
    // Variables
    PlayerType = type;
    PlayerName = name;
    Strength = str;
    Skill = sk;
    HealthPoints = 25;      // Sets Health to 25
    PlayerCount++;          // Increments Player Count
    std::string file = "";  // Initializes file name

    // Creates filenames (i.e: Red1.txt)
    file = name + ".txt";

    // Opens Created File Name and Inputs PlayerName to Log File
    out.open(file);
    if(out.is_open())
        out << name << " has been spawned\n";
}

// PlayerClass Deconstructor
PlayerClass::~PlayerClass()
{
    if(out.is_open())
    {
        out << PlayerName << " has been despawned\n";
        out.close();
    }
}

// Displays and Sets in Log File the amount of damage a player takes and "despawns" players when Health <= 0
void PlayerClass::TakeDamage(int damage)
{
    std::cout << PlayerName << " has taken " << damage << " damage!" << std::endl; // Prints message onto screen
    if(out.is_open())
        out << PlayerName << " took " << damage << " damage!\n";  // Writes this in the out file (Player Log)

    if(HealthPoints <= 0)
    {
        HealthPoints = 0;
        std::cout << PlayerName << " has reached 0 health! They can no longer battle...\n" << std::endl;
        if(out.is_open())
            out << PlayerName << " has reached 0 health\n";
    } else 
        HealthPoints -= damage;
}

// Placement function to calculate damage dealt to other players; overridden by other Player Type DoDamage Functions
void PlayerClass::DoDamage(PlayerClass& pClass)
{
    int damage = WeaponSlot.CalculateDamage(Strength, Skill);
    pClass.TakeDamage(damage);
}

// Changes the current weapon players have equipped with the inputted one and displays the info in the log file
void PlayerClass::EquipWeapon(std::string weapon)
{
    // Replaces current weapon with inputted one
    WeaponSlot.SetWeapon(weapon);
    // Enters that PlayerName has equipped a weapon in the log file
    if(out.is_open())
        out << PlayerName << " equipped a " << weapon << std::endl;
}

/********************************************************************************************************/
/*                              Red Class                                         */
/********************************************************************************************************/

class RedClass: public PlayerClass
{
    public:
        RedClass();                     // Constructor
        void DoDamage(PlayerClass&);    // DoDamage Override
};

// YOUR CODE HERE
// - Static Counters
static int RedCount = 0;
static int BlueCount = 0;
static int GreenCount = 0;

// Red Class Constructor
RedClass::RedClass() : PlayerClass('r', std::string("Red") + std::to_string(RedCount++), 3, 1)
{
    // ...
}

// Red Class Damage Dealt
void RedClass::DoDamage(PlayerClass& red)
{
    // Variables
    std::string Enemy = red.GetPlayerName();  // Creates Enemy to store and test player type
    char EnemyType = red.GetPlayerType();
    int damage = 0;         // Initialize damage to 0

    // Displays text to output file and terminal
    if(out.is_open())
        out << PlayerName << " is attacking " << Enemy << " \n";
    std::cout << PlayerName << " is attacking " << Enemy << " ";

    // Checks and deals damage based on enemy type
    // - R = 0.5x damage, B = 0, G = 2x damage
    damage = WeaponSlot.CalculateDamage(Strength, Skill);
    switch(EnemyType)
    {
        case 'r':
            damage = damage / 2;
            std::cout << "That was not very effective!" << std::endl;
            break;
        case 'b':
            break;
        case 'g':
            damage = damage * 2;
            std::cout << "That was super effective!" << std::endl;
            break;
        default:
            break;
    }
    red.TakeDamage(damage);
}

/********************************************************************************************************/
/*                              Blue Class                                         */
/********************************************************************************************************/

class BlueClass: public PlayerClass
{
    public:
        BlueClass();                    // Constructor
        void DoDamage(PlayerClass&);    // DoDamage Override
};

// YOUR CODE HERE
// Blue Class Constructor
BlueClass::BlueClass(): PlayerClass('b', std::string("Blue") + std::to_string(BlueCount++), 1, 3)
{
    // ...
}

// Blue Class Damage Dealt
void BlueClass::DoDamage(PlayerClass& blue)
{
    // Variables
    std::string Enemy = blue.GetPlayerName();  // Creates Enemy to store and test player type
    char EnemyType = blue.GetPlayerType();
    int damage = 0;         // Initialize damage to 0

    // Displays text to output file and terminal
    out << PlayerName << " is attacking " << Enemy << " \n";
    std::cout << PlayerName << " is attacking " << Enemy << " ";

    // Checks and deals damage based on enemy type
    // - R = 2x damage, B = 0.5x damage, G = 0
    damage = WeaponSlot.CalculateDamage(Strength, Skill);
    switch(EnemyType)
    {
        case 'r':
            damage = damage * 2;
            std::cout << "That was super effective!" << std::endl;
            break;
        case 'b':
            damage = damage / 2;
            std::cout << "That was not very effective!" << std::endl;
            break;
        case 'g':
            break;
        default:
            break;
    }
    blue.TakeDamage(damage);
}

/********************************************************************************************************/
/*                              Green Class                                         */
/********************************************************************************************************/

class GreenClass: public PlayerClass
{
    public:
        GreenClass();                   // Constructor
        void DoDamage(PlayerClass&);    // DoDamage Override
};

// YOUR CODE HERE
// Green Class Constructor
GreenClass::GreenClass(): PlayerClass('g', std::string("Green") + std::to_string(GreenCount++), 2, 2)
{
    // ...
}

// Green Class Damage Dealt
void GreenClass::DoDamage(PlayerClass& green)
{
    // Variables
    std::string Enemy = green.GetPlayerName();  // Creates Enemy to store and test player type
    char EnemyType = green.GetPlayerType();
    int damage = 0;         // Initialize damage to 0

    // Displays text to output file and terminal
    out << PlayerName << " is attacking " << Enemy << " \n";
    std::cout << PlayerName << " is attacking " << Enemy << " ";

    // Checks and deals damage based on enemy type
    // - R = 0, B = 2x damage, G = 0.5x damage
    damage = WeaponSlot.CalculateDamage(Strength, Skill);
    switch(EnemyType)
    {
        case 'r':
            break;
        case 'b':
            damage = damage * 2;
            std::cout << "That was super effective!" << std::endl;
            break;
        case 'g':
            damage = damage / 2;
            std::cout << "That was not very effective!" << std::endl;
            break;
        default:
            break;
    }
    green.TakeDamage(damage);
}

// - Getters
char PlayerClass::GetPlayerType(){
    return PlayerType;
}

std::string PlayerClass::GetPlayerName(){
    return PlayerName;
}

int PlayerClass::GetPlayerCount(){
    return PlayerCount;
}
