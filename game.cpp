#include "game.h"
#include <SFML/Graphics.hpp>

game::game()
{

}
game::~game()
{
}

void game::initialise()
{

	
	/*
	   To add an object, first load in the texture just below, 
	   Then add the initialisastion of that object, in the drawable objects file, under contructor
	   Create the object by calling it with createObject(string label, float xpos, float ypos, string type) in here
	   and assign the texture below

	   Once you have done that, you can simply use the third step to add any number of these objects to the game
	*/


	//font loading
	sf::Font font;
	if (!font.loadFromFile("C:/Users/Tehco/Desktop/NewProjects/NewStuff/NewStuff/fonts/sheeping dogs.ttf"))
	{
		cout<<"Could not load font sheeping dogs"<<endl;
	}
	
	//image used for masking
	sf::Image mask;

	//texture loading :: background to mask is 255,0,255
	collision = false;
	sf::Texture playerTexture;
	if (playerTexture.loadFromFile("player.png"))
	{
		cout<<"player loaded in!"<<endl;
	};
	//add texture to list of textures
	addTexture(playerTexture);

	//texture for character down
	sf::Texture characterDown;
	if (characterDown.loadFromFile("characterDown.png"))
	{
		cout << "characterDown loaded in!" << endl;
	};
	addTexture(characterDown);

	sf::Texture characterRight;
	if (characterRight.loadFromFile("characterRight.png"))
	{
		cout << "characterRight loaded in!" << endl;
	};
	addTexture(characterRight);

	sf::Texture characterLeft;
	if (characterLeft.loadFromFile("characterLeft.png"))
	{
		cout << "characterLeft loaded in!" << endl;
	};
	addTexture(characterLeft);

	sf::Texture characterUp;
	if (characterUp.loadFromFile("characterUp.png"))
	{
		cout << "characterUp loaded in!" << endl;
	};
	addTexture(characterUp);

	sf::Texture crate;
	if (crate.loadFromFile("crate.png"))
	{
		cout<<"crate loaded in!"<<endl;
	};
	addTexture(crate);

	sf::Texture girlProt;
	if (girlProt.loadFromFile("characterGirlDown.png"))
	{
		cout << "Girl Protagonist loaded in!" << endl;
	};
	addTexture(girlProt);
	
	sf::Texture pellet;
	if (pellet.loadFromFile("pellet.png"))
	{
		cout << "Pellets loaded in" << endl;
	}
	addTexture(pellet);

	sf::Texture undergroundStart;
	if (undergroundStart.loadFromFile("undergroundStart.png"))
	{
		cout << "undergroundStart loaded in" << endl;
	}
	addTexture(undergroundStart);

	sf::Texture health;
	if (health.loadFromFile("health.png"))
	{
		cout << "health loaded in" << endl;
	}
	addTexture(health);

	//fix textures
	fixTextures(gameTextures);

	//set initial background for testing
	setBackground(undergroundStart);
	/*
	drawableObject cooky("Cooky", 50.0f, 10.0f, "player");
	drawableObject aCrate("Crate", 120.0f, 100.0f, "crate");
	drawableObject Francesca("Francesca", 400.0f, 400.0f, "girlProt");

	old code for reference
	*/
	//createObject("Cooky", 150.f, 200.f, "player");
	createPlayer("Cooky", 150.f, 200.f, 3, 0);
	createObject("Crate", 350.0f, 200.f, "crate");
	createObject("Crate", 350.0f, 250.f, "crate");
	createObject("Crate", 350.0f, 300.f, "crate");
	createObject("Crate", 350.0f, 350.f, "crate");
	createObject("Crate", 350.0f, 400.f, "crate");
	createObject("Crate", 350.0f, 450.f, "crate");
	createObject("Crate", 350.0f, 500.f, "crate");
	createObject("Pellet", 150.0f, 300.f, "pellet");
	createObject("Pellet", 200.0f, 300.0f, "pellet");
	createObject("Pellet", 150.0f, 350.0f, "pellet");
	createObject("Pellet", 200.0f, 350.0f, "pellet");
	createObject("Big Cam", 400.f, 200.f, "player");
	createObject("Owen", 450.f, 200.f, "player");
	createObject("Brad", 500.0f, 200.f, "player");
	createObject("Health", 20.f, 20.f, "health");
	createObject("Sam", 550.0f, 200.0f, "player");

	//creating background
	createObject("background", 0.0f, 0.0f, "background");
	
	//set their sprites
	int i = 0;
	//gameObjects[0].setSprite(gameTextures[0]);

	for (i = 0; i < gameObjectPointers.size(); i++)
	{
		if (gameObjectPointers[i]->getType() == "player")
		{
			gameObjectPointers[i]->setSprite(gameTextures[1]);
		}
				
		if (gameObjectPointers[i]->getType() == "crate")
		{
			gameObjectPointers[i]->setSprite(gameTextures[5]);
		}
		if (gameObjectPointers[i]->getType() == "girlProt")
		{
			gameObjectPointers[i]->setSprite(gameTextures[6]);
		}
		if (gameObjectPointers[i]->getType() == "pellet")
		{
			gameObjectPointers[i]->setSprite(gameTextures[7]);
		}
		if (gameObjectPointers[i]->getType() == "health")
		{
			gameObjectPointers[i]->setSprite(gameTextures[9]);
		}
	}

	cout<<"Game object pointers is "<<gameObjectPointers.size()<<endl;
	i = 0;
	for(i=0;i<gameObjectPointers.size();i++)
	{
		gameObjectPointers[i]->setLabel(font, gameObjectPointers[i]->getObjectName());
	}
}

