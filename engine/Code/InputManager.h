#pragma once
#include <map>
#include <SFML/graphics.hpp>
#include "Button.h"

struct ControlSystem
{
	//Controller enum
	enum ControlType { Keyboard, Mouse, Controller, None = -1 };
	std::map<int, std::pair<Button, Button>> controls = std::map<int, std::pair<Button, Button>>();
	int controllerID = 0;
	ControlType controlScheme = ControlType::None;
	//static unsigned int nextKey;
	//unsigned int mapKey = 0;

	//ControlSystem() { mapKey = nextKey; nextKey++; }
};

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
	std::vector<ControlSystem*> controlSchemes;
	ControlSystem *current;

	// CONSTRUCTORS //
	InputManager() {}
	~InputManager() = default;

	// METHODS //
	void Update(const double &dt);
	void Remap(std::string scheme, unsigned int control, int rebindTo, ControlSystem::ControlType type, bool secondary);
	ControlSystem* CreateControlScheme(ControlSystem::ControlType cs);
	bool GetButtonDown(int control);
	bool GetButtonHeld(int control);
	bool GetButtonReleased(int control);
	float GetButtonValue(int control);
	float GetButtonHeldTime(int control);
};