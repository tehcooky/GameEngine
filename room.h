#pragma once

#include <iostream>
using namespace std;
#include "drawableObject.h"
#include "player.h"

//in here should be everything you need to know about the room you're in

class room
{
public:
	//constructing a room // room number, desc one word
	room(int, std::string);
	~room();

	//getters
	int getRoom();
	std::string getRoomDesc();

	//setters
	void setRoom(int);
	void setRoomDesc(std::string);

	//add objects
	void addObjectToRoom(drawableObject *);
private:
	int roomNumber;
	std::string roomDesc;
	std::vector<drawableObject*> gameObjects;

};