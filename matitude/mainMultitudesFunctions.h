#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


void findIntersection(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    cout << "The intersection is: ";
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
    cout << "The union is: ";
    for (int i = 0; i < index; i++)
    {
        cout << mergedArray[i] << " ";
    }

}

void symetricalDifference(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
    vector<int> sDifference(100);
    vector<int>::iterator sDCount;
    sort(multitudeA, multitudeA + sizeOfMultitudeA);
    sort(multitudeB, multitudeB + sizeOfMultitudeB);
    sDCount = set_symmetric_difference(multitudeA, multitudeA + sizeOfMultitudeA, multitudeB, multitudeB + sizeOfMultitudeB, sDifference.begin());
    sDifference.resize(sDCount - sDifference.begin());
    cout << "The simetric difference is: ";
    for (sDCount = sDifference.begin(); sDCount != sDifference.end(); sDCount++)
    {
        cout << *sDCount << " ";
    }
}