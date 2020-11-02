#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "inputSets.h"
#include "mainSetFunctions.h"
#include "secondarySetFunctions.h"
using namespace std;

bool mainMenu(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[])
{

    cout << endl;
label:
    cout << endl;
    cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
    cout << "|                                                                 |" << endl;
    cout << "| 1. Intersection of two sets                                     |" << endl;
    cout << "| 2. Union of two sets                                            |" << endl;
    cout << "| 3. Subtraction of two sets                                      |" << endl;
    cout << "| 4. Symetrical difference between two sets                       |" << endl;
    cout << "| 5. Show if set A is a subset B                                  |" << endl;
    cout << "| 6. Show if set A is equal to set B                              |" << endl;
    cout << "| 7. Show if set A has something in common with set B             |" << endl;
    cout << "| 0. EXIT                                                         |" << endl;
    cout << "|                                                                 |" << endl;
    cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
    cout << endl;
    int option;
    cout << "Please enter the option you'd like to use: ";
    cin >> option;
    cout << endl;

    switch (option)
    {
    case 1:
        findIntersection(sizeOfSetA, sizeOfSetB, setA, setB);
        return true;
        break;
    case 2:
        findUnion(sizeOfSetA, sizeOfSetB, setA, setB);
        return true;
        break;
    case 3:
        findDifferenceOfSetA(sizeOfSetA, sizeOfSetB, setA, setB);
        findDifferenceOfSetB(sizeOfSetA, sizeOfSetB, setA, setB);
        return true;
        break;
    case 4:
        symetricalDifference(sizeOfSetA, sizeOfSetB, setA, setB);
        return true;
        break;
    case 5:
        isASubSet(sizeOfSetA, sizeOfSetB, setA, setB);
        return true;
        break;
    case 6:
        showIsItEqual(sizeOfSetA, sizeOfSetB, setA, setB);
        return true;
        break;
    case 7:
        haveSomethingInCommon(sizeOfSetA, sizeOfSetB, setA, setB);
        return true;
        break;
    case 0:
        return false;
        break;
    default:
        cout << "Incorrect input try again" << endl;
        goto label; //return back to the start of the function
    }
}

int main()
{
    int sizeOfSetA, sizeOfSetB, * setA, * setB;
    bool exit = true;
    greeting();
    sizeOfSetA = inputSize();
    setA = new int[sizeOfSetA];
    inputSetElements(setA, sizeOfSetA);
    cout << endl;
    sizeOfSetB = inputSize();
    setB = new int[sizeOfSetB];
    inputSetElements(setB, sizeOfSetB);
    do
    {
        exit = mainMenu(sizeOfSetA, sizeOfSetB, setA, setB);
    } while (exit != false);
    delete[]setA; //delete the memory of setA
    delete[]setB; //delete the memory of setB
}