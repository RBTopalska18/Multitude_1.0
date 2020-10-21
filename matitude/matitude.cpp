#include <iostream>
#include <cmath>
using namespace std;

int inputSize()
{
	int sizeOfMultitude;

	cout << "Enter size of the multitude: ";

	cin >> sizeOfMultitude;

	cout << endl;

	return sizeOfMultitude;
}

void findsSection(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[]) {
	cout << endl;
	cout << "The section/s is/are: ";
	int areThereAnySections = 0;
	for (int i = 0; i < sizeOfMultitudeA; i++)
	{
		for (int j = 0; j < sizeOfMultitudeB; j++)
		{
			if (multitudeA[i] == multitudeB[j])
			{
				cout << multitudeA[i]<<" ";
				areThereAnySections++;
			}
		}
	}
	if (areThereAnySections == 0)
	{
		cout << "There are no sections";
	}
	cout << endl;
}

bool mainMenu(int sizeOfMultitudeA, int sizeOfMultitudeB, int multitudeA[], int multitudeB[])
{
	cout << endl;
		cout << "1. Enter multitude A and multitude B" << endl;
		cout << "2. Section of two multitudes" << endl;
		cout << "3. Unification of two multitudes" << endl;
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
		findsSection(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);
		return true;
		break;
	case 3:
		return true;
		break;
	case 4:
		return true;
		break;
	case 5:
		return true;
		break;
	case 6:
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
	cout << "Enter multitude elemts: ";
	for (int i = 0; i < sizeOfMultitudeA; i++) { cin >> multitudeA[i]; }
	cout << endl;
	sizeOfMultitudeB = inputSize();
	multitudeB = new int[sizeOfMultitudeB];
	cout << "Enter multitude elemts: ";
	for (int i = 0; i < sizeOfMultitudeA; i++) { cin >> multitudeB[i]; }
	do {exit = mainMenu(sizeOfMultitudeA, sizeOfMultitudeB, multitudeA, multitudeB);} while (exit != false);
	delete[]multitudeA;
	delete[]multitudeB;
}