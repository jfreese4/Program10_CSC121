/*

Program10_q3

Programmer: Freese, Joshua

Course: CSC119-142 Introduction to Programming Spring 2022

Submission Date: 4/28/22

This program reads a file, takes it's value per line, adds them up, then outputs it.

*/

#include <iostream>
#include <fstream>

using namespace std;

void outputSum(int sum)
{
    cout << "The sum of your numbers is " << sum;
}

int main()
{
    int numSum = 0;
    ifstream inFile;
    inFile.open("numbers.txt");     // Opens the file through the operator "inFile"

    if (inFile.fail())      // If the file fails to open, the program will exit out with an error message of 1
    {
        cout << "Error opening file." << endl;
        exit(1);
    }

    while (!inFile.eof())
    {
        int tempNum;
        inFile >> tempNum;
        numSum += tempNum;
    }

    outputSum(numSum);

    inFile.close();
    return(0);
}
