#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include <iostream>
#include <map>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "TEST");	//make test window
	InputManager inMan = InputManager();
	ControlSystem* cs = inMan.CreateControlScheme(ControlSystem::ControlType::Controller);
	ControlSystem* cs2 = inMan.CreateControlScheme(ControlSystem::ControlType::Keyboard);
	Button b1(0, Button::ControlType::Controller);
	cs->controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b1)));
	b1.button = 1;
	cs->controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b1)));
	b1.button = 2;
	cs->controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b1)));
	b1.button = 3;
	cs->controls.insert(std::pair<unsigned int, std::pair<Button, Button>>(0, std::pair<Button, Button>(b1, b1)));


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
			if (e.type == sf::Event::JoystickButtonPressed && inMan.current->controlScheme != ControlSystem::ControlType::Controller)
			{
				std::cout << "Control System changed to controller" << std::endl;
				inMan.current = inMan.controlSchemes[0];
				inMan.current->controllerID = (int)Joystick::getIdentification;
			}
			if (e.type == sf::Event::KeyPressed || e.type == sf::Event::MouseButtonPressed && (inMan.current->controlScheme != ControlSystem::ControlType::Keyboard || inMan.current->controlScheme != ControlSystem::ControlType::Mouse))
			{
				std::cout << "Control System changed to keyboard and Mouse" << std::endl;
				inMan.current = inMan.controlSchemes[1];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (inMan.GetButtonDown(i))
				std::cout << "button down" << std::endl;

			if (inMan.GetButtonDown(i))
				std::cout << "button Held" << std::endl;

			if (inMan.GetButtonReleased(i))
				std::cout << "button Released" << std::endl;

			if (inMan.GetButtonHeldTime(i) > 1)
				std::cout << inMan.GetButtonHeldTime(i) << std::endl;
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