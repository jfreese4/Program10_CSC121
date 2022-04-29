/*

Program10_q4

Programmer: Freese, Joshua

Course: CSC119-142 Introduction to Programming Spring 2022

Submission Date: 4/28/22

This program reads a file, takes it's value per line, sums them up, then outputs the average.

*/

#include <iostream>
#include <fstream>

using namespace std;

void outputSum(float sum, float numNums)
{
    cout << "The average of your numbers is " << sum/numNums;
}

int main()
{
    int numSum = 0;
    int numNums = 0;
    ifstream inFile;
    inFile.open("numbers.txt");

    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }

    while (!inFile.eof())
    {
        int tempNum;
        inFile >> tempNum;
        numSum += tempNum;
        numNums++;
    }

    outputSum(numSum, numNums);

    inFile.close();
    return(0);
}
