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

	Entity* findContains(const string& name, EntityType type) const;

	void changeParentTo(Entity* new_parent);
	string getName() const;
	string geDescription() const;
	EntityType getType() const;

protected:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;
	Entity* parent;

};

#endif