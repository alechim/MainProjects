#include <iostream>

using namespace std;

// version 1: Constructor with no Params
// classes_objects.cpp
class Book{
    public:
        string title;
        string author;
        int pages;

        // Added Code (Constructor)
        // v1 (No Params)
        Book(){
            // Outputs whenever a new Book class is created
            cout << "Creating Object" << endl;
        }

};

int main(){
    
    // classes_objects.cpp
    // =====
    // v1 (No Params)
    // =====
    Book book1;
    book1.title = "Harry Potter";
    book1.author = "JK Rowling";
    book1.pages = 500;

    Book book2;
    book2.title = "Lord of the Rings";
    book2.author = "Tolkein";
    book2.pages = 700;

    return 0;
}