#include <iostream>
#include "room.h"
#include "item.h"
#include "exit.h"

Item::Item(const char* name, const char* description, ItemType item_type, Room* room) :
Entity(name, description), item_type(item_type), room(room)
{
	type = ITEM;
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