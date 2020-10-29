#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//a function that finds an intersection between multitude A and B
void findIntersection(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    cout << "The intersection is: ";
    int areThereAnyIntersectionsInMultitudeA = 0;
    int areThereAnyIntersectionsInMultitudeB = 0;
    int* indexOfTheIntersectionA;
    int* indexOfTheIntersectionB;
    int intersectionNumber = 0;

    //loop for finding the number of intersections between the multitudes
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
        //creating a dynamic array with a size equal to the intersections
        indexOfTheIntersectionA = new int[areThereAnyIntersectionsInMultitudeA];
        indexOfTheIntersectionB = new int[areThereAnyIntersectionsInMultitudeB];
        //a loop for finding and getting the intersection 
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
        for (int i = 0; i < intersectionNumber; i++) // a loop that prints out the intersections and their position
        {
            cout << endl;
            cout << "The sectoins are found on position " << indexOfTheIntersectionA[i] << " from multitude A" << endl;
            cout << "The sectoins are found on position " << indexOfTheIntersectionB[i] << " from multitude B" << endl;
        }
    }
    cout << endl;
}

//a function for finding the union between two multitudes
void findUnion(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    int temp, count = 0, index = 0, intersectionCount = 0;
    int* mergedArray;
    //finds how many intersections are there 
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

    //declaring a dynamic array with size equal to the sum of the both multitudes size without their section
    mergedArray = new int[sizeOfMultitudeA + sizeOfMultitudeB - intersectionCount];
    //a loop in which that we assign multitude B without the intersection
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
    //a loop for assigning all the elements from multitude A
    for (int i = 0; i < sizeOfMultitudeB - count; i++)
    {
        mergedArray[index++] = multitudeB[i];
    }
    cout << "The union is: ";
    //printing the unions
    for (int i = 0; i < index; i++) 
    {
        cout << mergedArray[i] << " ";
    }

}

//a function that finds symetrical difference between the multitudes
void symetricalDifference(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    vector<int> sDifference(100);
    vector<int>::iterator sDCount;
    sort(multitudeA, multitudeA + sizeOfMultitudeA); //sorting multitude A
    sort(multitudeB, multitudeB + sizeOfMultitudeB); //sorting multitude B
    sDCount = set_symmetric_difference(multitudeA, multitudeA + sizeOfMultitudeA, multitudeB, multitudeB + sizeOfMultitudeB, sDifference.begin());//finding symetrical difference
    sDifference.resize(sDCount - sDifference.begin()); 
    cout << "The simetric difference is: ";
    //printing the intersection
    for (sDCount = sDifference.begin(); sDCount != sDifference.end(); sDCount++)
    {
        cout << *sDCount << " ";
    }
}