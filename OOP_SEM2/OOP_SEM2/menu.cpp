#include "stdafx.h"

void menu()
{
	int choice = 0;

	cout << "\t\t Menu of OOP: \n";
	cout << "\t\t 2: seminar 2, 3: seminar 3 \n";
	cout << "\t\t 4: seminar 4, 5: seminar 5 \n";
	cout << "\t\t choose the project: \n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		break;
	default: cout << "There is no such operation in the menu! Choose the true operation!" << endl;
		break;
	}
}