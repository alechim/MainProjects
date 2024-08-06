#include <iostream>

using namespace std;

int main(){

    int numberGrid[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    // 2
    cout << numberGrid[0][1] << endl;

    // 5
    cout << numberGrid[2][0] << endl;

    return 0;
}