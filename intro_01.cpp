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
    // methods
    // Setter methods
    void setName(string hero_name)
    {
        name = hero_name;
    }

    void setHealth(int hero_health)
    {
        if (hero_health >= 0 && hero_health <= 100)
            health = hero_health;
        else
            cout << "ERROR: Invalid Health '" << hero_health << "'. Health must be between 0-100." << endl;
    }

    void setLevel(char hero_level)
    {
        level = hero_level;
    }

    // Getter methods
    string getName()
    {
        return name;
    }
    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }
};

int main()
{
    // object of hero class
    Hero omen;
    cout << "Size of Hero Class: " << sizeof(omen) << endl;

    omen.setName("OMEN");
    omen.setHealth(800);
    omen.setLevel('A');

    cout << "------------------------------------" << endl;

    cout << "HERO Name: " << omen.getName() << endl;
    cout << "HERO Health: " << omen.getHealth() << endl;
    cout << "HERO Level: " << omen.getLevel() << endl;

    Hero Brimstone;
    Brimstone.setName("Brimstone");
    Brimstone.setHealth(80);
    Brimstone.setLevel('C');

    cout << "------------------------------------" << endl;

    cout << "HERO Name: " << Brimstone.getName() << endl;
    cout << "HERO Health: " << Brimstone.getHealth() << endl;
    cout << "HERO Level: " << Brimstone.getLevel() << endl;

    return 0;
}