/*
Student Information:
Write a C++ program that defines a Student class with member variables like name, rollNumber, marks, etc.
Implement member functions to input and display student details.
*/
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

class Student
{
private:
    string name;
    int roll_number;
    float marks;

public:
    // Constructor
    Student(string &name, int &roll_number, float &marks);
    static void menu();
    void displayInfo();
    void updateStudent(string &name, int &roll_number, float &marks);
    void search_student();
    int get_rollNumber()
    {
        return this->roll_number;
    }
};

int main()
{
    vector<Student> StudentRecord;
    int choice;
    string name;
    int roll_number;
    float marks;
    do
    {
        Student::menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Roll Number: ";
            cin >> roll_number;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Marks: ";
            cin >> marks;

            StudentRecord.push_back(Student(name, roll_number, marks));
            cout << "\n\t\tSTUDENT ADDED SUCCESSFULLY!" << endl;
            cout << "\nPress Enter to continue. . . .";
            getch();

            break;
        }
        case 2:
            if (StudentRecord.empty())
            {
                cout << "\nApologies, there are no student details to update at the moment.\nPlease add student information before attempting to update.\nThank You!" << endl;
            }
            else
            {
                cout << "Roll Number of Student To Update: ";
                cin >> roll_number;

                for (auto &std : StudentRecord)
                {
                    if (roll_number == std.get_rollNumber())
                    {
                        cout << "Enter New Roll Number: ";
                        cin >> roll_number;
                        cin.ignore();
                        cout << "Name: ";
                        getline(cin, name);
                        cout << "Marks: ";
                        cin >> marks;

                        std.updateStudent(name, roll_number, marks);
                        cout << "\n\t\tSTUDENT Updated SUCCESSFULLY!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Roll Number does not exist" << endl;
                        break;
                    }
                }
            }
            cout << "\nPress Enter to continue. . . .";
            getch();
            break;
        case 3:
            if (StudentRecord.empty())
            {
                cout << "\nThe student list is currently empty.\nPlease add student details before attempting to search.\nThank You!" << endl;
            }
            else
            {
                cout << "Roll Number To Search: ";
                cin >> roll_number;

                for (auto &std : StudentRecord)
                {
                    if (roll_number == std.get_rollNumber())
                    {
                        std.search_student();
                        break;
                    }
                    else
                    {
                        cout << "\nRoll Number does not exist" << endl;
                        break;
                    }
                }
            }
            cout << "\nPress Enter to continue. . . .";
            getch();
            break;
        case 4:
        {
            if (StudentRecord.empty())
            {
                cout << "\nThe student list is currently empty.\nPlease add student details to populate the list.\nThank You!" << endl;
            }
            else
            {
                cout << "\n\t\tALL STUDENTS RECORD: \t\t" << endl;
                for (auto &student : StudentRecord)
                {
                    student.displayInfo();
                }
            }
            cout << "\nPress Enter to continue. . . .";
            getch();
            break;
        }
        case 5:
        {
            cout << "\n\t\tExiting. . . ";
            getch();
            break;
        }
        default:
            cout << "Invalid Choice! Please input a valid choice [1/2/3/4]" << endl;
            getch();
        }

    } while (choice != 5);

    return 0;
}

Student::Student(string &name, int &roll_number, float &marks)
{
    this->name = name;
    this->roll_number = roll_number;
    this->marks = marks;
}

void Student::menu()
{
    system("cls");
    cout << "\n\t\t\t Welcome to Student Management System \t" << endl;
    cout << "\n1. Add new student record\n";
    cout << "2. Update Student\n";
    cout << "3. Search Student\n";
    cout << "4. Display all student records\n";
    cout << "5. Exit\n"
         << endl;
}
void Student::displayInfo()
{
    cout << "\n----------------------------------" << endl;
    cout << "Roll Number: " << this->roll_number << endl;
    cout << "Name: " << this->name << endl;
    cout << "Marks: " << this->marks << endl;
}

void Student::updateStudent(string &name, int &roll_number, float &marks)
{
    this->name = name;
    this->roll_number = roll_number;
    this->marks = marks;
}

void Student::search_student()
{
    this->displayInfo();
}
