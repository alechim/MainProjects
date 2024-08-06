#include <iostream>
#include <cmath>

using namespace std;

int main(){

    // To grab strings, you must use getline(cin, <var>)
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // cin can be used to grab numbers and characters
    double age;     // int, double, float, char
    // Prompt
    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello " << name << endl;
    cout << "You are " << age << " years old." << endl;

    return 0;
}