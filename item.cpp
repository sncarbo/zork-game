#include <iostream>
#include "item.h"


Item::Item(const char* name, const char* description, Entity* parent, ItemType item_type) :
	Entity(name, description, parent), item_type(item_type)
{
	type = ITEM;
}
//-----------------------------------------------------------
Item::~Item(){}
//-----------------------------------------------------------
