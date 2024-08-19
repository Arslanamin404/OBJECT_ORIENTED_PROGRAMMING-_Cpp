/*
! |------------------------------|
! |   Educational Institution    |
! |------------------------------|

TODO: Create a class hierarchy for an educational institution.

*Person Class:
    Attributes: name (string), age (int)
    Methods: Constructor, method to display name and age
*Student Class (inherits from Person):
    Attributes: studentID (string), major (string)
    Methods: Constructor, method to display student details (including base class attributes)
*GraduateStudent Class (inherits from Student):
    Attributes: researchTopic (string), advisor (string)
    Methods: Constructor, method to display graduate student details (including base class attributes)
*/

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>

using namespace std;

// Base class Person
class Person
{
protected:
    string name;
    int age;

public:
    // Constructor to initialize name and age
    Person(string name, int age) : name(name), age(age) {}

    // Method to display person details
    void display_person() const
    {
        cout << "NAME: " << name << endl;
        cout << "AGE: " << age << endl;
    }
};

// Derived class Student from Person
class Student : public Person
{
protected:
    string student_id;
    string major;

public:
    // Constructor to initialize name, age, student_id, and major
    Student(string name, int age, string student_id, string major) : Person(name, age), student_id(student_id), major(major) {}

    // Method to display student details including person details
    void display_student() const
    {
        display_person();
        cout << "Student ID: " << student_id << endl;
        cout << "MAJOR: " << major << endl;
    }
};

// Derived class GraduateStudent from Student
class GraduateStudent : public Student
{
private:
    string researchTopic;
    string advisor;

public:
    // Constructor to initialize name, age, student_id, major, research topic, and advisor
    GraduateStudent(string name, int age, string student_id, string major, string research_topic, string advisor) : Student(name, age, student_id, major), researchTopic(research_topic), advisor(advisor) {}

    // Method to display graduate student details including student details
    void display_graduate() const
    {
        display_student();
        cout << "Research Topic: " << researchTopic << endl;
        cout << "ADVISOR: " << advisor << endl;
        cout << "-------------------------------------------------" << endl;
    }
};

// Function declarations/prototypes
void menu();
void display_menu();
void createPerson(vector<Person> &people);
void createStudent(vector<Student> &students);
void createGraduateStudent(vector<GraduateStudent> &gradStudents);
void displayPeople(const vector<Person> &people);
void displayStudents(const vector<Student> &students);
void displayGraduateStudents(const vector<GraduateStudent> &gradStudents);

int main()
{
    int choice;
    int display_menu_choice;

    // Vectors to store person, student, and graduate student objects
    vector<Person> person;
    vector<Student> students;
    vector<GraduateStudent> graduate_students;

    do
    {
        system("cls");
        menu();
        cout << "\nEnter your choice[1/2/3/4/99]: ";
        cin >> choice;
        cin.ignore();
        cout << endl;
        switch (choice)
        {
        case 1:
            createPerson(person);
            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 2:
            createStudent(students);
            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 3:
            createGraduateStudent(graduate_students);
            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 4:
            display_menu();
            cout << "\nEnter your choice[11/22/33/44]: ";
            cin >> display_menu_choice;
            cout << endl;
            switch (display_menu_choice)
            {
            case 11:
                displayPeople(person);
                cout << "\nPRESS ANY KEY TO CONTINUE. . .";
                getch();
                break;
            case 22:
                displayStudents(students);
                cout << "\nPRESS ANY KEY TO CONTINUE. . .";
                getch();
                break;
            case 33:
                displayGraduateStudents(graduate_students);
                cout << "\nPRESS ANY KEY TO CONTINUE. . .";
                getch();
                break;
            case 44:
                cout << "\n\tReturning to MAIN MENU...";
                // getch();
                break;
            default:
                cout << "\n\n\tINVALID CHOICE...!";
                getch();
            }
            break;

        case 99:
            cout << "Exiting program..." << endl;
            getch();
            break;

        default:
            cout << "\n\tINVALID CHOICE...!";
            getch();
        }
    } while (choice != 99);

    return 0;
}

// Function to display the main menu
void menu()
{
    cout << setw(100) << "WELCOME TO THIS EDUCATIONAL INSTITUTION SOFTWARE\n"
         << endl;
    cout << setw(50) << "|--------------------------|" << endl;
    cout << setw(23) << "|" << setw(18) << "MAIN MENU" << setw(9) << "|" << endl;
    cout << setw(50) << "|--------------------------|" << endl
         << endl;

    cout << "\nPlease Select an Action -->\n"
         << endl;
    cout << setw(20) << "- Create a Person" << setw(16) << "[1]" << endl;
    cout << setw(21) << "- Create a Student" << setw(15) << "[2]" << endl;
    cout << setw(30) << "- Create a Graduate Student" << setw(6) << "[3]" << endl;
    cout << setw(20) << "- Display Details" << setw(16) << "[4]" << endl;
    cout << setw(9) << "- EXIT" << setw(27) << "[99]" << endl;
}

