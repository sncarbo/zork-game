#ifndef __ITEM__
#define __ITEM__

#include <string>
#include "entity.h"
#include "room.h"

using namespace std;

enum ItemType 
{
	KEY,
	BOX,
	PAPER
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, ItemType item_type);
	~Item();

	void Update() const;

private:
	ItemType item_type;
};

#endif // !__ITEM__