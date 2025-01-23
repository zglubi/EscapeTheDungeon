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
	manager->start(dungeonMap.getMap());
	manager->createPlayer();

	vector<char> patern =
	{
		'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U',
		'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
		'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D',
		'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L',
	};

	vector<char> patern1 =
	{
		'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U',
		'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
		'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U',
		'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
		'D', 'D', 'D', 'D', 'D', 'D', 'D',
		'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L',
		'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D',
		'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L',
	};

	vector<char> patern2 =
	{
		'U', 'U', 'U', 'U', 'U', 'U',
		'L', 'L', 'L', 'L', 'L',
		'D', 'D', 'D', 'D', 'D', 'D',
		'R', 'R', 'R', 'R', 'R',
	};

	manager->createPatrolling(Vector2f(825, 800), 100, 100, patern);

	manager->createPatrolling(Vector2f(500, 900), 100, 100, patern1);

	manager->createPatrolling(Vector2f(300, 450), 100, 100, patern2);

	manager->createChaser(Vector2f(1300, 200), 100, 200);

	Clock clock;
	float deltaTime;
	bool isRunning = true;

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		while (isRunning)
		{

			manager->isPlayerAlive(isRunning);

			deltaTime = clock.restart().asSeconds();

			Event event;

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
			}


			manager->update(deltaTime, dungeonMap.getMap());
			manager->collisions();


			// Drawage toi meme tu sais
			window.clear();
			dungeonMap.draw(window);
			manager->draw(window);
			window.display();

			manager->winCheck(isRunning);
		}

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		manager->winScreen(window);
	}


	return 0;
}