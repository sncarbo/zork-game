#ifndef __CREATURE__
#define __CREATURE__

#include <string>
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

	virtual bool go(const vector<string>& args);
	virtual bool take(const vector<string>& args);
	virtual bool drop(const vector<string>& args);
	virtual bool inventory() const;
	virtual bool unlock(const vector<string>& args);

private:
	bool alive;
	Item* item_taken;
};

#endif