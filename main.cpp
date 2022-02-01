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
		|| _stricmp(aux.c_str(), "inventory") == 0 || _stricmp(aux.c_str(), "update") == 0
		|| _stricmp(aux.c_str(), "quit") == 0)
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
			getline(cin >> ws, input);

		} while (!validWord(input));

		string temp = "";
		for (int i = 0; i < input.length(); ++i) {

			if (input[i] == ' ') {
				commands.push_back(temp);
				temp = "";
			}
			else {
				temp.push_back(input[i]);
			}

		}
		commands.push_back(temp);

		zork->command(commands);

		if (commands.at(0) == "quit") proceed = false;
	}

	cout << "See you soon!" << endl;
	return 0;
}