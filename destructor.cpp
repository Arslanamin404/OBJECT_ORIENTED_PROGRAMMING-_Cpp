#include <iostream>
using namespace std;

class Test
{
private:
    int size;
    int *data;
    int num;

public:
    // constructor
    Test(int num, int size);

    // destructor
    ~Test();

    // other member functions
};

int main()
{
    // objects are destroyed in their reverse order
    Test t1(1, 5);
    Test t2(2, 12);
    Test t3(3, 8);

    return 0;
}

// Constructor
Test::Test(int num, int size)
{
    this->num = num;
    this->size = size;
    data = new int[size]; // Allocate memory
    cout << "Constructor number " << num << " called." << endl;
    cout << "Dynamic array of SIZE " << size << " created.\n"
         << endl;
}

// Constructor

Test::~Test()
{
    delete[] data; // Free allocated memory
    cout << "Destructor number " << num << " called." << endl;
    cout << "Dynamic array of SIZE " << size << " destroyed.\n"
         << endl;
}