void game::update(sf::RenderWindow& window)
{
	//draw game objects
	if (gameObjectPointers.size() > 0)
	{
		window.draw(background.getSprite());
		int i, playerDrawn;
		sf::Text Name;
		i = 0;
		playerDrawn = 0;
		for (i=0; i<gameObjectPointers.size();i++)
		{
			if (gameObjectPointers[i]->getY() > gameObjectPointers[0]->getY() )
			{
				window.draw(gameObjectPointers[0]->getSprite());
				playerDrawn = 1;
			}
			gameObjectPointers[i]->setSpritePosition(gameObjectPointers[i]->getX(), gameObjectPointers[i]->getY());
			Name = gameObjectPointers[i]->getLabel();
			Name.setPosition(gameObjectPointers[i]->getX()-((Name.getCharacterSize()/2)), gameObjectPointers[i]->getY()+ gameObjectPointers[i]->getSizeX());
			window.draw(Name);
			window.draw(gameObjectPointers[i]->getSprite());
			
		}
		if (playerDrawn == 0)
		{
			window.draw(gameObjectPointers[0]->getSprite());
			playerDrawn = 1;
		}
	}
	//draw the ui
	drawUI(window);
	keyListener();
	

}

void game::addTexture(sf::Texture a)
{
	gameTextures.push_back(a);
}
void game::addObject(drawableObject a)
{
	gameObjects.push_back(a);
}
void game::printObjectsToConsole()
{
	if (gameObjects.size() > 0)
	{
		int i = 0;
		for(i=0; i < gameObjects.size() ; i++)
		{
			cout<<"game object: "<<i<<" is at: "<<gameObjects[i].getX()<<", "<<gameObjects[i].getY()<<endl;
		}
	}
}

//fix textures
void game::fixTextures(vector<sf::Texture> &Textures)
{	//set up variables to use within scope
	sf::Image image;
	int i = 0;
	//for each texture within the vector
	for (i = 0; i < Textures.size(); i++)
	{
		//copy the texture to the image
		image = Textures[i].copyToImage();
		//mask that image with magenta
		image.createMaskFromColor(sf::Color::Magenta);
		//reapply the image back to the texture
		Textures[i].loadFromImage(image);
	}
	
}

