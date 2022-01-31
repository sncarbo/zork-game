#ifndef __EXIT__
#define __EXIT__

#include "entity.h"
#include <string>

class Room;

enum DirectionType {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, Room* source_room, Room* next_room, DirectionType direction);
	~Exit();

	void update() const;

	bool isLocked() const;
	void unlock();
	Room* getSourceRoom() const;
	Room* getNextRoom() const;
	DirectionType getDirection() const;
	string& getDirectionString() const;

private:
	bool locked;
	DirectionType direction;
	Room* source_room;
	Room* next_room;
};

#endif // !__EXIT__
