#include <iostream>

using namespace std;

int exp(int baseNum, int powNum){
    int result = 1;
    for(int i = 0; i < powNum; i++){
        result *= baseNum;
    }
    return result;
}

int main(){
    // 2, 3 -> 2^3
    cout << exp(2, 3) << endl;

    // 4, 2 -> 4^2
    cout << exp(4, 2) << endl;

    return 0;
}