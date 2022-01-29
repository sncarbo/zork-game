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
	//Exit* bedroom_exit
	Room* living_room = new Room("Living room", "Okey, you managed to escape, you are now in the living room. However, the main gate is closed.");
	//Exit* living_room_exit
	Room* freedom = new Room("Freedom!", "Congratulations! You managed to escape from that 'monster house'. Now, you are ready to face the world. Or not...");


}