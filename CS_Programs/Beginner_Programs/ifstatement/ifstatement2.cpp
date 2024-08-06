#include <iostream>

using namespace std;

int getMax(int num1, int num2, int num3){
    
    int result;

    // Comparisons: <, >, ==, !=
    // Less than, Greater than, Equal to, Not Equal to
    // <= : Less than or equal to, >= : Greater than or equal to
    // When comparing two numbers,
    // if(num1 > num2){
    //     result = num1;
    // } else {
    //     result = num2;
    // }

    // When comparing three numbers,
    if(num1 >= num2 && num1 >= num3){
        result = num1;
    } else if(num2 >= num1 && num2 >= num3){
        result = num2;
    } else {
        result = num3;
    }


    return result;
}

int main(){

    cout << getMax(200, 200, 10) << endl;
    return 0;
}