#include "drawableObject.h"
#include <SFML/Graphics.hpp>

drawableObject::drawableObject()
{
}
//constructor and decontructor
drawableObject::drawableObject(sf::String name, float a, float b, float c, float d, int e)
{
	//what is initialised when the object is created
	x=a;
	y=b;
	sizeX=c;
	sizeY=d;
	solid = e;
	objectName = name;

}
drawableObject::~drawableObject()
{
}
//set up object player
drawableObject::drawableObject(sf::String name, float a, float b, sf::String c)
{
	//what is initialised when the object is created
	x = a;
	y = b;
	objectName = name;
	type = c;
	solid = 0;
	if (c == "player")
	{
		//22 Y for player
		sizeX = 32.0f;
		sizeY = 22.0f;
		solid = 1;
		actionableObjectFlag = 0;
	}
	if (c == "girlProt")
	{
		sizeX = 32.0f;
		sizeY = 32.0f;
		solid = 1;
		actionableObjectFlag = 1;
	}
	if (c == "crate")
	{
		sizeX = 32.0f;
		sizeY = 32.0f;
		solid = 1;
		objectName = "crate";
		actionableObjectFlag = 1;
	}
	if (c == "pellet")
	{
		sizeX = 32.0f;
		sizeY = 32.0f;
		solid = 0;
		objectName = "pellet";
		actionableObjectFlag = 0;
	}
	if (c == "background")
	{
		sizeX = 800.0f;
		sizeY = 600.0f;
		solid = 0;
		objectName = "background";
		actionableObjectFlag = 0;
	}
}
drawableObject::drawableObject(sf::String name, float a, float b)
{
	x = a;
	y = b;
	solid = 0;
	objectName = name;

	if (name == "health")
	{
		sizeX = 15;
		sizeY = 15;
	}
}

//setting variables
void drawableObject::setX(float a)
{
	x=a;
}
void drawableObject::setY(float a)
{
	y=a;
}
void drawableObject::setSizeX(float a)
{
	sizeX=a;
}
void drawableObject::setSizeY(float a)
{
	sizeY=a;
}
void drawableObject::setSprite(sf::Texture a)
{
	texture = a;
	sprite.setPosition(x, y);
	sprite.setTexture(texture);
}
void drawableObject::setSpritePosition(float x, float y)
{
	sprite.setPosition(x, y);
}
void drawableObject::setSolid(int a)
{
	solid = a;
}
void drawableObject::setObjectName(sf::String a)
{
	objectName = a;
}
void drawableObject::setLabel(sf::Font a, sf::String b)
{
	characterFont = a;
	label.setString(b);
	label.setCharacterSize(12);
	//label.setColor(sf::Color::White);
	label.setFont(characterFont);
}
void drawableObject::setType(sf::String a)
{
	type = a;
}
void drawableObject::setActionable(int a)
{
	actionableObjectFlag = a;
}


//get variables
float drawableObject::getX()
{
	return x;
}
float drawableObject::getY()
{
	return y;
}
float drawableObject::getSizeX()
{
	return sizeX;
}
float drawableObject::getSizeY()
{
	return sizeY;
}
sf::Sprite drawableObject::getSprite()
{
	return sprite;
}
int drawableObject::getSolid()
{
	return solid;
}
sf::String drawableObject::getObjectName()
{
	return objectName;
}
sf::Text drawableObject::getLabel()
{
	return label;
}
sf::String drawableObject::getType()
{
	return type;
}
int drawableObject::getActionable()
{
	return actionableObjectFlag;
}

