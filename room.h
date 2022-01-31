#ifndef __ROOM__
#define __ROOM__

#include <string>
#include <list>
#include "entity.h"

class Exit;

using namespace std;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

	void update() const;

	Exit* getExit() const;

};

#endif