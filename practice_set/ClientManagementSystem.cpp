/*
|-----------------------------------------------------------------------|
|            Client Management system for a small business              |
|-----------------------------------------------------------------------|

!Add the following methods:


* 1. Adding new clients
        ?( Name, Email, Phone, Address)
* 2. Searching for clients
* 3. Updating client details
        ?Prompt User to enter client_id.
        ?Display sub menu to ask user what exactly he wants to update (Name, Email, Phone, Address).
* 4. Deleting clients
* 5.  Displaying all clients
* 6.  Exit
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Client
{
    string name;
    string email;
    string phone;
    string address;

public:
    Client(string name, string email, string phone, string address);
};

int main()
{

    return 0;
}

Client::Client(string name, string email, string phone, string address)
{
    this->name = name;
    this->email = email;
    this->phone = phone;
    this->address = address;
}
