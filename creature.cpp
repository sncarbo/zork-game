#include <iostream>
#include "creature.h"
#include "exit.h"
#include "room.h"
#include "item.h"


Creature::Creature(const char* name, const char* description, Room* location) :
Entity(name, description), location(location)
{
	type = CREATURE;
	
	if(location != NULL)
		location->addToContains(this);
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
	else
		cout << "You can't go that way or there is a blocked door." << endl;

	return result;
}

bool Creature::take(const string& item, const string& subitem = "")
{
	bool result = false;
	Item* item_taken = (Item*)getLocation()->findByName(item);

	if (item_taken != (Item*)this->findByName(item) && item_taken != NULL)
	{
		if (item_taken->getItemType() == BOX && subitem != "" && item_taken != NULL){
			Item* subitem_taken = (Item*)item_taken->findByName(subitem);

			if (subitem_taken != NULL)
			{
				item_taken->removeFromContains(subitem_taken);
				subitem_taken->setContainedInBox(false);
				this->addToContains(subitem_taken);
				getLocation()->removeFromContains(subitem_taken);
				result = true;
				cout << "You just took " << subitem_taken->getName() << " from the box." << endl;
			}
		}
		else if (subitem == "" && item_taken->getItemType() != BOX && !item_taken->isContainedInBox()) {
			this->addToContains(item_taken);
			getLocation()->removeFromContains(item_taken);
			result = true;
			cout << "You just took " << item_taken->getName() << "." << endl;
		}
	}

	return result;
}

bool Creature::drop(const string& item, const string& subitem = "")
{
	bool result = false;
	Item* dropped_item;

	if(subitem != "")
		dropped_item = (Item*)this->findByName(subitem);
	else
		dropped_item = (Item*)this->findByName(item);

	if (dropped_item != NULL)
	{
		if (subitem != "")
		{
			list<Entity*> related_items = getLocation()->findAllByEntityType(ITEM);

			for (list<Entity*>::const_iterator it = related_items.begin(); it != related_items.cend(); ++it)
			{
				if (((Item*)*it)->getItemType() == BOX)
				{
					(*it)->addToContains(dropped_item);
					this->removeFromContains(dropped_item);
					dropped_item->setContainedInBox(true);
					getLocation()->removeFromContains(dropped_item);
					cout << "You just dropped " << dropped_item->getName() << " in the box." << endl;
				}
			}
		}
		else
		{
			getLocation()->addToContains((Entity*)dropped_item);
			this->removeFromContains(dropped_item);
			result = true;
			cout << "You just dropped " << dropped_item->getName() << "." << endl;
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

	update();
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
		cout << "The exit from the room " << getLocation()->getName() << " have just been UNLOCKED." << endl;
		result = true;
	}

	return result;
}