void game::keyListener()
{
	//cout<<"collision is "<<collision<<endl;
	//if this key is pressed
	int i = 0;
	float movementSpeed;
	movementSpeed = 0.2f;
	collision = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		gameObjectPointers[0]->setSprite(gameTextures[2]);
		//do this
		checkDrawableObjectCollision("right");
		if ((collision == true) && (collisionObject != NULL))
		{
			if (collisionObject->getSolid() == 1)
			{
				if (collisionObject->getType() == "crate")
				{

				}
			}
			if (collisionObject->getType() == "pellet")
			{
				gameObjectPointers[0]->setX(gameObjectPointers[0]->getX() + movementSpeed);
				
				for (i = 0; i < gameObjectPointers.size(); i++)
				{
					if (gameObjectPointers[i] == collisionObject)
					{
						destroyObject(i);
					}
				}
				
				

			}
			
		}
		if (collision == false)
		{
			gameObjectPointers[0]->setX(gameObjectPointers[0]->getX() + movementSpeed);
		}
		//key check
		//cout<<"D is pressed!"<<endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		gameObjectPointers[0]->setSprite(gameTextures[3]);
		//do this
		checkDrawableObjectCollision("left");
		if ((collision == true) && (collisionObject != NULL))
		{
			if (collisionObject->getSolid() == 1)
			{
				if (collisionObject->getType() == "crate")
				{

				}
			}
			if (collisionObject->getType() == "pellet")
			{
				gameObjectPointers[0]->setX(gameObjectPointers[0]->getX() + movementSpeed);

				for (i = 0; i < gameObjectPointers.size(); i++)
				{
					if (gameObjectPointers[i] == collisionObject)
					{
						destroyObject(i);
					}
				}
			}

		}
		if (collision == false)
		{
			gameObjectPointers[0]->setX(gameObjectPointers[0]->getX() - movementSpeed);
		}
		//key check
		//cout<<"A is pressed!"<<endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		gameObjectPointers[0]->setSprite(gameTextures[1]);
		//do this
		checkDrawableObjectCollision("down");
		if ((collision == true) && (collisionObject != NULL))
		{
			if (collisionObject->getSolid() == 1)
			{
				if (collisionObject->getType() == "crate")
				{

				}
			}
			if (collisionObject->getType() == "pellet")
			{
				gameObjectPointers[0]->setX(gameObjectPointers[0]->getX() + movementSpeed);

				for (i = 0; i < gameObjectPointers.size(); i++)
				{
					if (gameObjectPointers[i] == collisionObject)
					{
						destroyObject(i);
					}
				}
			}

		}
		if (collision == false)
		{
			gameObjectPointers[0]->setY(gameObjectPointers[0]->getY() + movementSpeed);
		}
		//key check
		//cout<<"S is pressed!"<<endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		gameObjectPointers[0]->setSprite(gameTextures[4]);
		//do this
		checkDrawableObjectCollision("up");
		if ((collision == true) && (collisionObject != NULL))
		{
			if (collisionObject->getSolid() == 1)
			{
				if (collisionObject->getType() == "crate")
				{

				}
			}
			if (collisionObject->getType() == "pellet")
			{
				gameObjectPointers[0]->setX(gameObjectPointers[0]->getX() + movementSpeed);

				for (i = 0; i < gameObjectPointers.size(); i++)
				{
					if (gameObjectPointers[i] == collisionObject)
					{
						destroyObject(i);
					}
				}
			}

		}
		if (collision == false)
		{
			gameObjectPointers[0]->setY(gameObjectPointers[0]->getY() - movementSpeed);
		}
		//key check
		//cout<<"W is pressed!"<<endl;
	}
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		checkDrawableObjectCollision("up");
		if (collision == true)
		{
			destroyObject(1, gameObjects);
		}

	}
	to use this function comment out name stuff in main loop
	*/
}

void game::createObject(std::string label, float x, float y, std::string texture)
{
	// vector of pointers std::vector<drawableObject*> gameObjectPointers;
	if (label == "background")
	{
		drawableObject* pointer = new drawableObject(label, x, y, texture);
		backgroundPointers.push_back(pointer);
	}
	if (label == "health")
	{
		drawableObject* pointer = new drawableObject(label, x, y, texture);
		uiElements.push_back(pointer);
	}
	else
	{
		drawableObject* pointer = new drawableObject(label, x, y, texture);
		gameObjectPointers.push_back(pointer);
	}
	
	

}

