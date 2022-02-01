#include <iostream>
#include <string>
#include "world.h"
#include <vector>

using namespace std;

bool validWord(const string& word)
{
	bool result = false;
	string aux = word.substr(0, word.find(" "));

	if (_stricmp(aux.c_str(), "go") == 0 || _stricmp(aux.c_str(), "take") == 0
		|| _stricmp(aux.c_str(), "drop") == 0 || _stricmp(aux.c_str(), "unlock") == 0
		|| _stricmp(aux.c_str(), "inventory") == 0 || _stricmp(aux.c_str(), "quit") == 0)
		result = true;
	else
		cout << "Sorry, it's not a valid word." << endl;

	return result;
}

int main()
{
	string input;
	vector<string> commands;
	commands.reserve(10);
	World* zork = new World();
	bool proceed = true;

	cout << "<--- Welcome to ESCAPE ROOM ZORK! --->" << endl << endl;

	while (proceed)
	{
		commands.clear();

		do
		{
			input = "";
			cout << ">> ";
			cin >> input;

		} while (!validWord(input));

		while (input.find(" ") != string::npos)
		{
			commands.push_back(input.substr(0, input.find(" ")));
			input = input.substr(input.find(" ") + 1, (input.size()- input.find(" ")));
			cout << input;
		}

		zork->command(commands);

		if (commands.at(0) == "quit") proceed = false;
	}

	cout << "See you soon!" << endl;
	return 0;
}