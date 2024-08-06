#include <iostream>

using namespace std;

int main(){

    string phrase = "Giraffe Academy";
    //               0123456 789...
    phrase[0] = 'B';
    // String Function: .length()
    // Tells how many characters are within a string
    cout << phrase.length() << endl;

    // String Function: .find("string", index)
    // Finds if the specified character is within a string
    // - Index specifies where the function starts looking
    // - Returns index of where string found begins
    cout << phrase.find("Academy", 0) << endl;

    // String Function: .substr(starting index, limit # of char)
    // Grabs a new string from the specified index and generates based on
    // how many allowed characters
    // - Giraffe Academy => Aca
    cout << phrase.substr(8, 3) << endl;

    string phrasesub;
    phrasesub = phrase.substr(8, 3);
    cout << phrasesub << endl;

    // Uses array index to display character of string
    cout << phrase[0] << endl;

    cout << phrase << endl;

    return 0;
}