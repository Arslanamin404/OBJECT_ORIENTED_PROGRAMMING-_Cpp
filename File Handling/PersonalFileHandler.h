#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// class to handle basic FILE IO
class FileHandler
{
private:
    string file_name; // var for file name to be handled

public:
    FileHandler(const string name) : file_name(name) {}

    // function to write data to the file
    void writeData(const string &content);

    // function to append data to the file
    void appendData(const string &content);

    // function to read data from the file
    void readData();

    // function to copy data from one file to another
    void fileCopy(const string &source_file_name, const string &destination_file_name);
};

// function to write data to the file
void FileHandler::writeData(const string &content)
{
    ofstream file(file_name, ios::out);

    if (!file)
    {
        cerr << "Error opening file for writing" << endl;
        return;
    }
    file << content << endl;
    file.close();
}

// function to append data to the file
void FileHandler::appendData(const string &content)
{
    ofstream file(file_name, ios::app);
    if (!file)
    {
        cerr << "Error opening file for appending" << endl;
        return;
    }
    file << content << endl;
    file.close();
}

// function to read data from the file
void FileHandler::readData()
{
    ifstream file(file_name, ios::in);
    if (!file)
    {
        cerr << "Error opening file for reading" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

// function to read data from the file
void FileHandler::fileCopy(const string &source_file_name, const string &destination_file_name)
{
    ifstream source_file(source_file_name, ios::in);
    if (!source_file)
    {
        cerr << "Error opening source file!" << endl;
        return;
    }
    ofstream destination_file(destination_file_name, ios::out);
    if (!destination_file)
    {
        cerr << "Error opening destination file!" << endl;
        return;
    }

    string line;
    while (getline(source_file, line))
    {
        destination_file << line << endl;
    }

    source_file.close();
    destination_file.close();
}
#endif