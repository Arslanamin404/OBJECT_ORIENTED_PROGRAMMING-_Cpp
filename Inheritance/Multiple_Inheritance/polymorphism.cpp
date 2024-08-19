#include <iostream>
#include <string>

using namespace std;

/*
MULTIPLE INHERITANCE --> DERIVED CLASS INHERITS FROM MORE THAN ONE BASE CLASS
Their arises a problem known as DIAMOND PROBLEM and to resolve that problem we need to use virtual class.
If we dont use virtual inheritance class,then we will get 2 instances/copies of base class members in the derived class
which results in ambiguity. To resolve this issue we use virtual inheritance in order to ensure that their is single
instance/copy in derived class of base class.
*/


// Base Class
class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void display()
    {
        cout << "NAME: " << this->name << endl;
        cout << "AGE: " << this->age << endl;
    }
};

// if we dont use virtual inheritance it will lead to Ambiguity, as 2 copies of base class will be received in further derived class
class Student : virtual public Person
{
protected:
    string student_id;

public:
    Student(string name, int age, string std_id) : Person(name, age), student_id(std_id) {}

    void display() override
    {
        cout << "STUDENT" << endl;
        cout << "---------" << endl;
        cout << "NAME: " << this->name << endl;
        cout << "AGE: " << this->age << endl;
        cout << "Student ID: " << this->student_id << endl;
    }
};

// Derived Class from 1 base class
class Employee : virtual public Person
{
protected:
    string employee_id;
    int salary;

public:
    Employee(string name, int age, string emp_id, int salary) : Person(name, age), employee_id(emp_id), salary(salary) {}

    void display() override
    {
        cout << "EMPLOYEE" << endl;
        cout << "----------" << endl;
        cout << "NAME: " << this->name << endl;
        cout << "AGE: " << this->age << endl;
        cout << "Employee ID: " << this->employee_id << endl;
        cout << "SALARY: " << this->salary << endl;
    }
};

// Derived Class from base classes
class WorkingStudent : public Student, public Employee
{
public:
    WorkingStudent(string name, int age, string std_id, string emp_id, int salary) : Person(name, age), Student(name, age, std_id), Employee(name, age, emp_id, salary) {}
    void display() override
    {
        cout << "WORKING STUDENT" << endl;
        cout << "-----------------" << endl;
        cout << "NAME: " << this->name << endl;
        cout << "AGE: " << this->age << endl;
        cout << "Student ID: " << this->student_id << endl;
        cout << "Employee ID: " << this->employee_id << endl;
        cout << "SALARY: " << this->salary << endl;
    }
};

int main()
{
    Person *person_ptr;
    
    Student student_Obj("jack", 18, "Std_21");
    Employee employee_Obj("John", 39, "emp-69-69", 69000);
    WorkingStudent ws_Obj("ADMIN", 21, "std-583", "emp-404", 67000);

    /*To achieve RUN TIME POLYMORPHISM, we generally need to use pointers or references.
    By using Pointers or References to base class objects, it enables the runtime to determine the actual derived
    class type and invoke the appropriate overridden functions, thus achieving runtime POLYMORPHISM.
    Without using virtual keyword we cannot achieve POLYMORPHISM.
    */

    person_ptr = &student_Obj;
    person_ptr->display();
    cout << "-------------------------------------" << endl;

    person_ptr = &employee_Obj;
    person_ptr->display();
    cout << "-------------------------------------" << endl;

    person_ptr = &ws_Obj;
    person_ptr->display();
    cout << "-------------------------------------" << endl;

    return 0;
}
