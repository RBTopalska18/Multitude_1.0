#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//a function that will check if the sets are equal
void showIsItEqual(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[])
{
    int equalCheck = 0;
    //find how many common elements are there 
    for (int i = 0; i < sizeOfSetA; i++)
    {
        for (int j = 0; j < sizeOfSetB; j++)
        {
            if (setA[i] == setB[j])
            {
                equalCheck++;
            }
        }
    }
    if (equalCheck == sizeOfSetA && sizeOfSetA == sizeOfSetB)
    {
        cout << "The sets are equal!" << endl;
    }
    else {
        cout << "The sets are not equal!" << endl;
    }
}

//a function that will check if the set elements are prime numbers
int checkPrime(int setElement) {
    if (setElement <= 1)
    {
        return 0;
    }
    for (int j = 2; j <= setElement / 2; j++) {
        if (setElement % j == 0) {
            return 0;
        }
        return 1;
    }
}

//a function that shows the user how many odd and even numbers are in each of the sets, what is the sum of every element in the set
//and shows the number of prime numbers 
void haveSomethingInCommon(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[])
{
    int oddNumbers = 0, evenNumbers = 0;
    int setSum = 0;
    showIsItEqual(sizeOfSetA, sizeOfSetB, setA, setB);
    cout << endl;
    for (int i = 0; i < sizeOfSetA; i++)
    {
        if (setA[i] % 2 == 0) {
            evenNumbers++;
        }
        else {
            oddNumbers++;
        }
    }
    cout << "In set A there are " << oddNumbers << " odd numbers and " << evenNumbers << " even numbers" << endl;
    evenNumbers = 0;
    oddNumbers = 0;
    for (int i = 0; i < sizeOfSetB; i++)
    {
        if (setB[i] % 2 == 0) {
            evenNumbers++;
        }
        else {
            oddNumbers++;
        }
    }
    cout << "In set B there are " << oddNumbers << " odd numbers and " << evenNumbers << " even numbers" << endl;
    for (int i = 0; i < sizeOfSetA; i++)
    {
        setSum += setA[i];
    }
    cout << endl;
    cout << "The sum of all elements in set A is: " << setSum << endl;
    setSum = 0;
    for (int i = 0; i < sizeOfSetB; i++)
    {
        setSum += setB[i];
    }
    cout << "The sum of all elements in set B is: " << setSum << endl;
    int primeCount = 0;
    int isprime = 0;
    for (int i = 0; i < sizeOfSetA; i++) {
        isprime = checkPrime(setA[i]);
        if (isprime == 1)
            primeCount++;
    }
    cout << endl;
    cout << "There is/are: " << primeCount << " prime numbers in set A" << endl;
    primeCount = 0;
    isprime = 0;
    for (int i = 0; i < sizeOfSetB; i++) {
        isprime = checkPrime(setB[i]);
        if (isprime == 1)
            primeCount++;
    }
    cout << "There is/are: " << primeCount << " prime numbers in set B" << endl;
}