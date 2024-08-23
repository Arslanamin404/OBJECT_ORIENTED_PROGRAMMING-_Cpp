//! Problem: Implement a Book class with private members title, author, price, and ISBN-10.
//* WAP to create an array of Book objects and display the details of all books costing more than a specified amount.
//? Requirements:
//? Implement getter and setter methods.
//? Use a constructor to initialize book details.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book
{
    string title;
    string author;
    float price;
    string ISBN_10;

public:
    // default constructor
    Book() {}

    // parameterized constructor
    Book(string title, string author, float price, string ISBN_10)
    {
        this->title = title;
        this->author = author;
        this->price = price;
        if (ISBN_10.length() == 10)
        {
            (this->ISBN_10 = ISBN_10);
        }
        else
        {

            cerr << "ERROR: Invalid ISBN_10! Please enter a 10 digit ISBN." << endl;
        }
    }

    // setter methods
    void set_BookTitle(string title) { this->title = title; }
    void set_BookAuthor(string author) { this->author = author; }
    void set_BookPrice(float price) { this->price = price; }
    void set_BookISBN_10(string ISBN_10) { this->ISBN_10 = ISBN_10; }

    // getter methods
    string get_BookTitle() { return this->title; }
    string get_BookAuthor() { return this->author; }
    float get_BookPrice() { return this->price; }
    string get_BookISBN_10() { return (this->ISBN_10.empty()) ? "Not Available" : this->ISBN_10; }

    void Display_Book()
    {
        cout << "TITLE: " << this->title << endl;
        cout << "AUTHOR: " << this->author << endl;
        cout << "PRICE: $" << this->price << endl;
        cout << "ISBN_10: " << this->ISBN_10 << endl;
    }

    friend ostream &operator<<(ostream &out, Book &new_book)
    {
        out << "TITLE: " << new_book.title << endl;
        out << "AUTHOR: " << new_book.author << endl;
        out << "PRICE: $" << new_book.price << endl;
        out << "ISBN_10: " << new_book.ISBN_10 << endl;

        return out;
    }

    friend istream &operator>>(istream &in, Book &new_book)
    {
        cout << "TITLE: " << endl;
        in >> new_book.title;
        cout << "AUTHOR: " << endl;
        in >> new_book.author;
        cout << "PRICE: $" << endl;
        in >> new_book.price;
        cout << "ISBN_10: " << endl;
        in >> new_book.ISBN_10;

        return in;
    }
};

class FileHandler
{
    string file_name;

public:
    FileHandler(string file_name) : file_name(file_name) {}

    void writeObject(Book &new_book)
    {
        ofstream file(file_name, ios::app);
        if (!file)
        {
            cerr << "Error occurred in writing the data to " << "\" " << file_name << "\"" << endl;
        }
        file << new_book << endl;
        file.close();
    }

    void readObject()
    {
        ifstream file(file_name);
        if (!file)
        {
            cerr << "Error occurred in reading the data from" << "\" " << file_name << "\"" << endl;
        }
        Book new_book;
        while (file >> new_book)
        {
            cout << new_book << endl;
        };
        file.close();
    }
};

int main()
{
    FileHandler Book_data("books.txt");
    string title;
    string author;
    float price;
    string ISBN_10;

    cout << "ENTER BOOK TITLE: ";
    getline(cin, title);
    cout << "ENTER BOOK AUTHOR: ";
    getline(cin, author);
    cout << "ENTER BOOK PRICE $: ";
    cin >> price;
    cin.ignore();
    cout << "ENTER BOOK ISBN_10: ";
    getline(cin, ISBN_10);
    cout << "\n------------------------" << endl;

    Book new_book(title, author, price, ISBN_10);
    Book_data.writeObject(new_book);

    return 0;
}