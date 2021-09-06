#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <SFML/Graphics.hpp>

class drawableObject
{
public:
	//default constructor
	drawableObject();
	//Constructor and Destructor
	drawableObject(sf::String, float, float, float, float, int);
	~drawableObject();

	//create an object label, posx, poxy, type
	drawableObject(sf::String, float, float, sf::String);

	//creating a ui element
	drawableObject(sf::String, float, float);

	//set variables
	void setX(float);
	void setY(float);
	void setSizeX(float);
	void setSizeY(float);
	void setSprite(sf::Texture);
	void setSpritePosition(float, float);
	void setSolid(int);
	void setObjectName(sf::String);
	void setLabel(sf::Font, sf::String);
	void setType(sf::String);
	void setActionable(int);

	//get variables
	float getX();
	float getY();
	float getSizeX();
	float getSizeY();
	sf::Sprite getSprite();
	int getSolid();
	sf::String getObjectName();
	sf::Text getLabel();
	sf::String getType();
	int getActionable();


	//functions
	//Write something here to do with being able to set actions for a specific action an object may have
	//for instance in some kind of list where you may be able to have a variable amount of actions
	//and be able to execute each one to deal with the object internally.
private:

protected:
	float x, y, sizeX, sizeY, solid;
	int actionableObjectFlag;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::String objectName;
	sf::Text label;
	sf::Font characterFont;
	sf::String type;
};
#endif