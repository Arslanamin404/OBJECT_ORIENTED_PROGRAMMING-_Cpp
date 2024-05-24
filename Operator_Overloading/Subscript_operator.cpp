#include <iostream>
using namespace std;
#define MAX_SIZE 20

class MyArray
{
    int data[20];

public:
    // subscript operator overloading
    int &operator[](int &index);
};

int main()
{
    MyArray arr;
    int n;
    cout << "SIZE: ";
    cin >> n;

    // assigning values
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        // arr[i] = (i+1)*2;
    }

    cout << "\n----------------------------------------------" << endl;
    // printing values
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

int &MyArray::operator[](int &index)
{
    if (index < 0 || index >= MAX_SIZE)
    {
        cout << "INDEX ERROR: Index out of range!" << endl;
        exit(1);
    }

    return data[index];
}
