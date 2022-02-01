#include <iostream>
#include "entity.h"
#include "exit.h"
#include "player.h"
#include "item.h"
#include "creature.h"
#include "room.h"

Entity::Entity(const char* name, const char* description) :
	name(name), description(description)
{
	type = ENTITY;
}

Entity::~Entity(){}

void Entity::update() const
{
	cout << name << endl;
	cout << description << endl;
}

Entity* Entity::findByEntityType(EntityType type) const
{
	Entity* result = NULL;

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend() && result == NULL; ++it)
	{
		if ((*it)->getType() == type)
		{
			result = (*it);
		}
	}

	return result;
}

string Entity::getName() const
{
	return name;
}

string Entity::getDescription() const
{
	return description;
}

EntityType Entity::getType() const
{
	return type;
}

Entity* Entity::findByName(const string& name) const
{
	Entity* result = NULL;

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend() && result == NULL; ++it)
	{
		if (_stricmp((*it)->getName().c_str(), name.c_str()) == 0)
		{
			result = (*it);
		}
	}

	return result;
}

void Entity::addToContains(Entity* element)
{
	if (contains.size() != contains.max_size())
		contains.push_back(element);
}

void Entity::removeFromContains(Entity* element)
{
	if (!contains.empty())
		contains.remove(element);
}

list<Entity*> Entity::findAllByEntityType(EntityType type) const
{
	list<Entity*> result;

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
	{
		if ((*it)->getType() == type)
		{

			result.push_back(*it);
		}
	}

	return result;
}

list<Entity*> Entity::getContains() const
{
	return contains;
}