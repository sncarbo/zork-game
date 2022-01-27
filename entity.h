#ifndef __ENTITY__
#define __ENTITY__

using namespace std;

#include <string>
#include <list>

enum EntityType {
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity {
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Update() const;

private:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;

};

#endif