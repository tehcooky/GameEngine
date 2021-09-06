#include "room.h"

room::room(int a, std::string b)
{
	roomNumber = a;
	roomDesc = b;
}

room::~room()
{

}

//getters
int room::getRoom()
{
	return roomNumber;
}
std::string room::getRoomDesc()
{
	return roomDesc;
}

//setters
void room::setRoom(int a)
{
	roomNumber = a;
}
void room::setRoomDesc(std::string a)
{
	roomDesc = a;
}
void room::addObjectToRoom(drawableObject *a)
{
	gameObjects.push_back(a);
}