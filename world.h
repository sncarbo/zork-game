#ifndef __WORLD__
#define __WORLD__

#include <string>
#include <list>
#include <vector>

using namespace std;

class Entity;
class Player;

class World
{
public:
	World();
	~World();

	bool command(vector<string>& commands);
private:
	list<Entity*> entities;
	Player* player;
};

#endif // __WORLD__
