#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "inputMultutudes.h"
#include "mainMultitudeFunctions.h"
#include "secondaryMultitudeFunctions.h"
using namespace std;

bool mainMenu(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[])
{

    cout << endl;
label:
    cout << endl;
    cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
    cout << "|                                                                 |" << endl;
    cout << "| 1. Intersection of two multitudes                               |" << endl;
    cout << "| 2. Union of two multitudes                                      |" << endl;
    cout << "| 3. Symetrical difference between two multitudes                 |" << endl;
    cout << "| 4. Show if multitude A is a submultitude B                      |" << endl;
    cout << "| 5. Show if multitude A is equal to multitude B                  |" << endl;
    cout << "| 6. Show if multitude A has something in common with multitude B |" << endl;
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
        findIntersection(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 2:
        findUnion(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 3:
        symetricalDifference(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 4:
        isASubMultitude(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 5:
        showIsItEqual(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 6:
        haveSomethingInCommon(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
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
    int sizeOfMultitudeA, sizeOfMultitudeB, * multitudeA, * multitudeB;
    bool exit = true;
    greeting();
    sizeOfMultitudeA = inputSize();
    multitudeA = new int[sizeOfMultitudeA];
    inputMultitudeElements(multitudeA, sizeOfMultitudeA);
    cout << endl;
    sizeOfMultitudeB = inputSize();
    multitudeB = new int[sizeOfMultitudeB];
    inputMultitudeElements(multitudeB, sizeOfMultitudeB);
    do
    {
        exit = mainMenu(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
    } while (exit != false);
    delete[]multitudeA; //delete the memory of multitudeA
    delete[]multitudeB; //delete the memory of multitudeB
}