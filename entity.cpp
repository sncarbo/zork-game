#include <iostream>
#include "entity.h"

Entity::Entity(const char* name, const char* description, Entity* parent = NULL) :
	name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->container.push_back(this);
}
//
Entity::~Entity(){}
//
void Entity::Update() const
{
	cout << name << endl;
	cout << description << endl;
}
