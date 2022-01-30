#include <iostream>
#include "creature.h"
#include "exit.h"
#include "room.h"
#include "item.h"


//----------------------------------------
Creature::Creature(const char* name, const char* description, Room* creature_room) :
Entity(name, description, creature_room)
{
	type = CREATURE;
	alive = true;
}
//----------------------------------------
Creature::~Creature(){}
//----------------------------------------
bool Creature::isAlive() const
{
	return alive;
}
//----------------------------------------
Room* Creature::getRoom() const
{
	return (Room*)parent;
}
//----------------------------------------
Item* Creature::getItemTaken() const
{
	return item_taken;
}
//----------------------------------------
void Creature::Update() const
{
	cout << name << " and is... " << ((isAlive()) ? "ALIVE" : "DEAD") << endl;
	cout << description;
}
//----------------------------------------
bool Creature::go(const string& direction)
{
	bool result = false;
	Exit* exit = getRoom()->getExit(direction);

	if (isAlive() && exit != NULL) {
		changeParentTo(exit->getNextRoom());
		result = true;
		cout << "Yout left this room... Now you're going to " << exit->getNextRoomName() << endl;
	}

	return result;
}
//-------------------------------------------
bool Creature::take(const string& item)
{
	bool result = false;
	

	if (item.find(" ") != string::npos)
	{
		size_t space = item.find(" ");
		string main_item = item.substr(0, space-1);
		string subitem = item.substr(space, item.length()-1);
	}

	item_taken = (Item*)parent->findContains(item, ITEM);

	return result;
}
//-------------------------------------------
bool Creature::drop(const string& item)
{
	
}
//-------------------------------------------
void Creature::inventory() const
{
	if (getItemTaken() == NULL)
		cout << "You don't have any items...";
	else
		cout << "You have an item! It's a " << getItemTaken()->getItemTypeString() << endl;
}
//-------------------------------------------
bool Creature::unlock(const string& direction) {
	bool result = false;
	Exit* exit = getRoom()->getExit(direction);

	if (isAlive() && exit != NULL && item_taken != NULL && item_taken->getItemType() == KEY && exit->isLocked())
	{
		exit->unlock();
		cout << "The exit to the room " << parent->getName() << " have just been UNLOCKED." << endl;
		result = true;
	}

	return result;
}
