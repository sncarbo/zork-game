#ifndef __PLAYER__
#define __PLAYER__

#include "creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void update() const;

	void inventory() const;
};

#endif