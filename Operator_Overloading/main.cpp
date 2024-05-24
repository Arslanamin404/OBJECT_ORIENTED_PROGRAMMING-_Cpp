#include <iostream>
using namespace std;

class Distance
{
private:
    int feet, inch;
    void normalize()
    {
        if (inch >= 12)
        {
            inch -= 12;
            feet++;
        }
    }

public:
    Distance() { feet = 0, inch = 0; };

    // parameterized constructor
    Distance(int feet, int inch);

    // Pre increment operator overloading
    Distance operator++();

    // Pre decrement operator overloading
    Distance operator--();

    // Post increment operator overloading
    Distance operator++(int);

    // Post decrement operator overloading
    Distance operator--(int);

    // + operator overloading
    Distance operator+(const Distance &other);

    // insertion operator overloading
    friend ostream &operator<<(ostream &out, Distance &d);

    // extraction operator overloading
    friend istream &operator>>(istream &in, Distance &d);
};

int main()
{
    Distance d1(12, 7);
    Distance d5;

    cin >> d5;
    cout << "D5 = " << d5 << endl;
    cout << "\n-------------------------------------------" << endl;
    Distance d2(2, 8);

    cout << "D1 = " << d1 << endl;
    cout << "D2 = " << d2 << endl;
    cout << "-------------------------------------------" << endl;

    Distance d3 = d1 + d2;

    cout << "D1 + D2 =  " << d3 << endl;

    cout << "-------------------------------------------" << endl;
    cout << "Pre increment Operator used on D1 & assigned to D4: " << endl;
    Distance d4 = ++d1;

    ++d4;
    ++d4;
    ++d4;
    ++d4;
    ++d4;
    ++d4;
    ++d4;

    cout << d4 << endl;
    cout << "-------------------------------------------" << endl;

    cout << "Pre decrement Operator used on D4: " << endl;
    --d4;
    --d4;
    cout << d4 << endl;

    Distance d6 = d5;
    cout << "D6: " << d6 << endl;
    return 0;
}

Distance::Distance(int feet, int inch)
{
    this->feet = feet;
    this->inch = inch;
    this->normalize();
}

// Pre increment operator overloading
Distance Distance::operator++()
{
    this->inch++;
    this->normalize();
    return *this;
}

// Pre decrement operator overloading
Distance Distance::operator--()
{
    this->inch--;
    this->normalize();
    return *this;
}

// Post increment operator overloading
Distance Distance::operator++(int)
{
    Distance temp = *this; // copy of current obj
    this->inch++;
    this->normalize();
    return temp;
}

// Post decrement operator overloading
Distance Distance::operator--(int)
{
    Distance temp = *this; // copy of current obj
    this->inch--;
    this->normalize();
    return temp;
}

Distance Distance::operator+(const Distance &other)
{
    return Distance(this->feet + other.feet, this->inch + other.inch);
}

ostream &operator<<(ostream &out, Distance &d)
{
    out << d.feet << " feet and " << d.inch << " inches";
    return out;
}

istream &operator>>(istream &in, Distance &d)
{
    cout << "Feet: ";
    in >> d.feet;

    cout << "Inches: ";
    in >> d.inch;

    d.normalize();
    return in;
}
