#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void greeting()
{
    cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_* Welcome to our program! *_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
    cout << endl;
}
int inputSize()
{
    int sizeOfMultitude;

    cout << "Enter the size of the multitude: ";

    cin >> sizeOfMultitude;

    cout << endl;


    return sizeOfMultitude;
}

void inputMultitudeElements(int multitude[], int sizeOfMultitude)
{
    cout << "Enter the elements of multitude: ";
    for (int i = 0; i < sizeOfMultitude; i++)
    {
        cin >> multitude[i];
    }
}

void findIntersection(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    cout << endl;
    cout << "The intersection/s is/are: ";
    int areThereAnyIntersectionsInMultitudeA = 0;
    int areThereAnyIntersectionsInMultitudeB = 0;
    int* indexOfTheIntersectionA;
    int* indexOfTheIntersectionB;
    int intersectionNumber = 0;

    for (int i = 0; i < sizeOfMultitudeA; i++)
    {
        for (int j = 0; j < sizeOfMultitudeB; j++)
        {
            if (multitudeA[i] == multitudeB[j])
            {
                cout << multitudeA[i] << " ";
                areThereAnyIntersectionsInMultitudeA++;
                areThereAnyIntersectionsInMultitudeB++;
            }
        }
    }
    if (areThereAnyIntersectionsInMultitudeA == 0)
    {
        cout << "There are no intersections";
    }
    else
    {
        indexOfTheIntersectionA = new int[areThereAnyIntersectionsInMultitudeA];
        indexOfTheIntersectionB = new int[areThereAnyIntersectionsInMultitudeB];
        for (int i = 0; i < sizeOfMultitudeA; i++)
        {
            for (int j = 0; j < sizeOfMultitudeB; j++)
            {
                if (multitudeA[i] == multitudeB[j])
                {
                    indexOfTheIntersectionA[intersectionNumber] = i + 1;
                    indexOfTheIntersectionB[intersectionNumber] = j + 1;
                    intersectionNumber++;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < intersectionNumber; i++)
        {
            cout << endl;
            cout << "The sectoins are found on position " << indexOfTheIntersectionA[i] << " from multitude A" << endl;
            cout << "The sectoins are found on position " << indexOfTheIntersectionB[i] << " from multitude B" << endl;
        }
    }
    cout << endl;
}



void findUnion(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    cout << endl;
    int temp, count = 0, index = 0, intersectionCount = 0;
    int* mergedArray;
    for (int i = 0; i < sizeOfMultitudeA; i++)
    {
        for (int j = 0; j < sizeOfMultitudeB; j++)
        {
            if (multitudeA[i] == multitudeB[j])
            {
                intersectionCount++;
            }
        }
    }
    mergedArray = new int[sizeOfMultitudeA + sizeOfMultitudeB - intersectionCount];
    for (int i = 0; i < sizeOfMultitudeA; i++)
    {
        for (int j = 0; j < sizeOfMultitudeB - count; j++)
        {
            if (multitudeA[i] == multitudeB[j])
            {
                temp = multitudeB[j];
                multitudeB[j] = multitudeB[sizeOfMultitudeB - 1 - count];
                multitudeB[sizeOfMultitudeB - 1 - count] = temp;
                count++;
            }
        }
        mergedArray[index++] = multitudeA[i];
    }
    for (int i = 0; i < sizeOfMultitudeB - count; i++)
    {
        mergedArray[index++] = multitudeB[i];
    }
    for (int i = 0; i < index; i++)
    {
        cout << mergedArray[i] << " ";
    }

}

void isASubMultitude(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    int isASub = 0;
    for (int i = 0; i < sizeOfMultitudeA; i++)
    {
        for (int j = 0; j < sizeOfMultitudeB; j++)
        {
            if (multitudeA[i] == multitudeB[j])
            {
                isASub++;
            }
        }
    }
    if (sizeOfMultitudeB == sizeOfMultitudeA && sizeOfMultitudeA == isASub)
    {
        cout << "The multitudes are equal";
        cout << endl;
    }
    else if (isASub == sizeOfMultitudeB)
    {
        cout << "Multitude B is a sub multitude of a multitude A";
        cout << endl;
    }
    else if (isASub == sizeOfMultitudeA)
    {
        cout << "Multitude A is a sub multitude of a multitude B";
        cout << endl;
    }
    else
    {
        cout << "There are no sub multitudes";
        cout << endl;
    }
}

void showIsItEqual(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[])
{
    int equalCheck = 0;
    for (int i = 0; i < sizeOfMultitudeA; i++)
    {
        for (int j = 0; j < sizeOfMultitudeB; j++)
        {
            if (multitudeA[i] == multitudeB[j])
            {
                equalCheck++;
            }
        }
    }
    if (equalCheck == sizeOfMultitudeA)
    {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int checkPrime(int multitudeElement) {
    if (multitudeElement <= 1)
    {
        return 0;
    }
    for (int j = 2; j <= multitudeElement / 2; j++) {
        if (multitudeElement % j == 0) {
            return 0;
        }
        return 1;
    }
}

void haveSomethingInCommon(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[])
{
    int oddNumbers = 0, evenNumbers = 0;
    int multitudeSum = 0;
    cout << "Are they the same: ";
    showIsItEqual(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
    cout << endl;
    for (int i = 0; i < sizeOfMultitudeA; i++)
    {
        if (multitudeA[i] % 2 == 0) {
            evenNumbers++;
        }
        else {
            oddNumbers++;
        }
    }
    cout << "In multitude A there are " << oddNumbers << " odd numbers and " << evenNumbers << " even numbers" << endl;
    evenNumbers = 0;
    oddNumbers = 0;
    for (int i = 0; i < sizeOfMultitudeB; i++)
    {
        if (multitudeB[i] % 2 == 0) {
            evenNumbers++;
        }
        else {
            oddNumbers++;
        }
    }
    cout << "In multitude B there are " << oddNumbers << " odd numbers and " << evenNumbers << " even numbers" << endl;
    for (int i = 0; i < sizeOfMultitudeA; i++)
    {
        multitudeSum += multitudeA[i];
    }
    cout << "The sum of all elements in multitude A is: " << multitudeSum << endl;
    multitudeSum = 0;
    for (int i = 0; i < sizeOfMultitudeB; i++)
    {
        multitudeSum += multitudeB[i];
    }
    cout << "The sum of all elements in multitude B is: " << multitudeSum << endl;
    int primeCount = 0;
    int isprime = 0;
    for (int i = 0; i < sizeOfMultitudeA; i++) {
        isprime = checkPrime(multitudeA[i]);
        if (isprime == 1)
            primeCount++;
    }
    cout << "There is/are: " << primeCount << " in multitude A" << endl;
    primeCount = 0;
    isprime = 0;
    for (int i = 0; i < sizeOfMultitudeB; i++) {
        isprime = checkPrime(multitudeB[i]);
        if (isprime == 1)
            primeCount++;
    }
    cout << "There is/are: " << primeCount << " in multitude B" << endl;
}


void symetricalDifference(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    vector<int> sDifference(100);
    vector<int>::iterator sDCount;
    sort(multitudeA, multitudeA + sizeOfMultitudeA);
    sort(multitudeB, multitudeB + sizeOfMultitudeB);
    sDCount = set_symmetric_difference(multitudeA, multitudeA + sizeOfMultitudeA, multitudeB, multitudeB + sizeOfMultitudeB, sDifference.begin());
    sDifference.resize(sDCount - sDifference.begin());
    for (sDCount = sDifference.begin(); sDCount != sDifference.end(); sDCount++)
    {
        cout <<*sDCount <<" ";
    }
}

bool mainMenu(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[])
{


    cout << endl;
    label:
    cout << endl;
    cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" <<endl;
    cout << "|_|                                                                                                 |_|" << endl;
    cout << "|_| 1. Intersection of two multitudes                                                               |_|" << endl;
    cout << "|_| 2. Union of two multitudes                                                                      |_|" << endl;
    cout << "|_| 3. Symetrical difference between two multitudes                                                 |_|" << endl;
    cout << "|_| 4. Show if multitude A is a submultitude B                                                      |_|" << endl;
    cout << "|_| 5. Show if multitude A is equal to multitude B                                                  |_|" << endl;
    cout << "|_| 6. Show if multitude A have something in common with multitude B                                |_|" << endl;
    cout << "|_| 0. EXIT                                                                                         |_|" << endl;
    cout << "|_|                                                                                                 |_|" << endl;
    cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
    int option;
    cout << "Please enter the option you'd like to use: ";
    cin >> option;

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
        goto label;
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
    }
    while (exit != false);
    delete[]multitudeA;
    delete[]multitudeB;
}