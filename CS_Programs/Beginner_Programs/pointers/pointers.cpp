#include <iostream>

using namespace std;

/*
    cout << "Age: " << &age << endl;
    cout << "Gpa: " << &gpa << endl;
    cout << "Name: " << &name << endl;
*/

int main(){
    // =====
    // Part 1
    // =====
    int age = 19;
    double gpa = 2.7;
    string name = "Mike";

    // Prints out the memory addresses (pointer)
    cout << "Age: " << &age << endl;
    cout << "Gpa: " << &gpa << endl;
    cout << "Name: " << &name << endl;

    // =====
    // Part 2
    // =====
    // Store memory addresses into pointers
    int *pAge = &age;
    double *pGpa = &gpa;
    string *pName = &name;

    // Prints memory address of age
    cout << pAge << endl;

    // Dereferencing pointer
    cout << *pAge << endl;
    cout << *&gpa << endl;

    return 0;

}