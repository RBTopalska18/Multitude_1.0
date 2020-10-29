#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//a function that is for welcoming the user
void greeting()
{
    cout << "|_|_|_|_|_|_|_|_* Welcome to our program! *_|_|_|_|_|_|_|_|" << endl;
    cout << endl;
}

//a function that is for entering the size of the multitude
int inputSize()
{ 
    int sizeOfMultitude;
    cout << endl;
    cout << "Enter the size of the multitude: ";

    cin >> sizeOfMultitude;

    if (sizeOfMultitude < 0) //checks if the size of the multitude is a positive number 
    {
        cout << "The size of the multitude should be a positive number!" << endl;
        inputSize(); //calls the function if size of the maltitude is a negative number  
    }
    else
    {
        return sizeOfMultitude;
    }
}

//a function that is for entering the elements of the multitude
void inputMultitudeElements(int multitude[], int sizeOfMultitude)
{
  
    if (sizeOfMultitude == 0)  
    {
        multitude[0] = NULL; //making the first index of the number to point to nowhere
    }
    else
    {
        cout << "Enter the elements of multitude: ";
        for (int i = 0; i < sizeOfMultitude; i++)
        {
            cin >> multitude[i];
        }
    }
}