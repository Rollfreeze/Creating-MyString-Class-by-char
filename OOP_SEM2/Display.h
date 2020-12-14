#pragma once
#include"stdafx.h"
#include "Classes.h"

class Display
{

private:
	bool check;
	char choice;
	char* p;
	char* p1;
	char* p2;
	Interface interface;
	String text4;

public:
	friend Interface;
	friend String;

	void showmenu();

};

