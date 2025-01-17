#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;



RenderWindow window(VideoMode(1440, 1080), "Escape the Dungeon");


int main()
{

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
	}
	
	
	
	
	
	return 0;
}