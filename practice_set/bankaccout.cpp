/*
Bank Account
Create a simple C++ program that simulates a bank account.
Define a BankAccount class with member variables like accountNumber, balance, and ownerName.
Implement member functions to deposit, withdraw, and display account details.
*/
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class BankAccount
{
private:
    int account_number;
    string name;
    int balance;

public:
    BankAccount(int &account_number, string &name, int &balance);
    int get_account_number();
    void deposit(int &amount);
    void withdraw(int &amount);
    void display_account_details();
};

void menu();

int main()
{
    // vector of bank accounts
    vector<BankAccount> account;

    int choice;
    int account_num;
    int balance;
    string name;
    do
    {
        system("cls");
        menu();
        cout << "\nPlease enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Account Number: ";
            cin >> account_num;

            cin.ignore();
            cout << "Enter Owner Name: ";
            getline(cin, name);

            cout << "Enter initial balance: ";
            cin >> balance;

            account.push_back(BankAccount(account_num, name, balance));
            cout << "\n\tAccount created successfully!\n"
                 << endl;
            cout << "\n\nPress Enter Key To Continue. . .";
            getch();
            break;

        case 2:
            cout << "\nEnter Account Number: ";
            cin >> account_num;

            for (auto &acc : account)
            {
                if (account_num == acc.get_account_number())
                {
                    cout << "Enter amount to deposit: ";
                    cin >> balance;
                    acc.deposit(balance);
                    break;
                }
                else
                {
                    cout << "Invalid Account Number" << endl;
                    break;
                }
            }
            cout << "\n\nPress Enter Key To Continue. . .";
            getch();
            break;
        case 3:
            cout << "\nEnter Account Number: ";
            cin >> account_num;

            for (auto &acc : account)
            {
                if (account_num == acc.get_account_number())
                {
                    cout << "Enter amount to withdraw: ";
                    cin >> balance;
                    acc.withdraw(balance);
                    break;
                }
                else
                {
                    cout << "Invalid Account Number" << endl;
                    break;
                }
            }
            cout << "\n\nPress Enter Key To Continue. . .";
            getch();
            break;
        case 4:
            cout << "\nEnter Account Number: ";
            cin >> account_num;

            for (auto &acc : account)
            {
                if (account_num == acc.get_account_number())
                {
                    acc.display_account_details();
                    break;
                }
                else
                {
                    cout << "Invalid Account Number" << endl;
                    break;
                }
            }
            cout << "\n\nPress Enter Key To Continue. . .";
            getch();
            break;
        case 5:
            cout << "\nThank you for using our bank!\n";
            getch();
            break;
        default:
            cout << "\nInvalid choice. Please enter a valid option.\n"
                 << endl;
            cout << "\n\nPress Enter Key To Continue. . .";
            getch();
        }
    } while (choice != 5);

    return 0;
}

BankAccount::BankAccount(int &account_number, string &name, int &balance)
{
    this->account_number = account_number;
    this->name = name;
    this->balance = balance;
}

int BankAccount::get_account_number()
{
    return this->account_number;
}

void BankAccount::deposit(int &amount)
{
    this->balance += amount;
    cout << "Deposit of $" << amount << " successful!" << endl;
}

void BankAccount::withdraw(int &amount)
{
    if (this->balance > amount)
    {
        this->balance -= amount;
        cout << "Withdrawal of $" << amount << " successful!" << endl;
    }
    else
    {
        cout << "Insufficient Funds!" << endl;
    }
}

void BankAccount::display_account_details()
{
    cout << "Owner Name: " << this->name << endl;
    cout << "Account Number: " << this->account_number << endl;
    cout << "Balance: " << this->balance << endl;
}

void menu()
{
    cout << "\t\t\tWelcome to the Bank!" << endl;
    cout << "\n1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Display Account Details" << endl;
    cout << "5. Exit" << endl;
}
