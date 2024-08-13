/*
 * Alec Him
 * CS 202 - Assignment 3
 * Description: A project that utilizes multi-file classes with polymorphism and inheritance
 *              A game that represents three different classes of players and their weapons
 * Input: None
 * Output: Name.txt - represents the actions and logs of each individual player
 */
#include <iostream>
#include "PlayerClass.h"

int main()
{
    std::cout << "/****\\ GAME START /****\\\n";

    // Red Players
    RedClass r[4];
    r[0].EquipWeapon("Sword");
    r[1].EquipWeapon("Staff");
    r[2].EquipWeapon("Bow");
    r[3].EquipWeapon("Saradomin Godsword"); // This will give the player Bare Hands

    // Blue Players
    BlueClass b[3];
    b[0].EquipWeapon("Sword");
    b[1].EquipWeapon("Staff");
    b[2].EquipWeapon("Bow");

    // Green Players
    GreenClass g[3];
    g[0].EquipWeapon("Sword");
    g[1].EquipWeapon("Staff");
    g[2].EquipWeapon("Bow");

    std::cout << "************************\nThere are " << PlayerClass::GetPlayerCount() << " Players.\n************************\n";
    r[3].DoDamage(g[2]);
    g[2].DoDamage(r[1]);
    b[1].DoDamage(r[1]);

    // R1 Can't Battle Anymore
    std::cout << std::endl << r[3].GetPlayerName() << " - {I can't believe this Red is using a Bow!}\n" << std::endl;

    r[3].DoDamage(r[2]);

    std::cout << std::endl << r[2].GetPlayerName() << " - {It is better than bare fists!}\n" << std::endl;

    r[2].DoDamage(r[3]);

    std::cout << std::endl << b[1].GetPlayerName() << " - {ENOUGH OF THIS CHILDISH BICKERING NOOBS!}\n" << std::endl;

    b[1].DoDamage(r[2]);
    b[1].DoDamage(r[3]);
    b[1].DoDamage(r[2]);
    b[1].DoDamage(r[3]);

    // R3 and R2 are out...
    std::cout << std::endl << r[0].GetPlayerName() << " - {My teammates! I AM ENRAGED!}\n" << std::endl;

    r[0].DoDamage(b[1]);
    r[0].DoDamage(b[1]);

    std::cout << std::endl << g[2].GetPlayerName() << " - {Here.. I can help!}\n" << std::endl;

    g[2].DoDamage(b[1]);

    // B1 is gone
    std::cout << std::endl << r[0].GetPlayerName() << " - {I DID NOT WANT YOUR HELP!}\n" << std::endl;

    r[0].DoDamage(g[2]);
    r[0].DoDamage(g[2]);

    // G2 is gone
    g[0].DoDamage(b[0]);
    b[0].DoDamage(g[0]);
    g[0].DoDamage(b[0]);

    g[1].DoDamage(b[2]);
    b[2].DoDamage(g[1]);
    g[1].DoDamage(b[2]);

    g[0].DoDamage(b[0]);
    g[1].DoDamage(b[2]);

    // B2 and B0 are Gone
    r[0].DoDamage(g[0]);
    r[0].DoDamage(g[1]);
    r[0].DoDamage(g[0]);
    r[0].DoDamage(g[1]);

    std::cout << std::endl << r[0].GetPlayerName() << " - {I AM THE CHAMPION!}\n" << std::endl;    
    std::cout << "/****\\ GAME OVER /****\\\n";

    return 0;
}