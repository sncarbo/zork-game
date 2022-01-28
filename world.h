#ifndef __WORLD__
#define __WORLD__

#include <string>
#include <list>

class World
{
public:
	World();
	~World();
private:
	list<Entities*> entities;
	Player* player;
};

#endif // __WORLD__
