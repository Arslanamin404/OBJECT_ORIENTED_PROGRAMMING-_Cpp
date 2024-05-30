#include <iostream>
#include <string>

using namespace std;

// Base/Parent Class
class Person
{
protected:
    string name;
    int age;

public:
    // constructor using initializer list
    Person(string name, int age) : name(name), age(age) {}

    void display_info()
    {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "-------------------------------------------------" << endl;
    }
};

// Derived/Child Class
class Student : public Person
{
private:
    string student_id;

public:
    Student(string name, int age, string student_id) : Person(name, age), student_id(student_id){};

    Student(Person &person, string student_id) : Person(person), student_id(student_id){};
    void display_student()
    {
        cout << "Student ID: " << this->student_id << endl;
        this->display_info();
    }
};

int main()
{
    Person p1("ADMIN", 69);
    Student std1(p1, "STD-404-ADMIN");

    Student std2("Mohammad Arsalan Rather", 21, "STD-69-Arsu");
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "PERSON 1: " << endl;
    p1.display_info();

    cout << "STUDENT 1: " << endl;
    std1.display_student();

    cout << "STUDENT 2: " << endl;
    std2.display_student();

    return 0;
}