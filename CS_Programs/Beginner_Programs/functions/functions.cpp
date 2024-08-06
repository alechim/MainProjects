#include <iostream>

using namespace std;

// Must use function signatures if planning to have additional functions below main

// Function Signatures
void sayHi(string name, int age);

int main(){

    sayHi("Mike", 16);
    sayHi("Tom", 22);
    sayHi("Brittany", 32);
    sayHi("Bill", 8);

    return 0;
}

// void: No return value
void sayHi(string name, int age){
    cout << "Hello " << name << ". You are " << age << " years old.\n";
}