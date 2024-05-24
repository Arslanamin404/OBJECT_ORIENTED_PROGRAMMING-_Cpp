#include <iostream>
using namespace std;

// class AddHeights; //forward declaration

class Height
{
private:
    int feet, inch;

public:
    // default constructor
    Height()
    {
        this->feet = 0;
        this->inch = 0;
    }
    // parameterized constructor
    Height(int feet, int inch)
    {
        this->feet = feet;
        this->inch = inch;
    }

    void display()
    {
        cout << this->feet << " Feet " << this->inch << " inches" << endl;
    }

    friend class AddHeights;
};

class AddHeights
{
private:
    Height temp;

public:
    AddHeights(Height &h1, Height &h2)
    {
        temp.feet = h1.feet + h2.feet;
        temp.inch = h1.inch + h2.inch;
        if (temp.inch >= 12)
        {
            temp.inch -= 12;
            temp.feet++;
        }
    }

    void display_total_height()
    {

        cout << "TOTAl HEIGHT: " << temp.feet << " Feet " << temp.inch << " inches" << endl;
    }
};

int main()
{
    Height h1(20, 8);
    Height h2(10, 10);

    h1.display();
    h2.display();
    
    AddHeights obj(h1, h2);

    obj.display_total_height();
    return 0;
}