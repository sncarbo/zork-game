#include <iostream>
#include "room.h"

Room::Room(const char* name, const char* description) :
Entity(name, description), exit(NULL)
{
	type = ROOM;
}

Room::~Room() {}

void Room::update() const
{
	cout << "Room name: " << name << endl;
	cout << description << endl;
	cout << "This room contains: ";

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
	{
		cout << "-- " << (*it)->getName() << ": " << (*it)->getDescription() << endl;
	}
}

Exit* Room::getExit() const
{
	return exit;
}

void Room::setExit(Exit* exit)
{
	this->exit = exit;
}


