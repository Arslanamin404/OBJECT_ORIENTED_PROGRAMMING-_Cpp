#include <iostream>
using namespace std;

/*
* Shallow and Deep copying only happens in heap memory variables example Pointers
! WE DONT NEED TO EXPLICITLY CREATE A COPY CONSTRUCTOR FOR SHALLOW COPY.
? THE COMPILER PROVIDES A DEFAULT COPY CONSTRUCTOR THAT PERFORMS SHALLOW COPYING.
*/

class Number
{
private:
    int *ptr;

public:
    // constructor
    Number(int value);

    // DESTRUCTOR
    ~Number();

    // methods
    void setValue(int val);
    int getValue();
};

int main()
{
    Number original(5);
    Number shallowCopy(original); // shallow copy created

    cout << "Before value change - " << endl;
    cout << "ORIGINAL: " << original.getValue() << endl;
    cout << "SHALLOW COPY: " << shallowCopy.getValue() << endl;

    original.setValue(10);

    cout << "\nAfter value change - " << endl;
    cout << "ORIGINAL: " << original.getValue() << endl;
    cout << "SHALLOW COPY: " << shallowCopy.getValue() << endl;

    /*
    Since we did Shallow Copy as we did not make any user defined copy constructor
    Changes in obj1 is reflected in obj2
    */

    return 0;
}

// constructor definiton;
Number::Number(int value)
{
    ptr = new int(value);
}

// destructor definition
Number::~Number()
{
    delete ptr;
}

void Number::setValue(int val)
{
    *ptr = val;
}
int Number::getValue()
{
    return *ptr;
}