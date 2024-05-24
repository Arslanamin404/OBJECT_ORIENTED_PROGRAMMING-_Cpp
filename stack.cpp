#include <iostream>
#include <conio.h>

#define MAX_SIZE 100
using namespace std;

class Stack
{
private:
    int top;           // Index of the top element
    int arr[MAX_SIZE]; // Array to store stack elements

public:
    Stack()
    {
        top = -1; // Initialize top to -1 indicating the stack is empty
    }

    bool push(int value); // Method to push an element onto the stack
    int pop();            // Method to pop an element from the stack
    int peek();           // Method to get the top element of the stack
    bool is_empty();      // Method to check if the stack is empty
    bool is_full();       // Method to check if the stack is full
    int size();           // Method to get the current size of the stack
    void display();       // Method to display the elements in the stack
};

void menu()
{
    cout << "\t\t\tWELCOME TO MY STACK\n"
         << endl;
    cout << "Please select an action --->\n"
         << endl;
    cout << "1. PUSH\t\t[1]" << endl;
    cout << "2. POP\t\t[2]" << endl;
    cout << "3. PEEK\t\t[3]" << endl;
    cout << "4. SIZE\t\t[4]" << endl;
    cout << "5. DISPLAY\t[5]" << endl;
    cout << "6. EXIT\t\t[6]" << endl;
}

int main()
{
    system("cls");
    Stack stack;

    int choice;
    do
    {
        system("cls");
        menu();
        cout << "\nENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "\nELEMENT TO PUSH: ";
            cin >> value;
            stack.push(value);
            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 2:
            int popped_element;
            popped_element = stack.pop();
            if (popped_element != -1)
            {
                cout << endl
                     << popped_element << " POOPED FROM THE STACK" << endl;
            }
            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 3:
            if (stack.peek() != -1)
            {
                cout << "\nPEAK: " << stack.peek() << endl;
            }

            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 4:
            cout << "\nSIZE: " << stack.size() << endl;
            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 5:
            cout << "\nELEMENTS IN STACK: " << endl;
            stack.display();
            cout << "\nPRESS ANY KEY TO CONTINUE. . .";
            getch();
            break;
        case 6:
            cout << "\n\tEXITING. . .";
            getch();
            break;

        default:
            cout << "PLEASE ENTER A VALID CHOICE. . .";
            getch();
        }
    } while (choice != 6);

    return 0;
}

bool Stack::push(int value)
{
    if (this->is_full())
    {
        cout << "\nSTACK OVERFLOW" << endl;
        return false;
    }
    else
    {
        this->arr[++top] = value;
        cout << endl
             << value << " pushed to the STACK!" << endl;
        return true;
    }
}

int Stack::pop()
{
    if (this->is_empty())
    {
        cout << "\nSTACK UNDERFLOW" << endl;
        return -1;
    }
    else
    {
        int popped_element = this->arr[top--];
        return popped_element;
    }
}

int Stack::peek()
{
    if (this->is_empty())
    {
        cout << "STACK UNDERFLOW" << endl;
        return -1;
    }
    else
    {
        return this->arr[top];
    }
}

bool Stack::is_empty()
{
    return (this->top < 0);
}

bool Stack::is_full()
{
    return (this->top >= MAX_SIZE - 1);
}

int Stack::size()
{
    return top + 1;
}

void Stack::display()
{
    if (this->is_empty())
        cout << "\nSTACK UNDERFLOW" << endl;
    else
    {
        for (int i = this->top; i >= 0; i--)
            cout << this->arr[i] << endl;
    }
}
