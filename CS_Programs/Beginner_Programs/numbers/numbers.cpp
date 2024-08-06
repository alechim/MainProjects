#include <iostream>
#include <cmath>

using namespace std;

int main(){

    // Integers = Whole Numbers
    cout << 40 << endl;
    // - Variables
    int wnum = 5;
    wnum++;     // Post-order Increment
    cout << wnum << endl;       // 6

    wnum--;     // Post-order Decrement
    cout << wnum << endl;       // 5
    
    wnum += 80; // Short-hand operations: wnum = wnum + 80
    // - Can subtract, multiply, divide, modulus as well            

    // Doubles & Floats = Decimal Numbers
    cout << -40.291 << endl;
    // - Variables
    double dnum = 5.5;

    cout << 10 / 3 << endl;     // Returns an integer
    cout << 10 / 3.0 << endl;   // Returns a double (Also works if both are double/float)
    // cout << 10.0 / 3.0 << endl;

    // Operations: Follows rules of PEMDAS
    cout << 5 + 7 << endl;   // Addition
    cout << 5 - 7 << endl;   // Subtraction
    cout << 5 * 7 << endl;   // Multiplication
    cout << 10 / 3 << endl;  // Division
    cout << 10 % 3 << endl;  // Modulus: Remainder of Division

    // =====
    // <cmath> Library
    // =====

    // Can use int, double, or float
    // pow(num1, num2) => int1^int2 => 2^5
    cout << pow(2, 5) << endl;      // 32
    // sqrt(num): returns square root of num
    cout << sqrt(36) << endl;       // 6
    // round(num): rounds a number up or down
    cout << round(4.6) << endl;     // 5
    // ceil(num): rounds a number up
    cout << ceil(4.1) << endl;      // 5
    // floor(num): rounds a number down
    cout << floor(4.8) << endl;     // 4
    // fmax(num1, num2): returns higher number
    cout << fmax(3, 10) << endl;    // 10
    // fmin(num1, num2): returns lower number
    cout << fmin(3, 10) << endl;    // 3
    // sin, cos, tan, log, exp, etc. are included

    return 0;
}