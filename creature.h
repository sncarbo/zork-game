#ifndef __CREATURE__
#define __CREATURE__

#include <string>
#include <vector>
#include "entity.h"
#include "room.h"
#include "item.h"

using namespace std;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

	virtual void Update() const;
	virtual void stats() const;

	virtual bool go(const string& direction);
	virtual bool take(const string& item);
	virtual bool drop(const string& item);
	virtual void inventory() const;
	virtual bool unlock(const string& direction);

	bool isAlive() const;
	Room* getRoom() const;
	Item* getItemTaken() const;

private:
	bool alive;
	Item* item_taken;
};

#endif