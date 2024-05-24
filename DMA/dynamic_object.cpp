#include <iostream>
using namespace std;

class Addition
{
private:
    int a, b;

public:
    void set_data(int a, int b);
    int get_sum();
};

int main()
{
    // Dynamic Object
    Addition *ptr = new Addition;
    ptr->set_data(10, 20);
    cout << "SUM is " << ptr->get_sum() << endl;
    delete ptr;
    return 0;
}

void Addition::set_data(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Addition::get_sum()
{
    return (this->a + this->b);
}