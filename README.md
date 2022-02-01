# Escape Room Zork
###### **Author**: Santiago Carbó García
###### **Link to my repository**: https://github.com/santiagocarbo89/Zork
#### **What is 'Escape Room Zork'?**

'Escape Room Zork' is a conversational game developed in C++. It's a text adventure based in the popular game 'Zork' of the late 1970s.

#### **Zork Manual**

There are 6 main commands: *go* (to move between rooms, if they are unlocked), *take* (to possess items), *drop* (to unown items), *unlock* (to unseal doors), *inventory* (it lets you know what you hace in possession) and *update* (it tells you information about the items, room, exits and creatures).To finish the game you have to type *quit*.</br></br>
You have to use the commands this way:</br></br>

```
inventory               // It tells you what items you have
update                  // It tells you information about the items, room, exits and creatures. Also displays inventory
go [direction]          // Example: "go NORTH". You need to guess the direction where the exit it. BUT BEFORE you need to unlock the door with a key.
take [item]             // Example: "take Gameboy".
take [box] [item]       // Example: "take BedroomBox BedroomKey".
drop [item]             // Example: "drop Gameboy".
drop [box] [item]       // Example: "drop BedroomBox BedroomKey".
unlock                  // If you are in possession of a key, type 'unlock' to unseal the door to the next room.
quit                    // To finish the game
```
You need to know the directions you can go (typed UPPERCASE):

```
NORTH
SOUTH
EAST
WEST
```

You also need to know the object names for taking or dropping an item:

```
Gameboy
Sketchbook
BedroomKey
BedroomBox
Laptop
LivingRoomKey
LivingRoomBox
KeyGameboy
GameboyColor
GameboyAdvance
KeyKey
NormalKey1
NormalKey2
NormalSketchbook
```

#### **Features**
* 6 connected rooms.
* Items in the rooms that can be picked up.
* Being able to drop items (in or outside the box).
* Items can be placed inside other items (you can place items in the box).
* Extra feature: exits that can be closed and only open with keys.
