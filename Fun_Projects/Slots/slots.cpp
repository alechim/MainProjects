#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Initializers
bool checkBoard(int slots[3][3]){

    // Rows
    if((slots[0][0] == slots[0][1] && slots[0][1] == slots[0][2]) || 
       (slots[1][0] == slots[1][1] && slots[1][1] == slots[1][2]) ||
       (slots[2][0] == slots[2][1] && slots[2][1] == slots[2][2])
    ){
        cout << "Matching Row!" << endl;
        return true;
    // Columns
    } else if((slots[0][0] == slots[1][0] && slots[1][0] == slots[2][0]) || 
              (slots[0][1] == slots[1][1] && slots[1][1] == slots[2][1]) ||
              (slots[0][2] == slots[1][2] && slots[1][2] == slots[2][2])){
        cout << "Matching Column!" << endl;
        return true;
    // Diagonals
    } else if((slots[0][0] == slots[1][1] && slots[1][1] == slots[2][2]) || 
              (slots[2][0] == slots[1][1] && slots[1][1] == slots[0][2])){
        cout << "Matching Diagonal!" << endl;
        return true;
    }

    return false;

}

int main(){

    bool run = true;
    int slots[3][3];
    string select;

    while(true){
        cout << "- Enter 'e' to exit game:\n";
        cout << "- Hit enter to roll slots: ";
        getline(cin, select);
        if(select == "e"){
            cout << "Exiting..." << endl;
            return 0;
        }        

        // Number Generator
        srand(time(0));
        int rand(void);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                // Randomizes values between 1-6
                slots[i][j] = rand() % 6+1;
            }
        }

        // Display
        cout << "=============" << endl;
        for(int i = 0; i < 3; i++){
            cout << "| ";
            for(int j = 0; j < 3; j++){
                cout << slots[i][j] << " | ";
            }
            if(i != 2){
                cout << "\n-------------\n";
            }
        }
        cout << "\n=============" << endl;

        if(checkBoard(slots)){
            cout << "You Win!" << endl;
            return 0;
        }

    }

    return 0;
}