#include "stdafx.h"
#include "Classes.h"

void String::string_size(char* message2)
{
	
	size = strlen(message1);
	if (size == 0)
	{
		cout << "The first Message is empty!\n";
	}
	else
	{
		cout << "String size of your first massage: " << size << endl;
		size = 0;
	}

	size = strlen(message2);
	if (size == 0)
	{
		cout << "The second Message is empty!\n";
	}
	else
	{
		cout << "String size of your second massage: " << size << endl;
		size = 0;
	}
	cout << endl;
}

char* String::getmessage()
{
	return message1;
}


void String::print_message(char* message2)
{
	cout << endl;
	cout << "Your first message was: " << '"';
	for (int i = 0; i < strlen(message1); i++)
	{
		cout << message1[i];
	}
	cout << '"' << endl;

	cout << "Your second message was: " << '"';
	for (int i = 0; i < strlen(message2); i++)
	{
		cout << message2[i];
	}
	cout << '"' << endl << endl;
}

int String::stroka(int n, char* message2)
{
	int i, j;
	int lenC, lenS;


	for (lenC = 0; message2[lenC]; lenC++);
	for (lenS = 0; message1[lenS]; lenS++);

	for (i = 0; i <= lenS - lenC; i++)
	{
		for (j = 0; j < lenC && message1[i + j] == message2[j]; j++);

		if (j == lenC)
			if (n - 1) n--;
			else return i;
	}
	return -1;
}
void String::strokapoisk(char* message2)
{
	bool check = 0;
	int i, n = 0;
	int size = strlen(message2);
	for (i = 1; n != -1; i++)
	{
		n = stroka(i, message2);

		if (n >= 0)
		{
			if (strlen(message2) == 1)
			{
				cout << "The coincidence of two messages begins at " << n << " index and ends at " << n << endl;
			}
			else
			{
				if (strlen(message2) > 1)
					cout << "The coincidence of two messages begins at " << n << " index and ends at " << n + size - 1 << endl;
				else
					cout << "The coincidence of two messages begins at " << n << " index and ends at " << n + size << endl;
			}
			check = 1;
		}
		if(check == 0)
			cout << "There is not any coincidence\n";
	}
}

void String::removesubstring(char* substring)
{
	bool check = 0;
	int i, n = 0;
	int size = strlen(this->message1);
	for (i = 1; n != -1; i++)
	{
		n = stroka(i, this->message1);

		if (n >= 0)
		{
			if (strlen(substring) == 1)
			{
				for (int k = 0; k < size; k++)
				{
					if (this->message1[k] == substring[0])
					{
						for (int w = k; w < size; w++)
							swap(this->message1[w], this->message1[w + 1]);
					}
				}
				check = 1;
			}
		}
		if (check == 0)
			cout << "There is not any coincidence\n" << endl;
	}
}


bool String::check_substring(char* message2)
{
	bool check = 0;
	int i, n = 0;
	for (i = 1; n != -1; i++)
	{
		n = stroka(i, message2);

		if (n >= 0)
		{
			if (strlen(message2) >= 1)
				check = 1;
			else
				check = 0;
		}
	}
	return check;
}


int String::getstrlen()
{
	return strlen(message1);
}

char* Interface::input_one()
{
	cout << "Please input the first message ---> ";
	cin.getline(m1, 50);
	return m1;
}

char* Interface::input_two()
{
	cout << "Please input the second message ---> ";
	cin.getline(m1, 50);
	return m1;
}

Interface::~Interface()
{
	delete[] m1;
}

String::~String()
{
	delete[] message1;
	delete[] newstring;
}

String::String(char* entermessage)
{
	p = new char[1];
	message1 = new char[100];
	strcpy_s(message1, 100, entermessage);
}

char* String::getsubstring()
{
	p[0] = '\0';
	return p;
}


String::String()
{
	p = new char[1];
	message1 = new char[100];
}


void String::setmessage(char* other)
{
	strcpy_s(message1, 100, other);
}

String::String(int length, char* payload)
{
	size = length;
	newstring = payload;
}

char* String::getnewstring()
{
	return this->newstring;
}

Interface::Interface()
{
	m1 = new char[100];
}

String::String(const String& other) //copy constructor
{
	p = new char[1];
	message1 = new char[100];

	int length = strlen(other.newstring);
	this->newstring = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->newstring[i] = other.newstring[i];
	}

	this->newstring[length] = '\0';
}

String& String::operator=(const String& other)
{
	if (this->newstring != nullptr)
	{
		delete[] newstring;
	}

	int length = strlen(other.newstring);
	this->newstring = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->newstring[i] = other.newstring[i];
	}

	this->newstring[length] = '\0';

	return *this;
}

String String::operator+(const String& other)
{
	String result;

	int size1 = strlen(this->message1);
	int size2 = strlen(other.message1);
	result.newstring = new char[size1 + size2 + 1];

	int i = 0;
	for (; i < size1; i++)
	{
		result.newstring[i] = this->message1[i];
	}

	for (int j = 0; j < size2; j++, i++)
	{
		result.newstring[i] = other.message1[j];
	}

	result.newstring[size1 + size2] = '\0';

	return result;
}

bool String::operator>=(const String& other)
{
	bool check;
	int size1 = strlen(this->message1);
	int size2 = strlen(other.message1);
	if (size1 >= size2)
	{
		newstring = new char[size1];
		for (int i = 0; i < size1; i++)
		{
			newstring[i] = this->message1[i];
		}
		check = true;
	}

	else
	{
		newstring = new char[size2];
		for (int i = 0; i < size2; i++)
		{
			newstring[i] = other.message1[i];
		}
		check = false;
	}

	return check;
}

bool String::operator==(const String& other)
{
	bool check = check_substring(other.message1);
	return check;
}