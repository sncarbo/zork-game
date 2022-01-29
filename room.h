#ifndef __ROOM__
#define __ROOM__

#include <string>
#include <list>
#include "entity.h"
#include "exit.h"
#include "item.h"

using namespace std;

class Room : public Entity
{
public:
	Room(const char* name, const char* next_room_name, const char* description, Room* next_room);
	~Room();

	void Update() const;

	Exit* getExit(const string& direction) const;

};

#endif