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

//a function that is for entering the size of the set
int inputSize()
{ 
    int sizeOfSet;
    cout << endl;
    cout << "Enter the size of the set: ";

    cin >> sizeOfSet;

    if (sizeOfSet < 0) //checks if the size of the set is a positive number 
    {
        cout << "The size of the set should be a positive number!" << endl;
        inputSize(); //calls the function if size of the maltitude is a negative number  
    }
    else
    {
        return sizeOfSet;
    }
}

//a function that is for entering the elements of the set
void inputSetElements(int set[], int sizeOfSet)
{
  
    if (sizeOfSet == 0)  
    {
        set[0] = NULL; //making the first index of the number to point to nowhere
    }
    else
    {
        cout << "Enter the elements of set: ";
        for (int i = 0; i < sizeOfSet; i++)
        {
            cin >> set[i];
        }
    }
}