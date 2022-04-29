/*

Program10_q6.2

Programmer: Freese, Joshua

Course: CSC119-142 Introduction to Programming Spring 2022

Submission Date: 4/28/22

This program reads each line of a document and outputs it.
*/

#include <iostream>
#include <fstream>

using namespace std;

void output(string data)
{
    cout << data << endl;;
}

int main()
{
    string data;
    ifstream inFile;
    inFile.open("golf.txt");

    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }

    while (!inFile.eof())
    {
        getline(inFile, data);
        output(data);
    }

    inFile.close();
    return(0);
}
