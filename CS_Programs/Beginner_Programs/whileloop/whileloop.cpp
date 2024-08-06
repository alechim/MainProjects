#include <iostream>

using namespace std;

int main(){

    int index = 1;
    // Loop starts only if condition is met
    while(index <= 5){
        cout << index << endl;
        index++;
    }

    index = 0;

    // Runs once and then loops based on condition
    do{
        cout << index << endl;
        index++;
    } while(index <= 5);

    return 0;
}