#include <iostream>
#include "exit.h"
#include "room.h"

Exit::Exit(const char* name, const char* description, Room* source_room, Room* next_room, DirectionType direction) :
Entity(name, description), locked(true), source_room(source_room), next_room(next_room), direction(direction)
{
	type = ENTITY;
}

Exit::~Exit(){}

void Exit::update() const
{
	cout << "This exit connects " << getSourceRoom()->getName() << " and " << getNextRoom()->getName() << endl;
	cout << description << endl;
}

bool Exit::isLocked() const
{
	return (locked == true);
}

void Exit::unlock()
{
	locked = false;
}

Room* Exit::getSourceRoom() const
{
	return source_room;
}

Room* Exit::getNextRoom() const
{
	return next_room;
}

DirectionType Exit::getDirection() const
{
	return direction;
}

string Exit::getDirectionString() const
{
	string result = "";

	switch (direction)
	{
	case NORTH:
		result = "NORTH";
		break;
	case SOUTH:
		result = "SOUTH";
		break;
	case EAST:
		result = "EAST";
		break;
	case WEST:
		result = "WEST";
		break;
	}

	return result;
}

