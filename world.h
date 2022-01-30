#ifndef __WORLD__
#define __WORLD__

#include <string>
#include <list>

using namespace std;

class Entity;
class Player;

class World
{
public:
	World();
	~World();
private:
	list<Entity*> entities;
	Player* player;
};

#endif // __WORLD__
