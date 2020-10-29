#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

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

    else if (sizeOfMultitudeB == sizeOfMultitudeA && sizeOfMultitudeA == isASub)
    {
        cout << "The multitudes are equal!";
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
    if (equalCheck == sizeOfMultitudeA && sizeOfMultitudeA == sizeOfMultitudeB)
    {
        cout << "The multitudes are equal!" << endl;
    }
    else {
        cout << "The multitudes are not equal!" << endl;
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
    cout << endl;
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
    cout << endl;
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