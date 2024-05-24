/*
Create a class ComplexNumber representing complex numbers with private data members real and imaginary.
Define a friend function add() to add two complex numbers.
*/

#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    int real, imaginary;

public:
    void set_num(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void get_num()
    {
        cout << "Number is (" << real << " + " << imaginary << "i)" << endl;
    }

    friend void add(ComplexNumber &n1, ComplexNumber &n2);
};

int main()
{
    ComplexNumber num1, num2;
    num1.set_num(10, 5);
    num1.get_num();
    num2.set_num(11, 9);
    num2.get_num();

    add(num1, num2);
    return 0;
}

void add(ComplexNumber &n1, ComplexNumber &n2)
{
    ComplexNumber result;

    result.real = n1.real + n2.real;
    result.imaginary = n1.imaginary + n2.imaginary;
    cout << "Sum is (" << result.real << " + " << result.imaginary << "i)" << endl;
}

