#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Patrolling.h"
#include "Chaser.h"
#include "EntityManager.h"
#include "Map.h"
#include "Button.h"
using namespace sf;
using namespace std;

RenderWindow window(VideoMode(1440, 1080), "Escape the Dungeon");

EntityManager* manager = EntityManager::getInstance();

Map dungeonMap;

void menu(Button buttonPlay, Button buttonExit)
{
	Event event;
	Texture menuTexture;
	if (!menuTexture.loadFromFile("Assets/Background/menu.png"))
	{
		cout << "menuTexture introuvable" << endl;
	}
	Sprite menuSprite(menuTexture);
	menuSprite.setScale(2.95, 2.95);

	buttonPlay.setPosition(Vector2f(600, 450));
	buttonExit.setPosition(Vector2f(600, 600));

	bool menu = true;

	while (menu)
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				menu = false;
			}

			if (buttonExit.isClicked(window))
			{
				window.close();
				menu = false;
			}

			if (buttonPlay.isClicked(window))
			{
				return;
			}
		}

		window.clear();
		window.draw(menuSprite);
		buttonPlay.draw(window);
		buttonExit.draw(window);
		window.display();
	}
}

int main()
{
	manager->start(dungeonMap.getMap());
	manager->createPlayer();

	Texture buttonExitTexture;
	if (!buttonExitTexture.loadFromFile("Assets/Buttons/exit.png"))
	{
		cout << "buttonExitTexture introuvable" << endl;
	}

	Texture buttonReplayTexture;
	if (!buttonReplayTexture.loadFromFile("Assets/Buttons/replay.png"))
	{
		cout << "buttonReplayTexture introuvable" << endl;
	}

	Texture buttonPlayTexture;
	if (!buttonPlayTexture.loadFromFile("Assets/Buttons/play.png"))
	{
		cout << "buttonPlayTexture introuvable" << endl;
	}

	Button buttonExit(buttonExitTexture, Vector2f(600, 800));

	Button buttonReplay(buttonReplayTexture, Vector2f(600, 650));

	Button buttonPlay(buttonPlayTexture, Vector2f(600, 650));


	menu(buttonPlay, buttonExit);



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

	manager->createNinja(Vector2f(625, 200), 100, 800);

	manager->createNinja(Vector2f(925, 800), 100, 800);

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
			if (buttonExit.isClicked(window))
			{
				window.close();
			}
			if (buttonReplay.isClicked(window))
			{
				isRunning = true;
				manager->clear();
				manager->start(dungeonMap.getMap());
				manager->createPlayer();

				manager->createPatrolling(Vector2f(825, 800), 100, 100, patern);

				manager->createPatrolling(Vector2f(500, 900), 100, 100, patern1);

				manager->createPatrolling(Vector2f(300, 450), 100, 100, patern2);

				manager->createChaser(Vector2f(1300, 200), 100, 200);

				manager->createNinja(Vector2f(625, 200), 100, 800);

				manager->createNinja(Vector2f(925, 800), 100, 800);

				clock.restart();
			}
		}

		window.clear();
		manager->winScreen(window);
		buttonExit.draw(window);
		buttonReplay.draw(window);
		window.display();
	}


	return 0;
}