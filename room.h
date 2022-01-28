#ifndef __ROOM__
#define __ROOM__

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();
	void Update() const;
};

#endif