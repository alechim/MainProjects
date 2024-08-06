#include <iostream>

using namespace std;

// version 3: Constructor with Multiple Function
class Book{
    public:
        string title;
        string author;
        int pages;

        // v3 (With Multiple Params)
        Book(string bookTitle, string bookAuthor, int bookPages){
            title = bookTitle;
            author = bookAuthor;
            pages = bookPages;
        }

};

int main(){

    // v3 (With Multiple Params)
    Book book1("Harry Potter", "JK Rowling", 500);
    Book book2("Lord of the Rings", "Tolkein", 700);

    cout << book1.title << ", " << book1.author << ", " << book1.pages << endl;
    cout << "=====" << endl;
    cout << book2.title << ", " << book2.author << ", " << book2.pages << endl;

    return 0;
}