// Function to display the sub-menu for displaying details
void display_menu()
{
    system("cls");
    cout << setw(100) << "WELCOME TO THIS EDUCATIONAL INSTITUTION SOFTWARE\n"
         << endl;
    cout << setw(50) << "|--------------------------|" << endl;
    cout << setw(23) << "|" << setw(18) << "DISPLAY MENU" << setw(9) << "|" << endl;
    cout << setw(50) << "|--------------------------|" << endl
         << endl;

    cout << "\nPlease Select an Action -->\n"
         << endl;
    cout << setw(20) << "- DISPLAY Person" << setw(19) << "[11]" << endl;
    cout << setw(22) << "- DISPLAY Students" << setw(17) << "[22]" << endl;
    cout << setw(31) << "- DISPLAY Graduate Students" << setw(8) << "[33]" << endl;
    cout << setw(25) << "- RETURN TO MAIN MENU" << setw(14) << "[44]" << endl;
}

// Function to create a Person and add to the vector
void createPerson(vector<Person> &people)
{
    string name;
    int age;
    cout << "FULL NAME: ";
    getline(cin, name);
    cout << "AGE: ";
    cin >> age;
    cin.ignore();
    people.push_back(Person(name, age));
    cout << endl;
    cout << setw(55) << "|-------------------------------------------|" << endl;
    cout << setw(11) << "|" << setw(36) << "PERSON CREATED SUCCESSFULLY!" << setw(8) << "|" << endl;
    cout << setw(55) << "|-------------------------------------------|" << endl;
}

// Function to create a Student and add to the vector
void createStudent(vector<Student> &students)
{
    string name, student_id, major;
    int age;
    cout << "FULL NAME: ";
    getline(cin, name);
    cout << "AGE: ";
    cin >> age;
    cin.ignore();
    cout << "STUDENT ID: ";
    getline(cin, student_id);
    cout << "Major: ";
    getline(cin, major);
    students.push_back(Student(name, age, student_id, major));
    cout << endl;
    cout << setw(55) << "|-------------------------------------------|" << endl;
    cout << setw(11) << "|" << setw(36) << "STUDENT CREATED SUCCESSFULLY!" << setw(8) << "|" << endl;
    cout << setw(55) << "|-------------------------------------------|" << endl;
}

// Function to create a Graduate Student and add to the vector
void createGraduateStudent(vector<GraduateStudent> &gradStudents)
{
    string name, student_id, major, research_topic, advisor;
    int age;
    cout << "FULL NAME: ";
    getline(cin, name);
    cout << "AGE: ";
    cin >> age;
    cin.ignore();
    cout << "STUDENT ID: ";
    getline(cin, student_id);
    cout << "Major: ";
    getline(cin, major);
    cout << "Enter research topic: ";
    getline(cin, research_topic);
    cout << "Enter advisor: ";
    getline(cin, advisor);
    gradStudents.push_back(GraduateStudent(name, age, student_id, major, research_topic, advisor));
    cout << endl;
    cout << setw(55) << "|--------------------------------------------------|" << endl;
    cout << setw(4) << "|" << setw(45) << "GRADUATE STUDENT CREATED SUCCESSFULLY!" << setw(6) << "|" << endl;
    cout << setw(55) << "|--------------------------------------------------|" << endl;
}

// Function to display all Persons in the vector
void displayPeople(const vector<Person> &people)
{
    cout << endl;
    cout << setw(40) << "|-----------------------------|" << endl;
    cout << setw(10) << "|" << setw(25) << "LIST OF ALL PEOPLE" << setw(5) << "|" << endl;
    cout << setw(40) << "|-----------------------------|" << endl
         << endl;
    if (people.empty())
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        for (const auto &p : people)
        {
            p.display_person();
            cout << endl;
        }
    }
}

// Function to display all students in the vector
void displayStudents(const vector<Student> &students)
{
    cout << endl;
    cout << setw(40) << "|-----------------------------|" << endl;
    cout << setw(10) << "|" << setw(25) << "LIST OF ALL STUDENTS" << setw(5) << "|" << endl;
    cout << setw(40) << "|-----------------------------|" << endl
         << endl;
    if (students.empty())
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        for (const auto &s : students)
        {
            s.display_student();
            cout << endl;
        }
    }
}

// Function to display all Graduate Students in the vector
void displayGraduateStudents(const vector<GraduateStudent> &gradStudents)
{
    cout << endl;
    cout << setw(60) << "|--------------------------------------------------|" << endl;
    cout << setw(9) << "|" << setw(40) << "LIST OF ALL GRADUATE STUDENTS" << setw(11) << "|" << endl;
    cout << setw(60) << "|--------------------------------------------------|" << endl
         << endl;
    if (gradStudents.empty())
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        for (const auto &gs : gradStudents)
        {
            gs.display_graduate();
            cout << endl;
        }
    }
}