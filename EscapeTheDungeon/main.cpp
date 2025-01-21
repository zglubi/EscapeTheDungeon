#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Patrolling.h"
#include "Chaser.h"
#include "EntityManager.h"
#include "Map.h"
using namespace sf;
using namespace std;

RenderWindow window(VideoMode(1440, 1080), "Escape the Dungeon");

EntityManager* manager = EntityManager::getInstance();

Map dungeonMap;

int main()
{
	Texture pText;
	if (!pText.loadFromFile("p.png"))
	{
		cout << "Texture introuvable";
		return -1;
	}

	manager->createPlayer();

	vector<char> patern = { 'U', 'U', 'U', 'R',
		'R', 'D', 'D', 'D', 'L', 'L'};

	manager->createPatrolling(100, 50, patern);

	manager->createChaser(100, 50);

	Clock clock;
	float deltaTime;

	window.setFramerateLimit(60);
	manager->start();
	while (window.isOpen())
	{
		if (!manager->isPlayerAlive())
			window.close();
		
		deltaTime = clock.restart().asSeconds();
		
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}


		manager->update(deltaTime);
		manager->collisions();


		// Drawage toi meme tu sais
		window.clear();
		dungeonMap.draw(window);
		manager->draw(window);
		window.display();
	}
	
	
	return 0;
}