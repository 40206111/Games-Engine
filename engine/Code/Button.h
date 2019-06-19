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
	void Update();
	bool GetButtonDown();
	bool GetButtonHeld();
	bool GetButtonReleased();
	float GetAnalogueButtonValue() { return 100; }	//to be overriden

protected:
	enum ButtonState { ButtonDown, ButtonHeld, ButtonReleased, Other}; //clear words for button states
	std::bitset<4> buttonState;
};


//child of button used for analogue input
class AnologueButton : Button
{
public:
private:
};