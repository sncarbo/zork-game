#include <iostream>
#include "creature.h"
#include "player.h"
#include "exit.h"
#include "room.h"
#include "item.h"

Player::Player(const char* name, const char* description, Room* location) :
	Creature(name, description, location)
{
	type = PLAYER;
}

Player::~Player() {}

void Player::update() const
{
	cout << "Player name: " << getName() << endl;
	cout << description << endl;
	cout << "This player is at " << getLocation()->getName() << " room." << endl;
}


void Player::inventory() const
{
	cout << "This player have this items: ";

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it) {
		cout << (*it)->getName() << " ";
	}

	cout << endl;
}
