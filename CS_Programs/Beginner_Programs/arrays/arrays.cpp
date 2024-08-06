#include <iostream>
#include <cmath>

using namespace std;

int main(){

    // int luckyNums[] = OR int luckyNums[]; OR int luckyNums[20];
    int luckyNums[20] = {4, 8, 15, 16, 23, 42};
    // Indexes:        0  1  2   3   4   5
    
    cout << luckyNums[0] << endl;       // 4
    cout << luckyNums[2] << endl;       // 15

    // Store a variable in the array
    luckyNums[10] = 100;
    cout << luckyNums[10] << endl;

    return 0;
}