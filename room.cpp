#include <iostream>
#include "room.h"

Room::Room(const char* name, const char* description) :
Entity(name, description)
{
	type = ROOM;
}

Room::~Room() {}

void Room::update() const
{
	cout << "Room name: " << name << endl;
	cout << description << endl;
}
//---------------------------------------
Exit* Room::getExit() const
{
	Exit* result = (Exit*)findByEntityType(EXIT);

	return result;
}


