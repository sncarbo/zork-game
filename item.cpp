#include <iostream>
#include "room.h"
#include "item.h"
#include "exit.h"

Item::Item(const char* name, const char* description, Entity* parent, ItemType item_type) :
Entity(name, description, parent), item_type(item_type)
{
	type = ITEM;
}
//-----------------------------------------------------------
Item::~Item(){}
//-----------------------------------------------------------
ItemType Item::getItemType() const
{
	return item_type;
}
//-----------------------------------------------------------
string& Item::getItemTypeString() const
{
	string result = "";

	switch (getItemType())
	{
	case PAPER:
		result = "PAPER";
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