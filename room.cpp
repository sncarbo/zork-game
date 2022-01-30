#include <iostream>
#include "room.h"

Room::Room(const char* name, const char* description) :
Entity(name, description, NULL)
{
	type = ROOM;
}
//--------------------------------------
Room::~Room() {}
//---------------------------------------
void Room::Update() const
{
	cout << "Actual room: " << name << endl;
	cout << description << endl;
}
//---------------------------------------
Exit* Room::getExit(const string& direction) const
{
	Exit* result = ((Exit*) findContains(direction, EXIT));

	return result;
}


