#include <iostream>

using namespace std;

// 2^3 (cubed) => 2 * 2 * 2
double cube(double num){

    return num * num * num;
    
    // Since return keyword is used, function returns to main (breaks out)
    cout << "Hello" << endl;

}

int main(){

    cout << cube(5.0) << endl;

    return 0;
}