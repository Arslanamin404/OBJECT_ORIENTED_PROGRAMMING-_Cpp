#include <iostream>
using namespace std;

//* Shallow and Deep copying only happens in heap memory variables example Pointers

class Number
{
    int *ptr;

public:
    Number(int x)
    {
        ptr = new int(x);
    }

    // Overriding default copy constructor with user defend copy constructor
    Number(Number &temp)
    {
        ptr = new int(*temp.ptr);
    }
    ~Number()
    {
        delete ptr;
    }

    void setValue(int value)
    {
        *ptr = value;
    }
    int getValue()
    {
        return *ptr;
    }
};

int main()
{
    // calling the normal constructor
    Number original(10);

    // calling user defined copy constructor (Deep Copy)
    Number deepCopy(original);

    cout << "Before value change - " << endl;
    cout << "Original: " << original.getValue() << endl;
    cout << "Deep Copy: " << deepCopy.getValue() << endl;

    original.setValue(20);

    cout << "\nAfter value change - " << endl;
    cout << "Original: " << original.getValue() << endl;
    cout << "Deep Copy: " << deepCopy.getValue() << endl;

    // since we did deep copy using user defined copy constructor
    // change in obj1 is not reflected in obj2

    return 0;
}