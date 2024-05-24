#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int(30);
    cout << "Value int: " << *ptr << endl;
    delete ptr;

    float *float_ptr = new float(22.7);
    cout << "Value float: " << *float_ptr << endl;
    delete float_ptr;


    // Dynamic array
    int *dynamic_array = new int[5];
    for (int i = 0; i < 5; i++)
    {
        *(dynamic_array + i) = (i + 1) * 10;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << *(dynamic_array + i) << " ";
    }
    delete[] dynamic_array;

    return 0;
}