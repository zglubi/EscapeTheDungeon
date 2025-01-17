#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
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

	Player player(pText);


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

		// Drawage toi meme tu sais
		window.clear();
		player.draw(window);
		window.display();
	}
	
	
	return 0;
}