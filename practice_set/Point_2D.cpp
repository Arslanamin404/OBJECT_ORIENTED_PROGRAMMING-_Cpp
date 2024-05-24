/*
Create a class Point to represent a point in 2D space with attributes for X & Y coordinates.
Include member function to calculate distance between 2 points and to display the coordinates
*/
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    double x, y;

public:
    // default constructor
    Point() { x = 0, y = 0; };

    // parameterized constructor
    Point(double x, double y);

    // insertion operator overloading
    friend ostream &operator<<(ostream &out, Point &p);

    // extraction operator overloading
    friend istream &operator>>(istream &in, Point &p);

    double get_distance(Point p2);
};

int main()
{
    Point pointA(2, 3);
    cout << "Coordinates of Point A: " << pointA << endl;

    Point pointB;
    cin >> pointB;
    cout << "Coordinates of Point B: " << pointB << endl;

    cout << "Distance: " << pointA.get_distance(pointB) << " units" << endl;
    return 0;
}

// Parameterized constructor definition
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

ostream &operator<<(ostream &out, Point &p)
{
    out << "(x: " << p.x << ", y: " << p.y << ")";
    return out;
}

istream &operator>>(istream &in, Point &p)
{
    cout << "x coordinate: ";
    in >> p.x;
    cout << "y coordinate: ";
    in >> p.y;
    return in;
}

double Point::get_distance(Point p2)
{
    // distance = sqrt((x2-x1)^2 + (y2-y1)^2)
    return sqrt(pow((p2.x - x), 2) + pow((p2.y - y), 2));
}