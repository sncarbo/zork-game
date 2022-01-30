#include <iostream>
#include "entity.h"
#include "exit.h"
#include "player.h"
#include "item.h"
#include "creature.h"
#include "room.h"

Entity::Entity(const char* name, const char* description, Entity* parent = NULL) :
	name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->contains.push_back(this);
}
//-----------------
Entity::~Entity(){}
//-----------------
void Entity::Update() const
{
	cout << name << endl;
	cout << description << endl;
}
//-----------------
Entity* Entity::findContains(const string& name, EntityType type) const
{
	Entity* result = NULL;

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend() && result == NULL; ++it)
	{
		if ((*it)->getType() == type && _stricmp((*it)->getName().c_str(), name.c_str()) == 0)
		{
			switch (type)
			{
				case ENTITY:
					result = (*it);
					break;
				case EXIT:
					result = ((Exit*)*it);
					break;
				case ROOM:
					result = ((Room*)*it);
					break;
				case ITEM:
					result = ((Item*)*it);
					break;
				case CREATURE:
					result = ((Creature*)*it);
					break;
				case PLAYER:
					result = ((Player*)*it);
					break;
			}

			result = ((Exit*)*it);
		}
	}
}
//-----------------
void Entity::changeParentTo(Entity* new_parent)
{
	if (parent != NULL)
		parent->contains.remove(this);

	parent = new_parent;

	if (parent != NULL)
		parent->contains.push_back(this);
}
//-----------------
string Entity::getName() const
{
	return name;
}
//-----------------
string Entity::geDescription() const
{
	return description;
}
//-----------------
EntityType Entity::getType() const
{
	return type;
}