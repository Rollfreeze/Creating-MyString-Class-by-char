#include "Display.h"
#include "stdafx.h"
#include "Classes.h"

void Display::showmenu()
{
	String text1(interface.input_one());
	String text2(interface.input_two());
	p1 = text1.getmessage();
	p2 = text2.getmessage();

	if (text1 >= text2)
	{
		text1.print_message(text2.getmessage());
		text1.string_size(text2.getmessage());
		text1.strokapoisk(text2.getmessage());
		if (text1.check_substring(text2.getmessage()) == 1)
		{
			p = text2.getmessage();
			check = 1;
		}
		else
		{
			p = text2.getsubstring();
			check = 0;
		}
	}

	else
	{
		text1.print_message(text2.getmessage());
		text1.string_size(text2.getmessage());
		text2.strokapoisk(text1.getmessage());
		if (text2.check_substring(text1.getmessage()) == 1)
		{
			p = text1.getmessage();
			check = 1;
		}

		else
		{
			p = text1.getsubstring();
			check = 0;
		}

	}

	String text3(p);
	cout << endl;
	cout << "Substring ---> " << text3.getmessage() << endl;
	cout << endl;

	cout << "Which string you want to remove from the understring?\n";
	cout << "1) The first one\n";
	cout << "2) The second one\n";
	cin >> choice;

	switch (choice)
	{
	case '1':
	{
		text1.removesubstring(text3.getmessage());
		cout << "Now the first string looks like: " << text1.getmessage() << endl;
		break;
	}
	case '2':
	{
		text2.removesubstring(text3.getmessage());
		cout << "Now the first string looks like: " << text2.getmessage() << endl;
		break;
	}
	default: cout << "There is no such operation in the menu! Choose the true operation!" << endl;
		break;
	}

	while (true)
	{
		if (check)
			while (true)
			{
				cout << "Choose to which message you want to add your substring\n";
				cout << "1) Add the substring to the first message\n";
				cout << "2) Add the substring to the second message\n";
				cout << "3) Quit\n";
				cin >> choice;
				if ((choice == '1') || (choice == '2') || (choice == '3'))
					break;
				else
					cout << "Uncorrect choice! Try again!\n";
			}
		if (choice == '3')
			break;
		if (check)
			switch (choice)
			{
			case '1':
			{
				while (true)
				{
					cout << "Choose to which part of the first message you want to add your substring\n";
					cout << "1) Add the substring before the message\n";
					cout << "2) Add the substring after the message\n";
					cout << "3) Quit\n";
					cin >> choice;
					if ((choice == '1') || (choice == '2') || (choice == '3'))
						break;
					else
						cout << "Uncorrect choice! Try again!\n";
				}
				if (choice == '3')
					break;
				switch (choice)
				{
				case'1':
				{
					text4 = text3 + text1;
					if (strlen(text3.getmessage()) == 0)
						cout << "There is no substing. We can't plus messsages\n";
					else
						cout << endl << text4.getnewstring() << endl;
					break;
				}
				case'2':
				{
					text4 = text1 + text3;
					if (strlen(text3.getmessage()) == 0)
						cout << "There is no substing. We can't plus messsages\n";
					else
						cout << endl << text4.getnewstring() << endl;
					break;
				}
				default: cout << "There is no such operation in the menu! Choose the true operation!" << endl;
					break;
				}
				break;
			}
			case '2':
			{
				while (true)
				{
					cout << "Choose to which part of the second message you want to add your substring\n";
					cout << "1) Add the substring before the message\n";
					cout << "2) Add the substring after the message\n";
					cout << "3) Quit\n";
					cin >> choice;
					if ((choice == '1') || (choice == '2') || (choice == '3'))
						break;
					else
						cout << "Uncorrect choice! Try again!\n";
				}
				if (choice == '3')
					break;
				switch (choice)
				{
				case'1':
				{
					text4 = text3 + text2;
					if (strlen(text3.getmessage()) == 0)
						cout << "There is no substing. We can't plus messsages\n";
					else
						cout << endl << text4.getnewstring() << endl;
					break;
				}
				case'2':
				{
					text4 = text2 + text3;
					if (strlen(text3.getmessage()) == 0)
						cout << "There is no substing. We can't plus messsages\n";
					else
						cout << endl << text4.getnewstring() << endl;
					break;
				}
				default: cout << "There is no such operation in the menu! Choose the true operation!" << endl;
					break;
				}
				break;
			}
			default: cout << "There is no such operation in the menu! Choose the true operation!" << endl;
				break;
			}

	}
}