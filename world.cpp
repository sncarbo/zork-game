#include <iostream>
#include "entity.h"
#include "creature.h"
#include "item.h"
#include "exit.h"
#include "room.h"
#include "player.h"
#include "world.h"

World::World() {

	//ROOMS AND EXITS
	Room* bedroom = new Room("Bedroom", "Your parents punished you, so your trapped in your bedroom. Is there any way out?");
	Room* living_room = new Room("Living room", "Okey, you managed to escape, you are now in the living room. However, the main gate is closed.");
	Room* freedom = new Room("Freedom!", "Congratulations! You managed to escape from that 'monster house'. Now, you are ready to face the world. Or not...");
	Exit* bedroom_exit = new Exit("Bedroom exit", "This exit connects the bedroom and the living room", bedroom, living_room, SOUTH);
	Exit* living_room_exit = new Exit("Living room exit", "This exit connects the living room and FREEDOM", living_room, freedom, EAST);

	entities.push_back(bedroom);
	entities.push_back(living_room);
	entities.push_back(freedom);
	entities.push_back(bedroom_exit);
	entities.push_back(living_room_exit);

	Creature* mom = new Creature("Mom", "It's your mom. She is asleep.", living_room);

	entities.push_back(mom);

	Item* gameboy = new Item("Gameboy", "It's your gameboy. Your favourite thing ever.", GAMEBOY, bedroom);
	Item* sketchbook = new Item("Sketchbook", "It's your sketchbook. You recently draw Buzz Lightyear", SKETCHBOOK, bedroom);
	Item* box_bedroom = new Item("Bedroom box", "It's just a common box.", BOX, bedroom);
	Item* key_bedroom = new Item("Bedroom key", "It's the bedroom key... WAIT, YOU CAN LEAVE NOW.", KEY, bedroom);
	Item* laptop = new Item("Laptom", "It's your mom's laptop.", LAPTOP, living_room);
	Item* box_living_room = new Item("Living room box", "It's just another common box.", BOX, living_room);
	Item* key_living_room = new Item("Living room key", "KEY TO FREEDOM.", KEY, living_room);

	entities.push_back(gameboy);
	entities.push_back(sketchbook);
	entities.push_back(box_bedroom);
	entities.push_back(key_bedroom);
	entities.push_back(laptop);
	entities.push_back(box_living_room);
	entities.push_back(key_living_room);

	Player* player = new Player("Player", "It's you and only you.", bedroom);
	this->player = player;

	entities.push_back(player);
}

World::~World()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete* it;

	entities.clear();
}

bool strcmp(const string& a, const string& b)
{
	return (_stricmp(a.c_str(), b.c_str()) == 0);
}

bool World::command(vector<string>& commands)
{
	bool result = false;

	if(strcmp("go", commands.at(0)))
		result = player->go(commands.at(1));
	else if (strcmp("take", commands.at(0)))
	{
		if(commands.size() > 2)
			result = player->take(commands.at(1), commands.at(2));
		else
			result = player->take(commands.at(1), "");
	}
	else if (strcmp("drop", commands.at(0)))
		result = player->drop(commands.at(1));
	else if (strcmp("inventory", commands.at(0))) {
		player->inventory();
		result = true;
	}
	else if (strcmp("unlock", commands.at(0)))
		result = player->unlock();

	return result;
}

