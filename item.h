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
	Item(const char* name, const char* description, ItemType item_type, Room* room, bool containedInBox);
	~Item();

	void update() const;
	
	Room* getRoom() const;
	ItemType getItemType() const;
	string& getItemTypeString() const;
	bool isContainedInBox() const;
	void setContainedInBox(bool value);

private:
	ItemType item_type;
	Room* room;
	bool containedInBox;
};

#endif // !__ITEM__
