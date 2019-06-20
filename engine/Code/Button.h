#pragma once
#include <SFML/graphics.hpp>
#include <bitset>
#include <ostream>

//Class defining a button
class Button
{
public:
	enum ControlType { Keyboard, Mouse, Controller, None = -1 };
	// VARIABLES //
	ControlType controller = None;
	int button = -1;
	int controlerId;

	// CONSTRUCTORS //
	Button(int but, ControlType cont) { controller = cont; button = but; };
	Button(int but, ControlType cont, int contId) { controller = cont; button = but; controlerId = contId; };
	~Button() = default;

	// METHODS //
	friend std::ostream& operator<<(std::ostream& stream, const Button& b);
	void Update(const double &dt);
	bool GetButtonDown() { return buttonState.test(ButtonDown); }
	bool GetButtonHeld(){ return buttonState.test(ButtonHeld); }
	bool GetButtonReleased(){ return buttonState.test(ButtonReleased); }
	float GetHeldTime() { return heldTime; }
	float GetAnalogueButtonValue() { return 100; }	//to be overriden

protected:
	enum ButtonState { ButtonDown, ButtonHeld, ButtonReleased, Other}; //clear words for button states
	std::bitset<4> buttonState;
	float heldTime = 0;
};


//child of button used for analogue input
class AnologueButton : Button
{
public:
	sf::Joystick::Axis axis;
	int direction = 1;
private:
	float value = 0;
};