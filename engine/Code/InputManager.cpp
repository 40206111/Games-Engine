#include "InputManager.h"
#include <utility>
#include <cmath>

using namespace std;

/*
PS4 button codes
0 - square
1 - x
2 - o
3 - triangle
4 - L1
5 - R1
6 - L2
7 - R2
8 - select
9 - start
10 - left analogue down
11 - right analogue down
12 - PS button
13 - touch pad down
X Axis - Left Analogue -100 left, 100 right, 0 center
Y Axis - Left Analogue -100 up, 100 down, 0 center
Z Axis - Right Analogue -100 left, 100 right, 0 center
R Axis - Right Analogue -100 up, 100 down, 0 center
PovX Axis - D-pad -100 left, 100 right, 0 none
PovY Axis - D-pad -100 down, 100 up, 0 none
V Axis - L2 -100 not pressed, 100 fully pressed
U Axis - R2 -100 not pressed, 100 fully pressed
*/

///INPUT MANAGER CLASS///

//Keyboard controls to string
const std::map<sf::Keyboard::Key, std::string> InputManager::keyboardControls = {
	{ sf::Keyboard::LShift, "LEFT SHIFT" },
{ sf::Keyboard::RShift, "RIGHT SHIFT" },
{ sf::Keyboard::LControl, "LEFT CONTROL" },
{ sf::Keyboard::RControl, "RIGHT CONTROL" },
{ sf::Keyboard::LAlt, "LEFT ALT" },
{ sf::Keyboard::RAlt, "RIGHT ALT" },
{ sf::Keyboard::Tab, "TAB" },
{ sf::Keyboard::Return, "ENTER" },
{ sf::Keyboard::BackSpace, "BACKSPACE" },
{ sf::Keyboard::Space, "SPACE" },
{ sf::Keyboard::F1, "F1" },
{ sf::Keyboard::F2, "F2" },
{ sf::Keyboard::F3, "F3" },
{ sf::Keyboard::F4, "F4" },
{ sf::Keyboard::F5, "F5" },
{ sf::Keyboard::F6, "F6" },
{ sf::Keyboard::F7, "F7" },
{ sf::Keyboard::F8, "F8" },
{ sf::Keyboard::F9, "F9" },
{ sf::Keyboard::F10, "F10" },
{ sf::Keyboard::F11, "F11" },
{ sf::Keyboard::F12, "F12" },
{ sf::Keyboard::Home, "HOME" },
{ sf::Keyboard::End, "END" },
{ sf::Keyboard::PageUp, "PAGE UP" },
{ sf::Keyboard::PageDown, "PAGE DOWN" },
{ sf::Keyboard::Delete, "DEL" },
{ sf::Keyboard::Left, "LEFT ARROW" },
{ sf::Keyboard::Right, "RIGHT ARROW" },
{ sf::Keyboard::Up, "UP ARROW" },
{ sf::Keyboard::Down, "DOWN ARROW" },
{ sf::Keyboard::Menu, "MENU" },
{ sf::Keyboard::Pause, "PAUSE" },
{ sf::Keyboard::Num0, "0" },
{ sf::Keyboard::Num1, "1" },
{ sf::Keyboard::Num2, "2" },
{ sf::Keyboard::Num3, "3" },
{ sf::Keyboard::Num4, "4" },
{ sf::Keyboard::Num5, "5" },
{ sf::Keyboard::Num6, "6" },
{ sf::Keyboard::Num7, "7" },
{ sf::Keyboard::Num8, "8" },
{ sf::Keyboard::Num9, "9" },
{ sf::Keyboard::Numpad0, "NUMPAD 0" },
{ sf::Keyboard::Numpad1, "NUMPAD 1" },
{ sf::Keyboard::Numpad2, "NUMPAD 2" },
{ sf::Keyboard::Numpad3, "NUMPAD 3" },
{ sf::Keyboard::Numpad4, "NUMPAD 4" },
{ sf::Keyboard::Numpad5, "NUMPAD 5" },
{ sf::Keyboard::Numpad6, "NUMPAD 6" },
{ sf::Keyboard::Numpad7, "NUMPAD 7" },
{ sf::Keyboard::Numpad8, "NUMPAD 8" },
{ sf::Keyboard::Numpad9, "NUMPAD 9" },
};

//ps4 controls to string
const std::map<InputManager::PS4, std::string> InputManager::ps4Controls = {
	{ InputManager::SQUARE, "SQUARE" },
	{ InputManager::X, "X" },
	{ InputManager::O, "CIRCLE" },
	{ InputManager::TRIANGLE, "TRIANGLE" },
	{ InputManager::L1, "L1" },
	{ InputManager::R1, "R1" },
	{ InputManager::L2, "L2" },
	{ InputManager::R2, "R2" },
	{ InputManager::SELECT, "SELECT" },
	{ InputManager::START, "START" },
	{ InputManager::LEFTA, "LEFT ANALOGUE IN" },
	{ InputManager::RIGHTA, "RIGHT ANOLOGUE IN" },
	{ InputManager::PS, "PLAY STATION" },
	{ InputManager::TOUCH, "TOUCH PAD" },
};

void InputManager::Update(const double &dt)
{
	int contId = current->controllerID;
	//Update buttons
	for (auto &p : current->controls)
	{
		p.second.first.Update(dt, contId);
		p.second.second.Update(dt, contId);
	}
}

void InputManager::Remap(std::string scheme, unsigned int control, int rebindTo, ControlSystem::ControlType type, bool secondary)
{
}

ControlSystem* InputManager::CreateControlScheme(ControlSystem::ControlType cs)
{
	ControlSystem* newSystem = new ControlSystem();
	newSystem->controlScheme = cs;
	controlSchemes.push_back(newSystem);
	if (current = nullptr) current = newSystem;
	return newSystem;
}

bool InputManager::GetButtonDown(int control)
{
	if (current->controls[control].first.GetButtonDown() || current->controls[control].first.GetButtonDown())
		return true;
	return false;
}

bool InputManager::GetButtonHeld(int control)
{
	if (current->controls[control].first.GetButtonHeld() || current->controls[control].first.GetButtonHeld())
		return true;
	return false;
}

bool InputManager::GetButtonReleased(int control)
{
	if (current->controls[control].first.GetButtonReleased() || current->controls[control].first.GetButtonReleased())
		return true;
	return false;
}

float InputManager::GetButtonValue(int control)
{
	float value1 = current->controls[control].first.GetAnalogueButtonValue();
	float value2 = current->controls[control].second.GetAnalogueButtonValue();

	if (std::abs(value1) > std::abs(value2))
		return value1;
	else
		return value2;
}

float InputManager::GetButtonHeldTime(int control)
{
	float value1 = current->controls[control].first.GetHeldTime();
	float value2 = current->controls[control].second.GetHeldTime();

	if (value1 > value2)
		return value1;
	else
		return value2;
}
