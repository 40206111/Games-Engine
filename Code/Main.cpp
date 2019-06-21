#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include <iostream>
#include <map>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "TEST");	//make test window
	InputManager inMan = InputManager();
	ControlSystem cs = inMan.CreateControlScheme(InputManager::ControlType::Controller);
	ControlSystem cs = inMan.CreateControlScheme(InputManager::ControlType::Keyboard);
	Button b1(0, Button::ControlType::Controller);
	Button b2(0, Button::ControlType::Controller);
	cs.controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b2)));
	b1.button = 1;
	cs.controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b2)));
	b1.button = 2;
	cs.controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b2)));
	b1.button = 3;
	cs.controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b2)));


	static sf::Clock clock;

	//Run game loop
	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		window.clear();	//clear window

		Event e;
		//pole events
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)	//close window
			{
				window.close();
			}
			if (e.type == sf::Event::JoystickButtonPressed)
			{
				std::cout << "Control System changed to controller" << std::endl;
				inMan.current = &inMan.controlSchemes[0];
				inMan.current->controllerID = (int)Joystick::getIdentification;
			}
			if (e.type == sf::Event::KeyPressed || e.type == sf::Event::MouseButtonPressed)
			{
				std::cout << "Control System changed to keyboard and Mouse" << std::endl;
				inMan.current = &inMan.controlSchemes[1];
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