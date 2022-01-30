#ifndef __EXIT__
#define __EXIT__

#include "entity.h"
#include <string>

class Room;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* next_room_name, const char* description, Room* actual_room, Room* next_room);
	~Exit();

	void Update() const;

	bool isLocked() const;
	void unlock();
	string& getNextRoomName();
	Room* getNextRoom() const;
	Entity* getKey() const;

private:
	bool locked;
	string next_room_name;
	Room* next_room;
	Entity* key;
};

#endif // !__EXIT__
