#ifndef __ITEM__
#define __ITEM__

#include <string>
#include "entity.h"

class Room;

using namespace std;

enum ItemType 
{
	GAMEBOY,
	LAPTOP,
	SKETCHBOOK,
	BOX,
	KEY
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, ItemType item_type, Room* room);
	~Item();

	void update() const;
	
	Room* getRoom() const;
	ItemType getItemType() const;
	string& getItemTypeString() const;

private:
	ItemType item_type;
	Room* room;
};

#endif // !__ITEM__
