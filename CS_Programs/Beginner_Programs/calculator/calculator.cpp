#include <iostream>
#include <cmath>

using namespace std;

int main(){

    // Can use integers or doubles/floats
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Addition
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

    // Subtraction
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;

    // Multiplication
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    
    // Division
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;

    // Modulus (Can only be used with int variables)
    cout << num1 << " % " << num2 << " = " << num1 % num2 << endl;

    return 0;
}