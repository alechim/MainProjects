#include <iostream>

using namespace std;

// version 4: Multiple Constructors
class Book{
    public:
        string title;
        string author;
        int pages;

        // v4 (Multiple Constructors)
        Book(){
            title = "no title";
            author = "no author";
            pages = 0;
        }
        Book(string bookTitle, string bookAuthor, int bookPages){
            title = bookTitle;
            author = bookAuthor;
            pages = bookPages;
        }

};

int main(){

    // v4 (Multiple Constructors)
    Book book1("Harry Potter", "JK Rowling", 500);
    Book book2("Lord of the Rings", "Tolkein", 700);
    Book book3;

    cout << book1.title << ", " << book1.author << ", " << book1.pages << endl;
    cout << "=====" << endl;
    cout << book2.title << ", " << book2.author << ", " << book2.pages << endl;
    cout << "=====" << endl;
    cout << book3.title << ", " << book3.author << ", " << book3.pages << endl;

    return 0;
}