#include <iostream>

using namespace std;

int main(){

    // Logic Table (~ is the same as !) [negation]
    // X && Y = T     | X && Y = T
    // ~X && Y = F    | ~X && Y = T
    // X && ~Y = F    | X && ~Y = T
    // ~X && ~Y = F   | ~X && ~Y = F

    bool isMale = true;
    bool isTall = true;

    if(isMale && isTall){
        cout << "You are a tall male.\n";
    } else if(isMale && !isTall){
        cout << "You are a short male.\n";
    } else if(!isMale && isTall){
        cout << "You are tall but not male.\n";
    } else {
        cout << "You are not male and not tall.\n";
    }

    return 0;
}