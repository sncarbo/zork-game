#include <iostream>
#include "room.h"

Room::Room(const char* name, const char* next_room_name, const char* description, Room* actual_room, Room* next_room) :
	Entity(name, description, actual_room),
	locked(false), key(NULL), next_room_name(next_room_name), next_room(next_room)
{
	type = ROOM;
}
//--------------------------------------
Room::Room() {}
//---------------------------------------
Room::Update() const
{
	cout << "Actual room: " << name << endl;
	cout << "Next room: " << next_room_name << endl;
	cout << description << endl;
	cout << "The door is..." << (locked) ? "LOCKED" : "NOT LOCKED";


}
//---------------------------------------
boolean Room::isLocked() {
	return locked;
}
//---------------------------------------
string& Room::get