void game::createPlayer(std::string label, float x, float y, int coins, int health)
{
	player* pointer = new player(label, x, y, coins, health);
	gameObjectPointers.push_back(pointer);
	players.push_back(pointer);
}
void game::createUIElement(std::string label, float x, float y)
{
	drawableObject* pointer = new drawableObject(label, x, y);
}
void game::checkDrawableObjectCollision(std::string a)
{
	//declare variables for the box
	//boxXMin etc represent the players values which the collision will be tested against. They
	//have been slightly altered so that its not testing on just a single pixel but a box.
	float boxXMin, boxXMax, boxYMin, boxYMax, boxOffset;
	//boxOffset = 0.0f;
	//if the the string passed contains right
	if (a == "right")
	{
		//for each game object, check collision, probably better Y first as you are moving right
		//check this work

		//Xmin should be left value <-
		//Xmax should be right value ->
		//Ymin should be top value ^
		//Ymax should be bottom value v
		//possbily but takes into account X or Y being less than the object colliding with

		//check that its not empty
		
		if (gameObjectPointers.size() > 0)
		{
			boxXMin = gameObjectPointers[0]->getX();
			boxXMax = gameObjectPointers[0]->getX() + (gameObjectPointers[0]->getSizeX());
			boxYMin = gameObjectPointers[0]->getY() - gameObjectPointers[0]->getSizeY();
			boxYMax = gameObjectPointers[0]->getY() + gameObjectPointers[0]->getSizeY();
			//collision = doCollision(boxXMin, boxXMax, boxYMin, boxYMax, "right");
			collisionObject = doCollisionObject(boxXMin, boxXMax, boxYMin, boxYMax, "right");
		}
		
	}
	if (a == "left")
	{
		//for each game object, check collision, probably better Y first as you are moving right
		//check that its not empty
		if (gameObjectPointers.size() > 0)
		{			
			boxXMin = gameObjectPointers[0]->getX() - (gameObjectPointers[0]->getSizeX());
			boxXMax = gameObjectPointers[0]->getX();
			boxYMin = gameObjectPointers[0]->getY() - (gameObjectPointers[0]->getSizeY());
			boxYMax = gameObjectPointers[0]->getY() + (gameObjectPointers[0]->getSizeY());
			collisionObject = doCollisionObject(boxXMin, boxXMax, boxYMin, boxYMax, "left");
		}
	}
	if (a == "down")
	{
		if (gameObjectPointers.size() > 0)
		{
			boxXMin = gameObjectPointers[0]->getX() - gameObjectPointers[0]->getSizeX();
			boxXMax = gameObjectPointers[0]->getX() + gameObjectPointers[0]->getSizeX();
			boxYMin = gameObjectPointers[0]->getY();
			boxYMax = gameObjectPointers[0]->getY() + (gameObjectPointers[0]->getSizeY());
			collisionObject = doCollisionObject(boxXMin, boxXMax, boxYMin, boxYMax, "down");
		}
	}
	if (a == "up")
	{
		if (gameObjectPointers.size() > 0)
		{
			boxXMin = gameObjectPointers[0]->getX() - gameObjectPointers[0]->getSizeX();
			boxXMax = gameObjectPointers[0]->getX() + gameObjectPointers[0]->getSizeX();
			boxYMin = gameObjectPointers[0]->getY() - (gameObjectPointers[0]->getSizeY());
			boxYMax = gameObjectPointers[0]->getY();
			collisionObject = doCollisionObject(boxXMin, boxXMax, boxYMin, boxYMax, "up");
		}
	}
}
bool game::doCollision(int boxXMin, int boxXMax, int boxYMin, int boxYMax, std::string direction)
{
			int i = 1;
			for (i = 1; i < gameObjectPointers.size(); i++)
			{
				//test if the y is close
				if ((gameObjectPointers[i]->getY() > boxYMin) && (gameObjectPointers[i]->getY() < boxYMax))
				{
					//test the x, to the right of the object
					if ((gameObjectPointers[i]->getX() > boxXMin) && (gameObjectPointers[i]->getX() < boxXMax))
					{
						
						if (gameObjectPointers[i]->getSolid() == 1)
						{
									return true;
						}
																
					}
				}
			}
			return false;
}
//Check for collision and return the object collided with
drawableObject* game::doCollisionObject(int boxXMin, int boxXMax, int boxYMin, int boxYMax, std::string direction)
{
	/////TEST THIS, DOES THIS ACTUALLY RETURN WHAT YOU WANT?
	int i = 1;
	for (i = 1; i < gameObjectPointers.size(); i++)
	{
		//test if the y is close
		if ((gameObjectPointers[i]->getY() > boxYMin) && (gameObjectPointers[i]->getY() < boxYMax))
		{
			//test the x, to the right of the object
			if ((gameObjectPointers[i]->getX() > boxXMin) && (gameObjectPointers[i]->getX() < boxXMax))
			{

				//if (gameObjectPointers[i]->getSolid() == 1)
				//{
					collision = true;
					return gameObjectPointers[i];
				//}
				

			}
		}
		else collision = false;
	}
	return false;
}

//extra actions you can perform on object
void game::destroyObject(int i)
{
	if (gameObjectPointers.size() > 0)
	{
		delete(gameObjectPointers[i]);
		gameObjectPointers.erase(gameObjectPointers.begin()+i);
	}
}

void game::setBackground(sf::Texture a)
{
	background.setSprite(a);
	background.setX(0.0f);
	background.setY(0.0f);
}

void game::drawUI(sf::RenderWindow& window)
{ 
	/*
	//Health
	if (gameObjectPointers.size() > 0)
	{
		if (uiElements.size() > 0)
		{
			int a = players[0]->getHealth();
			int i = 0;
			int uiDrawn = 0;

			float x, y;
			x = 20.0f;
			y = 20.0f;

			if (uiDrawn = 0)
			{
				for (i = a; i > 0; i--)
				{
					cout << "A is "<< a << "I is "<< i << endl;
					window.draw(uiElements[0]->getSprite());
					uiElements[0]->setSpritePosition(uiElements[0]->getX()+32, uiElements[0]->getY());
					uiDrawn = 1;
				}
			}
		}
	}
	*/
}