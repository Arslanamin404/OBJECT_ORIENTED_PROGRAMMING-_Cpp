#include <iostream>
using namespace std;

class Test
{
    int a;

public:
    Test(int a)
    {
        this->a = a;
    }

    int get_val()
    {
        return this->a;
    }

    // > operator overloading
    bool operator>(const Test &other);

    // < operator overloading
    bool operator<(const Test &other);

    // == operator overloading
    bool operator==(const Test &other);

    // != operator overloading

    bool operator!=(const Test &other);

    // += operator overloading
    Test operator+=(const Test other);
};

int main()
{
    Test t1(21), t2(52);

    (t1 > t2) ? cout << t1.get_val() << " is greater" << endl : cout << t2.get_val() << " is greater" << endl;
    (t1 == t2) ? cout << t1.get_val() << " is Equal to " << t2.get_val() << endl : cout << t1.get_val() << " is Not Equal to " << t2.get_val() << endl;

    cout << t1.get_val() << endl;
    t1 += 2;
    cout << t1.get_val() << endl;

    return 0;
}

bool Test::operator>(const Test &other)
{
    return (this->a > other.a);
}

bool Test::operator<(const Test &other)
{
    return (this->a < other.a);
}

bool Test::operator==(const Test &other)
{
    return (this->a == other.a);
}

bool Test::operator!=(const Test &other)
{
    return (this->a != other.a);
}

Test Test::operator+=(const Test other)
{
    // t1+=t2;
    // t1 = t1+t2;
    this->a += other.a;
    return *this;
}
