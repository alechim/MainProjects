#include <iostream>

using namespace std;

class Book{
    public:
        string title;
        string author;
        int pages;
};

int main(){

    string name = "Mike";
    double pi = 3.14;
    char favoriteLetter = 'G';
    // No Book datatype

    // Class is the specification/blueprint of a datatype
    // Object is an instance of the class
    Book book1;
    book1.title = "Harry Potter";
    book1.author = "JK Rowling";
    book1.pages = 500;

    Book book2;
    book2.title = "Lord of the Rings";
    book2.author = "Tolkein";
    book2.pages = 700;
    // replaces existing class variable
    // book2.title = "Hunger Games";

    cout << book1.title << endl;
    cout << book1.author << endl;
    cout << book1.pages << endl;
    cout << "=====" << endl;
    cout << book2.title << endl;
    cout << book2.author << endl;
    cout << book2.pages << endl;

    return 0;
}