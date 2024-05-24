#include <iostream>
#include <string>
using namespace std;

class Hero
{
private:
    // Properties or Attributes
    string name;
    int health;
    char level;

public:
    // Default constructor
    Hero(){};

    // Parameterized constructor
    Hero(string name, int health, char level);

    // copy Constructor
    Hero(Hero &temp);

    // methods
    void display_heroInfo();
};

// constructor definiton;
Hero::Hero(string name, int health, char level)
{
    cout << "Constructor Called as soon as object is created." << endl;
    // `this` contains the address of current object
    cout << "this -> " << this << endl;
    this->name = name;
    this->health = health;
    this->level = level;
}
// copy constructor definiton;
Hero::Hero(Hero &temp)
{
    this->name = temp.name;
    this->health = temp.health;
    this->level = temp.level;
}

void Hero::display_heroInfo()
{
    cout << "Hero Name: " << name << endl;
    cout << "Hero Health: " << health << endl;
    cout << "Hero Level: " << level << endl
         << endl;
}

int main()
{
    // object of class using constructor
    Hero h1("Omen", 85, 'B');
    cout << "Address of h1: " << &h1 << endl;
    h1.display_heroInfo();

    // user defined copy constructor called
    Hero h2(h1);
    h2.display_heroInfo();

    return 0;
}