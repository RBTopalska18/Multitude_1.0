#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void greeting()
{
    cout << "|_|_|_|_|_|_|_|_* Welcome to our program! *_|_|_|_|_|_|_|_|" << endl;
    cout << endl;
}
   
int inputSize()
{
    int sizeOfMultitude;
    cout << endl;
    cout << "Enter the size of the multitude: ";

    cin >> sizeOfMultitude;

    if (sizeOfMultitude <= 0)
    {
        cout << "The size of the multitude should be a positive number!" << endl;
        inputSize();
    }
    else
    {
        return sizeOfMultitude;
    }
}

void inputMultitudeElements(int multitude[], int sizeOfMultitude)
{
    cout << "Enter the elements of multitude: ";
    for (int i = 0; i < sizeOfMultitude; i++)
    {
        cin >> multitude[i];
    }
}