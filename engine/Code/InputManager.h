#pragma once
#include <map>
#include <SFML/graphics.hpp>
#include "Button.h"

struct ControlSystem
{
	std::map<int, std::pair<Button, Button>> controls;
	int controllerID = 0;
	InputManager::ControlType controlScheme = InputManager::ControlType::None;
	static unsigned int nextKey;
	unsigned int mapKey = 0;

	ControlSystem() { mapKey = nextKey; nextKey++; }
};

class InputManager
{
public:
	//Controller enum
	enum ControlType { Keyboard, Mouse, Controller, None = -1 };
	//PS4 enum
	enum PS4 { SQUARE, X, O, TRIANGLE, L1, R1, L2, R2, SELECT, START, LEFTA, RIGHTA, PS, TOUCH, NONE = -1 };
	//Dpad Enum
	enum Dir { Up, Down, Left, Right };

	// VARIABLES //
	//Controls to string
	static const std::map<PS4, std::string> ps4Controls;
	static const std::map<sf::Keyboard::Key, std::string> keyboardControls;
	//Controls
	std::vector<ControlSystem> controlSchemes;
	ControlSystem *current;

	// CONSTRUCTORS //
	InputManager() {}
	~InputManager() = default;

	// METHODS //
	void Update(const double &dt);
	void Remap(std::string scheme, unsigned int control, int rebindTo, ControlType type, bool secondary);
	ControlSystem CreateControlScheme(ControlType cs);
};