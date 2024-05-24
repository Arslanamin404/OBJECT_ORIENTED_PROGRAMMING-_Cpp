#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length, breadth;

public:
    Rectangle() { length = 0, breadth = 0; };

    Rectangle(double length, double breadth);

    double get_area();

    double get_perimeter();

    friend istream &operator>>(istream &in, Rectangle &r);

    friend ostream &operator<<(ostream &out, Rectangle &r);
};

int main()
{
    Rectangle r1(10, 20);
    cout << "Area: " << r1.get_area() << " units" << endl;
    cout << "Perimeter: " << r1.get_perimeter() << " units" << endl;

    cout << "\n---------------------------------------------" << endl;

    Rectangle r2;
    cout << "Enter dimensions for rectangle r2" << endl;
    cin >> r2;
    cout << r2;
    cout << "Area: " << r2.get_area() << " units" << endl;
    cout << "Perimeter: " << r2.get_perimeter() << " units" << endl;
    return 0;
}

Rectangle ::Rectangle(double length, double breadth)
{
    this->length = length;
    this->breadth = breadth;
    cout << "Length: " << length << " units" << endl;
    cout << "Breadth: " << breadth << " units" << endl;
}

double Rectangle::get_area()
{
    return length * breadth;
}

double Rectangle::get_perimeter()
{
    return 2 * (length + breadth);
}

istream &operator>>(istream &in, Rectangle &r)
{
    cout << "LENGTH: ";
    in >> r.length;

    cout << "BREADTH: ";
    in >> r.breadth;

    return in;
}

ostream &operator<<(ostream &out, Rectangle &r)
{
    out << "(L = " << r.length << " units, B = " << r.breadth << " units)" << endl;
    return out;
}
