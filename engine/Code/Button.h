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
	Button(int but, ControlType cont) { controller = cont; button = but; }
	Button(int but, ControlType cont, int contId) { controller = cont; button = but; controlerId = contId; }
	Button() {}
	~Button() = default;

	// METHODS //
	friend std::ostream& operator<<(std::ostream& stream, const Button& b);
	virtual void Update(const double &dt);
	bool GetButtonDown() { return buttonState.test(ButtonDown); }
	bool GetButtonHeld(){ return buttonState.test(ButtonHeld); }
	bool GetButtonReleased(){ return buttonState.test(ButtonReleased); }
	float GetHeldTime() { return heldTime; }
	virtual float GetAnalogueButtonValue() { if (GetButtonHeld()) return 100; else return 0; }	//to be overriden

protected:
	enum ButtonState { ButtonDown, ButtonHeld, ButtonReleased, Other}; //clear words for button states
	std::bitset<4> buttonState;
	float heldTime = 0;
};


//child of button used for analogue input
class AnologueButton : public Button
{
public:
	// VARIABLES //
	sf::Joystick::Axis axis;
	int direction = 1;
	float deadZone = 50.0f;

	// CONSTRUCTORS //
	AnologueButton(sf::Joystick::Axis ax, int dir, int contId) { direction = dir; axis = ax; controlerId = contId; };
	AnologueButton(sf::Joystick::Axis ax, int dir, int contId, float dz) { direction = dir; axis = ax; controlerId = contId; deadZone = dz; };
	AnologueButton(sf::Joystick::Axis ax, int contId) { axis = ax; controlerId = contId; };
	AnologueButton(sf::Joystick::Axis ax, int contId, float dz) { axis = ax; controlerId = contId; deadZone = dz; };
	~AnologueButton() = default;

	// METHODS //
	friend std::ostream& operator<<(std::ostream& stream, const Button& b);
	void Update(const double &dt) override;
	float GetAnalogueButtonValue() override { return (value * direction > 0)? value : 0; }
private:
	float value = 0.0f;
};