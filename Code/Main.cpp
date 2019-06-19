#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include <iostream>
#include <map>
#include "Button.h" //shouldn't be needed when input manager is set up

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "TEST");	//make test window
	InputManager inMan = InputManager();

	Button b((int)sf::Keyboard::E, Button::ControlType::Keyboard);

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

			//if (e.type == Event::JoystickButtonPressed) //test PS4
			//{
			//	std::cout << inMan.ps4Controls.at((InputManager::PS4)e.joystickButton.button) << std::endl;
			//}


			//if (e.type == Event::KeyPressed) //test	keyboard keys in map
			//{
			//	if (inMan.keyboardControls.count((Keyboard::Key)e.key.code) > 0)
			//	{
			//		std::cout << inMan.keyboardControls.at((Keyboard::Key)e.key.code) << std::endl;
			//	}
			//}

			//if (e.type == Event::MouseButtonPressed)
			//{
			//	std::cout << e.mouseButton.button << std::endl;
			//}
		}
		b.Update();

		if (b.GetButtonDown())
		{
			std::cout << "Button Down" << std::endl;
		}

		if (b.GetButtonHeld())
		{
			std::cout << "Button Held" << std::endl;
		}

		if (b.GetButtonReleased())
		{
			std::cout << "Button Released" << std::endl;
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