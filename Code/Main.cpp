#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Component.h"
#include "Renederer.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "TEST");	//make test window

	Entity* butt = new Entity();
	std::shared_ptr<ShapeComponent> boobs = butt->AddComponent<ShapeComponent>();
	boobs->setShape<CircleShape>(12.0f);

	//Run game loop
	while (window.isOpen())
	{
		window.clear();	//clear window

		Event e;
		//pole events
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)	//close window
			{
				window.close();
			}
		}

		//get keyboard input
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.display();	//display window
	}

	return 0;
}