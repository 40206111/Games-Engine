#pragma once
#include <map>
#include <SFML/graphics.hpp>

struct InputSystem
{
	enum ControlType {Keyboard, PS4, XBox};
	std::map<unsigned int, int> controls;
	ControlType controller = Keyboard;
};

class InputManager
{
public:
	//PS4 enum
	enum PS4 {SQUARE, X, O, TRIANGLE, L1, R1, L2, R2, SELECT, START, LEFTA, RIGHTA, PS, TOUCH, NONE = -1};
	//Dpad Enum
	enum Dir{ Up, Down, Left, Right};

	//Controls to string
	static const std::map<PS4, std::string> ps4Controls;
	static const std::map<sf::Keyboard::Key, std::string> keyboardControls;

	//constructor
	InputManager() {}
};