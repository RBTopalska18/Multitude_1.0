#include <iostream>
#include <cmath>
using namespace std;

void greeting()
{
	cout << "Welcome to our program! " << endl;

}


void findsSection(int& sizeOfMultitudeA, int& sizeOfMultitudeB, int* multitudeA, int* multitudeB) {
	for (int i = 0; i < sizeOfMultitudeA; i++)
	{
		for (int j = 0; j < sizeOfMultitudeB; j++)
		{
			if (multitudeA[i] == multitudeB[j])
			{
				cout << "There is section in " << i << " position from multitudeA and in " << j << " position from multitudeB";
				cout << endl;
				cout << "The Section is " << multitudeA[i];
			}
		}
	}
}

bool mainMenu(int& sizeOfMultitudeA, int& sizeOfMultitudeB, int* multitudeA, int* multitudeB)
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
	cout << "0. EXIT" << endl;

	int option;
	cin >> option;

	switch (option)
	{
	case 0:
		return false;
		break;
	case 1:

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
	int sizeOfMultitudeA, sizeOfMultitudeB;
	int* multitudeA, *multitudeB;
	bool exit = true;
	greeting();
	 cin >> sizeOfMultitudeA;
	multitudeA = new int[sizeOfMultitudeA];

	for (int i = 0; i < sizeOfMultitudeA; i++)
	{
		cin >> multitudeA[i];
	}

	cin >> sizeOfMultitudeB;
	multitudeB = new int[sizeOfMultitudeB];

	for (int i = 0; i < sizeOfMultitudeB; i++)
	{
		cin >> multitudeB[i];
	}
	for (int i = 0; i < sizeOfMultitudeB; i++)
	{
		cout << multitudeB[i] << " " << multitudeA[i] << " ";
	}
	delete[]multitudeA;
	delete[]multitudeB;
	do {

		exit = mainMenu(sizeOfMultitudeA,sizeOfMultitudeB,multitudeA,multitudeB);
	} while (exit != false);

}