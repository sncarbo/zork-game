#include <iostream>
#include "room.h"
#include "item.h"
#include "exit.h"

Item::Item(const char* name, const char* description, ItemType item_type, Room* room, bool containedInBox) :
Entity(name, description), item_type(item_type), room(room), containedInBox(containedInBox)
{
	type = ITEM;

	if (item_type == BOX)
	{
		list<Entity*> items = room->findAllByEntityType(ITEM);
		
		for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
		{
			if (((Item*)*it)->getItemType() == KEY) {
				this->addToContains((*it));
			}
		}
	}

	if(room != NULL)
		room->addToContains(this);
}

Item::~Item(){}

void Item::update() const
{
	cout << "Item name: " << getName() << endl;
	cout << description << endl;
	cout << "This item is a " << getItemTypeString() << " and is placed at " << getRoom()->getName() << " room." << endl;
}

ItemType Item::getItemType() const
{
	return item_type;
}

string& Item::getItemTypeString() const
{
	string result = "";

	switch (getItemType())
	{
	case GAMEBOY:
		result = "GAMEBOY";
		break;
	case LAPTOP:
		result = "LAPTOP";
		break;
	case SKETCHBOOK:
		result = "SKETCHBOOK";
		break;
	case BOX:
		result = "BOX";
		break;
	case KEY:
		result = "KEY";
		break;
	}

	return result;
}

Room* Item::getRoom() const
{
	return room;
}

bool Item::isContainedInBox() const
{
	return containedInBox;
}