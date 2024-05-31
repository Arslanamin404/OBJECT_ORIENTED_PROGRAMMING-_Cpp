/*
! ---------------------------------
!|   Employee Management System    |
! ---------------------------------

*Define a base class Employee with:
    Protected member variables name and employeeID.
    A public constructor to initialize name and employeeID.
    A public member function displayInfo() that prints the employee's name and ID.

*Define a derived class Manager that:
    Inherits from Employee.
    Has a private member variable department.
    Provides a constructor to initialize name, employeeID, and department.
*/
#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
    string emp_id, name;

public:
    Employee(string emp_id, string name) : emp_id(emp_id), name(name) {}

protected:
    void display_employee()
    {
        cout << "EMP-ID: " << this->emp_id << endl;
        cout << "EMP-NAME: " << this->name << endl;
    }
};

class Manager : public Employee
{
    string department;

public:
    // parameterized constructor
    Manager(string emp_id, string name, string department) : Employee(emp_id, name), department(department) {}

    // constructor will be called if we want to make already created employee to manager
    Manager(Employee &emp, string department) : Employee(emp), department(department) {}

    void display_info()
    {
        this->display_employee();
        cout << "DEPARTMENT: " << this->department << endl;
        cout << "------------------------------------------" << endl;
    }
};

int main()
{
    Employee emp1("M001", "Alice Johnson");
    Employee emp2("M002", "Bob Smith");

    Manager manager1(emp1, "Human Resources");
    Manager manager2(emp2, "Finance");
    Manager manager3("M003", "Charlie Brown", "Marketing");
    Manager manager4("M004", "Diane Clark", "IT");
    Manager manager5("M005", "Evan Davis", "Operations");
    Manager manager6("M006", "Fiona Adams", "Sales");
    Manager manager7("M007", "George Miller", "Customer Support");
    Manager manager8("M008", "Hannah Wilson", "Research and Development");

    manager1.display_info();
    manager2.display_info();
    manager3.display_info();
    manager4.display_info();
    manager5.display_info();
    manager6.display_info();
    manager7.display_info();
    manager8.display_info();
    
    return 0;
}