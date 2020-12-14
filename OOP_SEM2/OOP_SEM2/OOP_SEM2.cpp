#include "stdafx.h"
#include "Classes.h"
#include "Functions.h"

int main()
{
	char* p;
	Interface interface;
	String text1(interface.input_one());
	String text2(interface.input_two());

	if (text1.getstrlen() >= text2.getstrlen())
	{
		text1.print_message(text2.getmessage());
		text1.string_size(text2.getmessage());
		text1.strokapoisk(text2.getmessage());
		p = text2.getmessage();
	}
	else
	{
		text2.print_message(text1.getmessage());
		text2.string_size(text1.getmessage());
		text2.strokapoisk(text1.getmessage());
		p = text1.getmessage();
	}

	String text3(p);

	cout << text3.getmessage();

	return 0;
}