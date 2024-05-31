/*
!---------------------
!|   LIBRARY SYSTEM  |
!---------------------
*Define a base class LibraryItem with:
    Protected member variables title and itemID.
    Public constructor to initialize title and itemID.
    Public member function displayInfo() that prints the title and item ID.
*Define a derived class Book that:
    Inherits from LibraryItem.
    Has private member variables author and pageCount.
    Provides a constructor to initialize title, itemID, author, and pageCount.
*/

#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
protected:
    int item_id;
    string title;

public:
    LibraryItem(int item_id, string title) : item_id(item_id), title(title) {}

protected:
    // im making it protected so that it can not be accessed outside of the class
    void display_item()
    {
        cout << "ITEM ID: " << this->item_id << endl;
        cout << "TITLE: " << this->title << endl;
    }
};

// derived class
class Book : public LibraryItem
{
    string author;
    int page_count;

public:
    // constructor using initializer list
    Book(int item_id, string title, string author, int page_count) : LibraryItem(item_id, title), author(author), page_count(page_count) {}

    void display_book()
    {
        display_item();
        cout << "AUTHOR: " << this->author << endl;
        cout << "PAGE COUNT: " << this->page_count << endl;
        cout << "------------------------------------------------" << endl;
    }
};

int main()
{
    Book book1(101, "Admin is testing", "ADMIN", 404);
    Book book2(10003, "Pride and Prejudice", "Jane Austen", 279);
    Book book3(10004, "The Hobbit", "J.R.R. Tolkien", 310);
    Book book4(10005, "Moby Dick", "Herman Melville", 635);

    book1.display_book();
    book2.display_book();
    book3.display_book();
    book4.display_book();
    return 0;
}