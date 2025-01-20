#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Patrolling.h"
#include "Chaser.h"
using namespace sf;
using namespace std;



RenderWindow window(VideoMode(1440, 1080), "Escape the Dungeon");


int main()
{
	Texture pText;
	if (!pText.loadFromFile("p.png"))
	{
		cout << "Texture introuvable";
		return -1;
	}

	Player player;

	vector<char> patern = { 'U', 'U', 'U', 'R',
		'R', 'D', 'D', 'D', 'L', 'L'};

	Patrolling pat(100, 50, patern);
	pat.getSprite().setPosition(Vector2f(600, 500));

	Chaser chase(100, 50);


	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		player.update(0.016f);
		pat.update(0.016f);
		chase.moveUpdate(player);
		chase.update(0.016f);

		// Drawage toi meme tu sais
		window.clear();
		player.draw(window);
		pat.draw(window);
		chase.draw(window);
		window.display();
	}
	
	
	return 0;
}