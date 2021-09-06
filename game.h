#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "drawableObject.h"
#include "player.h"
#include "room.h"

class game
{
public:
	//constructor and deconstructor
	game();
	~game();

	//set up objects for the game
	void initialise();
	//game loop
	void update(sf::RenderWindow&);

	//use this to add to the list of textures
	void addTexture(sf::Texture);

	//use this to save game objects created
	void addObject(drawableObject);

	//use this to get a list of gameObjects
	void printObjectsToConsole();

	//work on a function that takes a texture as an arguement and returns a texture with masking applied
	void fixTextures(vector<sf::Texture>&);

	//simplified make an object and put a pointer to it on a vector
	void createObject(std::string, float, float, std::string);
	void createPlayer(std::string, float, float, int, int);
	void createUIElement(std::string, float, float);

	//key listener stuff
	void keyListener();
	void checkDrawableObjectCollision(std::string);
	bool doCollision(int, int, int, int, std::string);
	drawableObject * doCollisionObject(int, int, int, int, std::string);

	//set the backing level sprite here?
	void setBackground(sf::Texture);

	//extra actions you can perform on objects
	void destroyObject(int);

	//draw the ui
	void drawUI(sf::RenderWindow&);
private:
	//pointer to an object you for collision
	drawableObject *collided;
	std::vector<sf::Texture> gameTextures;
	std::vector<drawableObject> gameObjects;
	bool collision;
	drawableObject *collisionObject;
	std::vector<drawableObject*> gameObjectPointers;
	std::vector<drawableObject*> backgroundPointers;
	std::vector<player*> players;
	std::vector<drawableObject*> uiElements;
	std::vector<room*> rooms;
	drawableObject background;


};

#endif