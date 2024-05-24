#include <iostream>
using namespace std;

class B; // Forward declaration
class A
{
private:
    int num_pvt;

protected:
    int num_protected;

public:
    A()
    {
        num_pvt = 69;
        num_protected = 169;
    }
    friend class B;
};

class B
{
public:
    void get_num(A &obj)
    {
        cout << "Value of Private member of CLASS A: " << obj.num_pvt << endl;
        cout << "Value of Protected member of CLASS A: " << obj.num_protected << endl;
    }
};

int main()
{
    A obj_A;
    B obj_B;
    obj_B.get_num(obj_A);
    return 0;
}