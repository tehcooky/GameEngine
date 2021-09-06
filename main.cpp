#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space!");
	
	//start a game
	game theGame;
	//initialise objects
	theGame.initialise();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		theGame.update(window);
        window.display();
    }

    return 0;
}