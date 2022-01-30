#include <iostream>
#include <string>
#include "world.h"
#include <conio.h>

using namespace std;

int main()
{
	char** argv = new char* [10];
	string result;
	World zork;
	bool proceed = true;

	cout << "<--- Welcome to ESCAPE ROOM ZORK! --->" << endl << endl;

	while (proceed)
	{
		if (_kbhit())
		{
			result.push_back(_getch());

			switch (result.at(result.length()-1))
			{
			case '\b':
				if (result.length() > 0)
				{
					result.pop_back();
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
				break;
			case 'q':
				proceed = false;
				break;
			default:
				break;
			}
		}
	}

	cout << "See you soon!" << endl;
	return 0;
}