#include "player.h"
#include <SFML/Graphics.hpp>

player::player(sf::String name, float a, float b, float c, float d, int e)
{
	//what is initialised when the object is created
	x=a;
	y=b;
	sizeX=c;
	sizeY=d;
	solid = e;
	objectName = name;
}
player::~player()
{

}
//new way to initiate player
player::player(sf::String name, float a, float b, int c, int d)
{
	//what is initialised when the player is created
	x = a;
	y = b;
	sizeX = 32.0f;
	sizeY = 32.0f;
	solid = 1;
	objectName = name;
	type = "player";

	health = c;
	coin = d;
}
//set
void player::setCoin(int a)
{
	coin=a;
}
void player::setHealth(int a)
{
	health=a;
}

//get
int player::getCoin()
{
	return coin;
}
int player::getHealth()
{
	return health;
}