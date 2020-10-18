#include <iostream>
#include <cmath>

using namespace std;


bool mainMenu() {
	cout << "1. Section of two multitudes" << endl;
	cout << "2. Unification of two multitudes" << endl;
	cout << "3. Symetrical difference between two multitudes" << endl;
	cout << "4. Difference between two multitudes" << endl;
	cout << "5. Show if multitude A is a submultitude B " << endl;
	cout << "6. Show if multitude A is equal to multitude B" << endl;
	cout << "7. Show if multitude A have something it common with multitude B " << endl;
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
	}

}

int main()
{
	int sizeOfMaltitudeA, sizeOfMaltitudeB;
	int* maltitudeA, * maltitudeB;

	bool exit= true;
	
	cin >> sizeOfMaltitudeA;

	maltitudeA = new int[sizeOfMaltitudeA];

	for (int i = 0; i < sizeOfMaltitudeA; i++)
	{
		cin >> maltitudeA[i];
	}

	cin >> sizeOfMaltitudeB;

	maltitudeB = new int[sizeOfMaltitudeB];

	for (int i = 0; i < sizeOfMaltitudeB; i++)
	{
		cin >> maltitudeB[i];
	}

	for (int i = 0; i < sizeOfMaltitudeB; i++)
	{
		cout << maltitudeB[i] << " " << maltitudeA[i] << " ";
	}

	delete[]maltitudeA;
	delete[]maltitudeB;
	
	do {exit=mainMenu()} while (exit!= false)
	
}
