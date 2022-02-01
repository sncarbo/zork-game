#include <iostream>
#include "creature.h"
#include "exit.h"
#include "room.h"
#include "item.h"


Creature::Creature(const char* name, const char* description, Room* location) :
Entity(name, description), location(location)
{
	type = CREATURE;
}

Creature::~Creature(){}

Room* Creature::getLocation() const
{
	return location;
}

void Creature::update() const
{
	cout << "Creature name: " << getName() << endl;
	cout << description << endl;
	cout << "This creature is at " << getLocation()->getName() << " room." << endl;
}

bool Creature::go(const string& direction)
{
	bool result = false;
	Exit* exit = getLocation()->getExit();

	if (exit != NULL && exit->getDirectionString() == direction && !exit->isLocked()) {
		result = true;
		this->location = exit->getNextRoom();
		cout << "Yout left this room... Now you're going to " << exit->getNextRoom()->getName() << endl;
	}

	return result;
}

bool Creature::take(const string& item, const string& subitem = "")
{
	bool result = false;
	Item* item_taken = (Item*)getLocation()->findByName(item);

	if (item_taken != (Item*)this->findByName(item))
	{
		if (item_taken->getItemType() == BOX && subitem != ""){
			Item* subitem_taken = (Item*)item_taken->findByName(subitem);
			this->addToContains(subitem_taken);
			result = true;
		}
		else if (subitem == "") {
			this->addToContains(item_taken);
			result = true;
		}
	}

	return result;
}

bool Creature::drop(const string& item)
{
	bool result = false;
	Item* dropped_item = (Item*)this->findByName(item);
	list<Entity*> items_room = getLocation()->findAllByEntityType(ITEM);

	for (list<Entity*>::const_iterator it = items_room.begin(); it != items_room.cend() && !result; ++it)
	{
		if (((Item*)*it)->getItemType() == BOX)
		{
			(*it)->addToContains(dropped_item);
			this->removeFromContains(dropped_item);
			result = true;
		}
	}

	return result;
}

void Creature::inventory() const
{
	cout << "This creature have this items: ";

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it) {
		cout << (*it)->getName() << " ";
	}

	cout << endl;
}

bool Creature::unlock() {
	bool result = false;
	Exit* exit = getLocation()->getExit();
	list<Entity*> items = this->findAllByEntityType(ITEM);
	Item* key = NULL;

	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		if (((Item*)*it)->getItemType() == KEY)
			key = ((Item*) *it);
	}

	if (exit != NULL && key != NULL && exit->isLocked())
	{
		exit->unlock();
		this->removeFromContains(key);
		cout << "The exit to the room " << getLocation()->getName() << " have just been UNLOCKED." << endl;
		result = true;
	}

	return result;
}
