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

	virtual void update() const;

	virtual bool go(const string& direction);
	virtual bool take(const string& item, const string& subitem);
	virtual bool drop(const string& item);
	virtual void inventory() const;
	virtual bool unlock();

	bool isAlive() const;
	Room* getLocation() const;

private:
	bool alive;
	Room* location; // Room where the creature is.
};

#endif