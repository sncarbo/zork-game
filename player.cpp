#include <iostream>
#include "creature.h"
#include "player.h"
#include "exit.h"
#include "room.h"
#include "item.h"
#include "entity.h"

Player::Player(const char* name, const char* description, Room* location) :
	Creature(name, description, location)
{
	type = PLAYER;

	if (location != NULL)
		location->addToContains(this);
}

Player::~Player() {}

void Player::update() const
{
	cout << "Player name: " << getName() << endl;
	cout << description << endl;
	cout << "This player is at " << getLocation()->getName() << " room." << endl;
	cout << "The room has this items: ";

	list<Entity*> locationContains = getLocation()->getContains();

	for (list<Entity*>::const_iterator it = locationContains.begin(); it != locationContains.cend(); ++it)
	{
		if((*it)->getType() == ITEM)
			cout << (*it)->getName() << " ";
	}

	cout << endl;

	cout << "The room has this creatures: ";

	for (list<Entity*>::const_iterator it = locationContains.begin(); it != locationContains.cend(); ++it)
	{
		if ((*it)->getType() == CREATURE)
			cout << (*it)->getName() << " ";
	}

	cout << endl;

	cout << "The room has this exits: ";

	for (list<Entity*>::const_iterator it = locationContains.begin(); it != locationContains.cend(); ++it)
	{
		if ((*it)->getType() == EXIT)
			cout << (*it)->getName() << " ";
	}

	cout << endl;

	this->inventory();
}


void Player::inventory() const
{
	cout << "This player have this items: ";

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it) {
		cout << (*it)->getName() << " ";
	}

	cout << endl;
}
