#pragma once
#include"stdafx.h"


class String
{
private:
	int size;
	int n;
	char* p;
	char* message1;
	char* newstring;
	String(int , char*);
	
public:
	void string_size(char*);
	void print_message(char*);
	void removesubstring(char*);
	void setmessage(char*);
	void strokapoisk(char*);
	int stroka(int, char*);
	int getstrlen();
	char* getmessage();
	char* getnewstring();
	char* getsubstring();
	bool check_substring(char*);
	String();
	String(char*);
	~String();

	String operator+(const String& other);
	bool operator>=(const String& other);
	String& operator=(const String& other);
	String(const String& other);
	bool operator==(const String& other);

};

class Interface
{
private:
	char* m1;
public:
	char* input_one();
	char* input_two();
	Interface();
	~Interface();
};




