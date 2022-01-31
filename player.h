#ifndef __PLAYER__
#define __PLAYER__

#include "creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Update() const;

	bool go(const string& direction);
	bool take(const string& item);
	bool drop(const string& item);
	void inventory() const;
	bool unlock(const string& direction);
};

#endif