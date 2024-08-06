#include <iostream>

using namespace std;

int main(){
    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    bool outOfGuesses = false;

    // ===
    // Phase 1
    // ===
    // while(secretNum != guess){
    //     cout << "Enter guess: ";
    //     cin >> guess;
    // }

    // cout << "You Win!" << endl;

    // ===
    // Phase 2
    // ===
    while(secretNum != guess && !outOfGuesses){
        if(guessCount < guessLimit){
            cout << "Enter guess: ";
            cin >> guess;
            guessCount++;
        } else {
            outOfGuesses = true;
        }
    }

    if(outOfGuesses){
        cout << "You Lose!" << endl;
    } else {
        cout << "You Win!" << endl;
    }

    return 0;
}