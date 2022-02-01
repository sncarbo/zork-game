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
	Entity(const char* name, const char* description);
	virtual ~Entity();

	virtual void update() const;

	Entity* findByEntityType(EntityType type) const;
	Entity* findByName(const string& name) const;
	list<Entity*> findAllByEntityType(EntityType type) const;
	string getName() const;
	string getDescription() const;
	EntityType getType() const;
	void addToContains(Entity* element);
	void removeFromContains(Entity* element);

protected:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;
};

#endif