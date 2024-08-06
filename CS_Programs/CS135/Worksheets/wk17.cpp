/*
 * Alec Him
 * CS 135 - Worksheet 17
 * Description: Simple program that reverses the names in an array
 * Input: None
 * Output: Before and After Reversed Names
 */
#include <iostream>

void reverseNames(std::string pet[], std::string owner[], int size);

void reverseNames(std::string pet[], std::string owner[], int size)
{
    std::string petReverse[5], ownerReverse[5];

    for(int i = 0; i < size; i++)
    {
        petReverse[i] = pet[size - i - 1];
        ownerReverse[i] = owner[size - i - 1];
    }

    for(int i = 0; i < size; i++)
    {
        pet[i] = petReverse[i];
        owner[i] = ownerReverse[i];
    }
}

int main()
{
    // Variables
    std::string pet[5] = {"Hobbs", "Snoopy", "Odie", "Garfield", "Pluto"};
    std::string owner[5] = {"Calvin", "Charlie", "Jon", "Jon", "Mickey"};

    std::cout << "Initial array values" << std::endl;
    for(int i = 0; i < 5; i++)
        std::cout << pet[i] << " " << owner[i] << std::endl;

    reverseNames(pet, owner, 5);
    std::cout << "\nAfter reverse\n";
    
    for(int i = 0; i < 5; i++)
        std::cout << pet[i] << " " << owner[i] << std::endl;

    return 0;
}