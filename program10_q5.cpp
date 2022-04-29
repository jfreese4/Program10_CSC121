/*

Program10_q4

Programmer: Freese, Joshua

Course: CSC119-142 Introduction to Programming Spring 2022

Submission Date: 4/28/22

This program finds the largest number in a file
*/

#include <iostream>
#include <fstream>

using namespace std;

void outputSum(int largestNum)
{
    cout << "The largest of your numbers is " << largestNum;
}

int main()
{
    int largestNum = 0;
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
        if(tempNum > largestNum)
        {
            largestNum = tempNum;
        }
    }

    outputSum(largestNum);

    inFile.close();
    return(0);
}
