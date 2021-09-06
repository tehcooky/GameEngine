#ifndef PLAYER_H
#define PLAYER_H

#include "drawableObject.h"
#include <iostream>

class player: public drawableObject
{
public:
	player(sf::String, float, float, float, float, int);
	~player();
	player(sf::String name, float, float, int, int);

	void setCoin(int);
	void setHealth(int);

	int getCoin();
	int getHealth();

private:
	int health;
	int coin;
};

#endif