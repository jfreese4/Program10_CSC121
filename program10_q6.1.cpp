/*

Program10_q6.1

Programmer: Freese, Joshua

Course: CSC119-142 Introduction to Programming Spring 2022

Submission Date: 4/28/22

This program gets the amount of entries needed, gets input for each entry, and outputs the data into a file 'golf.txt'
*/

#include <iostream>
#include <fstream>

using namespace std;

void toFile(int entries)
{
    string name;
    int score;
    ofstream outFile;
    outFile.open("golf.txt");

    for (int counter = 1; counter <= entries; counter++)
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        outFile << name << "\t\t\t" << score << endl;
    }

    outFile.close();
}

int main()
{
    int numEntries;
    ofstream inFile;
    inFile.open("golf.txt");

    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }

    cout << "How many entries do you have? ";
    cin >> numEntries;

    toFile(numEntries);

    inFile.close();
    return(0);
}
