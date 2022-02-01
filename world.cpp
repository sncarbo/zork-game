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
	Room* gameboy_store = new Room("Gameboy Store", "Where gameboys are made.");
	Room* key_store = new Room("Key Store", "Where keys are made.");
	Room* sketchbook_store = new Room("Sketchbook Store", "Where sketchbooks are made.");
	Exit* bedroom_exit = new Exit("Bedroom exit", "Where gameboys are made.", bedroom, living_room, SOUTH);
	Exit* living_room_exit = new Exit("Living room exit", "This exit connects the living room and FREEDOM", living_room, freedom, EAST);
	Exit* gameboy_store_door = new Exit("Gameboy Store Door", "The door to the Gameboy Store", freedom, gameboy_store, EAST);
	Exit* key_store_door = new Exit("Key Store Door", "The door to the Key Store", gameboy_store, key_store, NORTH);
	Exit* sketchbook_store_door = new Exit("Sketchbook Store Door", "The door to the Sketchbook Store", key_store, sketchbook_store, WEST);
	bedroom->setExit(bedroom_exit);
	living_room->setExit(living_room_exit);
	freedom->setExit(gameboy_store_door);
	gameboy_store->setExit(key_store_door);
	key_store->setExit(sketchbook_store_door);

	entities.push_back(bedroom);
	entities.push_back(living_room);
	entities.push_back(freedom);
	entities.push_back(gameboy_store);
	entities.push_back(key_store);
	entities.push_back(sketchbook_store);
	entities.push_back(bedroom_exit);
	entities.push_back(living_room_exit);
	entities.push_back(gameboy_store_door);
	entities.push_back(key_store_door);
	entities.push_back(sketchbook_store_door);

	Creature* mom = new Creature("Mom", "It's your mom. She is asleep.", living_room);

	entities.push_back(mom);

	Item* gameboy = new Item("Gameboy", "It's your gameboy. Your favourite thing ever.", GAMEBOY, bedroom, false);
	Item* sketchbook = new Item("Sketchbook", "It's your sketchbook. You recently draw Buzz Lightyear.", SKETCHBOOK, bedroom, false);
	Item* key_bedroom = new Item("BedroomKey", "It's the bedroom key... WAIT, YOU CAN LEAVE NOW.", KEY, bedroom, true);
	Item* box_bedroom = new Item("BedroomBox", "It's just a common box.", BOX, bedroom, false);
	Item* laptop = new Item("Laptop", "It's your mom's laptop.", LAPTOP, living_room, false);
	Item* key_living_room = new Item("LivingRoomKey", "KEY TO FREEDOM.", KEY, living_room, true);
	Item* box_living_room = new Item("LivingRoomBox", "It's just another common box.", BOX, living_room, false);
	Item* key_gameboy_store = new Item("KeyGameboy", "A gameboy key.", KEY, freedom, false);
	Item* gameboy_color = new Item("GameboyColor", "IT'S A GAMEBOY COLOR.", GAMEBOY, gameboy_store, false);
	Item* gameboy_advance = new Item("GameboyAdvance", "IT'S A GAMEBOY ADVANCE.", GAMEBOY, gameboy_store, false);
	Item* key_key_store = new Item("KeyKey", "A key key.", KEY, gameboy_store, false);
	Item* key1 = new Item("NormalKey1", "A normal key.", KEY, key_store, false);
	Item* key2 = new Item("NormalKey2", "Another normal key.", KEY, key_store, false);
	Item* sketchbook1 = new Item("NormalSketchbook", "A normal sketchbook.", SKETCHBOOK, sketchbook_store, false);

	entities.push_back(gameboy);
	entities.push_back(sketchbook);
	entities.push_back(box_bedroom);
	entities.push_back(key_bedroom);
	entities.push_back(laptop);
	entities.push_back(box_living_room);
	entities.push_back(key_living_room);
	entities.push_back(gameboy_color);
	entities.push_back(gameboy_advance);
	entities.push_back(key1);
	entities.push_back(key2);
	entities.push_back(sketchbook1);

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
	if (commands.size() == 1)
	{
		if (strcmp("update", commands.at(0))) {
			player->update();
			result = true;
		}
		else if (strcmp("inventory", commands.at(0))) {
			player->inventory();
			result = true;
		}
		else if (strcmp("unlock", commands.at(0)))
			result = player->unlock();
	}
	else if (commands.size() == 2)
	{
		if (strcmp("go", commands.at(0)))
			result = player->go(commands.at(1));
		else if (strcmp("take", commands.at(0)))
		{
			result = player->take(commands.at(1), "");
		}
		else if (strcmp("drop", commands.at(0)))
		{
			result = player->drop(commands.at(1), "");
		}
	}
	else if (commands.size() == 3)
	{
		if (strcmp("take", commands.at(0)))
		{
			result = player->take(commands.at(1), commands.at(2));
		}
		else if (strcmp("drop", commands.at(0)))
		{
			result = player->drop(commands.at(1), commands.at(2));
		}
	}

	return result;
}

