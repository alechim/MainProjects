#include <iostream>

using namespace std;

int main(){
    int index = 1;
    while(index <= 5){
        cout << index << endl;
        index++;
    }

    for(int i = 1; i <= 5; i++){
        cout << i << endl;
    }

    int nums[] = {1, 2, 5, 7, 3};
    for(int i = 0; i < 5; i++){
        cout << nums[i] << endl;
    }

    return 0;
}