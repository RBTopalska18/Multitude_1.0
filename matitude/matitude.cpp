#include <iostream>
#include <cmath>
using namespace std;

int inputSize()
{
    int sizeOfMultitude;

    cout << "Enter the size of the multitudes: ";

    cin >> sizeOfMultitude;

    cout << endl;

    return sizeOfMultitude;
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
        cout << mergedArray[i];
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


bool mainMenu(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[])
{
    cout << endl;
    cout << "1. Enter multitude A and multitude B" << endl;
    cout << "2. Intersection of two multitudes" << endl;
    cout << "3. Union of two multitudes" << endl;
    cout << "4. Symetrical difference between two multitudes" << endl;
    cout << "5. Difference between two multitudes" << endl;
    cout << "6. Show if multitude A is a submultitude B " << endl;
    cout << "7. Show if multitude A is equal to multitude B" << endl;
    cout << "8. Show if multitude A have something it common with multitude B " << endl;
    cout << "0. EXIT" << endl << endl;

    int option;
    cout << "Please enter the option you'd like to use: ";
    cin >> option;

    switch (option)
    {
    case 0:
        return false;
        break;
    case 1:
        cout << "Please enter the both multitudes: " << endl;
        return true;
        break;
    case 2:
        findIntersection(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 3:
        findUnion(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 4:
        return true;
        break;
    case 5:
        return true;
        break;
    case 6:
        isASubMultitude(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
        return true;
        break;
    case 7:
        return true;
        break;
    case 8:
        return true;
        break;
    }
}


int main()
{
    int sizeOfMultitudeA, sizeOfMultitudeB, * multitudeA, * multitudeB;
    bool exit = true;
    sizeOfMultitudeA = inputSize();
    multitudeA = new int[sizeOfMultitudeA];
    cout << "Enter the first multitude elements: ";
    for (int i = 0; i < sizeOfMultitudeA; i++) { cin >> multitudeA[i]; }
    cout << endl;
    sizeOfMultitudeB = sizeOfMultitudeA;
    multitudeB = new int[sizeOfMultitudeB];
    cout << "Enter the second multitude elements: ";
    for (int i = 0; i < sizeOfMultitudeA; i++) { cin >> multitudeB[i]; }
    do { exit = mainMenu(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB); } while (exit != false);
    delete[]multitudeA;
    delete[]multitudeB;
}