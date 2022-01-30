#include <iostream>
#include "exit.h"

//----------------------------
Exit::Exit(const char* name, const char* next_room_name, const char* description, Room* actual_room, Room* next_room) :
Entity(name, description, (Entity*)actual_room), locked(true), next_room_name(next_room_name), next_room(next_room), key(NULL)
{
	type = ENTITY;
}
//----------------------------
Exit::~Exit(){}
//----------------------------
void Exit::Update() const
{
	cout << "This exit connects " << name << " and " << next_room_name << endl;
	cout << description << endl;
}
//----------------------------
bool Exit::isLocked() const
{
	return (locked == true);
}
//----------------------------
void Exit::unlock()
{
	locked = false;
}
//----------------------------
string& Exit::getNextRoomName()
{
	return next_room_name;
}
//----------------------------
Room* Exit::getNextRoom() const
{
	return next_room;
}
//----------------------------
Entity* Exit::getKey() const
{
	return key;
}
//----------------------------
