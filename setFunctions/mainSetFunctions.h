#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//a function that finds an intersection between set A and B
void findIntersection(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[]) {
    cout << "The intersection is: ";
    int areThereAnyIntersectionsInSetA = 0;
    int areThereAnyIntersectionsInSetB = 0;
    int* indexOfTheIntersectionA;
    int* indexOfTheIntersectionB;
    int intersectionNumber = 0;

    //loop for finding the number of intersections between the sets
    for (int i = 0; i < sizeOfSetA; i++)
    {
        for (int j = 0; j < sizeOfSetB; j++)
        {
            if (setA[i] == setB[j])
            {
                cout << setA[i] << " ";
                areThereAnyIntersectionsInSetA++;
                areThereAnyIntersectionsInSetB++;
            }
        }
    }
    if (areThereAnyIntersectionsInSetA == 0)
    {
        cout << "There are no intersections";
    }
    else
    {
        //creating a dynamic array with a size equal to the intersections
        indexOfTheIntersectionA = new int[areThereAnyIntersectionsInSetA];
        indexOfTheIntersectionB = new int[areThereAnyIntersectionsInSetB];
        //a loop for finding and getting the intersection 
        for (int i = 0; i < sizeOfSetA; i++)
        {
            for (int j = 0; j < sizeOfSetB; j++)
            {
                if (setA[i] == setB[j])
                {
                    indexOfTheIntersectionA[intersectionNumber] = i + 1;
                    indexOfTheIntersectionB[intersectionNumber] = j + 1;
                    intersectionNumber++;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < intersectionNumber; i++) // a loop that prints out the intersections and their position
        {
            cout << endl;
            cout << "The sectoins are found on position " << indexOfTheIntersectionA[i] << " from set A" << endl;
            cout << "The sectoins are found on position " << indexOfTheIntersectionB[i] << " from set B" << endl;
        }
    }
    cout << endl;
}

//a function for finding the union between two sets
void findUnion(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[]) {
    int temp, count = 0, index = 0, intersectionCount = 0;
    int* mergedArray;
    //finds how many intersections are there 
    for (int i = 0; i < sizeOfSetA; i++)
    {
        for (int j = 0; j < sizeOfSetB; j++)
        {
            if (setA[i] == setB[j])
            {
                intersectionCount++;
            }
        }
    }

    //declaring a dynamic array with size equal to the sum of the both sets size without their section
    mergedArray = new int[sizeOfSetA + sizeOfSetB - intersectionCount];
    //a loop in which that we assign set B without the intersection
    for (int i = 0; i < sizeOfSetA; i++)
    {
        for (int j = 0; j < sizeOfSetB - count; j++)
        {
            if (setA[i] == setB[j])
            {
                temp = setB[j];
                setB[j] = setB[sizeOfSetB - 1 - count];
                setB[sizeOfSetB - 1 - count] = temp;
                count++;
            }
        }
        mergedArray[index++] = setA[i];
    }
    //a loop for assigning all the elements from set A
    for (int i = 0; i < sizeOfSetB - count; i++)
    {
        mergedArray[index++] = setB[i];
    }
    cout << "The union is: ";
    //printing the unions
    for (int i = 0; i < index; i++) 
    {
        cout << mergedArray[i] << " ";
    }

}

//a function that finds symetrical difference between the sets
void symetricalDifference(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[]) {
    vector<int> sDifference(100);
    vector<int>::iterator sDCount;
    sort(setA, setA + sizeOfSetA); //sorting set A
    sort(setB, setB + sizeOfSetB); //sorting set B
    sDCount = set_symmetric_difference(setA, setA + sizeOfSetA, setB, setB + sizeOfSetB, sDifference.begin());//finding symetrical difference
    sDifference.resize(sDCount - sDifference.begin()); 
    cout << "The simetric difference is: ";
    //printing the intersection
    for (sDCount = sDifference.begin(); sDCount != sDifference.end(); sDCount++)
    {
        cout << *sDCount << " ";
    }
}

void findDifferenceOfSetA(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[])
{
    int* newSetA;
    newSetA = new int[sizeOfSetA];
    int counterDifferenceElements = 0;
    int* differenceArray;
    differenceArray = new int[sizeOfSetA];

    for (int i = 0; i < sizeOfSetA; i++)
    {
        newSetA[i] = setA[i];
        for (int j = 0; j < sizeOfSetB; j++)
        {
            if (newSetA[i] == setB[j])
            {
                newSetA[i] = 0;
            }
        }
    }
    for (int i = 0; i < sizeOfSetA; i++)
    {
        if (newSetA[i] != 0)
        {
            differenceArray[counterDifferenceElements++] = newSetA[i];
        }
    }
    cout << "The difference of set A has " << counterDifferenceElements << " elements: ";
    for (int i = 0; i < counterDifferenceElements; i++)
    {
        cout << differenceArray[i] << " ";
    }
    cout << endl;
}

void findDifferenceOfSetB(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[])
{
    int* newSetB;
    newSetB = new int[sizeOfSetB];
    int counterDifferenceElements = 0;
    int* differenceArray;
    differenceArray = new int[sizeOfSetB];

    for (int i = 0; i < sizeOfSetB; i++)
    {
        newSetB[i] = setB[i];
        for (int j = 0; j < sizeOfSetA; j++)
        {
            if (newSetB[i] == setA[j])
            {
                newSetB[i] = 0;
            }
        }
    }
    for (int i = 0; i < sizeOfSetB; i++)
    {
        if (newSetB[i] != 0)
        {
            differenceArray[counterDifferenceElements++] = newSetB[i];
        }
    }
    cout << "The difference of set B has " << counterDifferenceElements << " elements: ";
    for (int i = 0; i < counterDifferenceElements; i++)
    {
        cout << differenceArray[i] << " ";
    }
    cout << endl;
}

//a function that will check if there are any sub sets
void isASubSet(int sizeOfSetA, int sizeOfSetB, int setA[], int setB[]) {

    int isASub = 0;
    //a loop for finding how many common elements there are
    for (int i = 0; i < sizeOfSetA; i++)
    {
        for (int j = 0; j < sizeOfSetB; j++)
        {
            if (setA[i] == setB[j])
            {
                isASub++;
            }
        }
    }

    if (sizeOfSetB == sizeOfSetA && sizeOfSetA == isASub) //checks if the sets are equal and equal to isASub
    {
        cout << "The sets are equal!";
        cout << endl;
    }
    else if (isASub == sizeOfSetB)
    {
        cout << "Set B is sub set of set A";
        cout << endl;
    }
    else if (isASub == sizeOfSetA)
    {
        cout << "Set A is sub set of set B";
        cout << endl;
    }
    else
    {
        cout << "There are no sub sets";
        cout << endl;
    }

}