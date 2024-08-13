/* CS 202 FALL 2020
   This skeleton code was developed by James Piotrowski - UNLV Computer Science */

#include <iostream>
#include <string>

/********************************************************************************************************/
/*                              Weapon Class                                       */
/********************************************************************************************************/

class WeaponClass
{
    public:
        WeaponClass();  // Constructor
        std::string GetName(); // GetName returns the WeaponName
        void SetWeapon(std::string); // Changes the Weapon Name
        int CalculateDamage(int, int);  // Determines damage dealt by weapon
    private:
        std::string name;  // The Weapon Name - "Sword", "Bow", "Staff", or "Bare Hands"
        const int Damage = 3; // Base Damage for all Weapons except Bare Hands
};

// YOUR CODE HERE
// Constructor Function
WeaponClass::WeaponClass()
{
    name = "Bare Hands";
}

// Reads and returns the name of the weapon
std::string WeaponClass::GetName()
{
    return name;  // returns the name
}

// Sets the name of the weapon to the string
void WeaponClass::SetWeapon(std::string weapon)
{
    if(weapon == "Sword" || weapon == "Bow" || weapon == "Staff")
    {
        name = weapon;
        std::cout << "Weapon is: " << name << std::endl;
    } else {
        weapon = "Bare Hands";
        name = "Bare Hands";
        std::cout << "ERROR: Unknown Weapon" << std::endl;
    }
}

// Calculates damage based on weapon type
int WeaponClass::CalculateDamage(int Strength, int Skill)
{
    // Variables
    std::string tmp = GetName();
    int Calculation = 0;  // Used to store the calculations of damage based on each weapon

    if(tmp == "Sword")
    {
        Calculation = Strength * Damage;
        std::cout << "**CLANG**" << std::endl; 
    } else if(tmp == "Staff"){
        Calculation = Skill * Damage;
        std::cout << "**POW**" << std::endl;
    } else if(tmp == "Bow"){
        int tmp = Strength - Skill;
        if(Strength - Skill < 0)
            tmp *= -1;
        Calculation = tmp * Damage;
        std::cout << "**FWOOSH**" << std::endl;
    } else if(tmp == "Bare Hands"){
        Calculation = 1;
        std::cout << "**pfft**" << std::endl;
    } else {
        Calculation = 0;
        std::cout << "ERROR: Unknown Weapon" << std::endl; 
    }

    return Calculation;
}
