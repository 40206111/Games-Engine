#pragma once
#include <map>
#include <SFML/graphics.hpp>
#include "Button.h"


class InputManager
{
public:
	//PS4 enum
	enum PS4 { SQUARE, X, O, TRIANGLE, L1, R1, L2, R2, SELECT, START, LEFTA, RIGHTA, PS, TOUCH, NONE = -1 };
	//Dpad Enum
	enum Dir { Up, Down, Left, Right };

	// VARIABLES //
	//Controls to string
	static const std::map<PS4, std::string> ps4Controls;
	static const std::map<sf::Keyboard::Key, std::string> keyboardControls;
	//Controls
	std::map <std::string, std::map<unsigned int, std::pair<Button, Button>>> controlSchemes;
	std::map<unsigned int, std::pair<Button, Button>> *current;

	// CONSTRUCTORS //
	//constructor
	InputManager() {}
	~InputManager() = default;

	// METHODS //
	void Update(const double &dt);
	void Remap(std::string scheme, unsigned int control, int rebindTo, Button::ControlType type, bool secondary);
};