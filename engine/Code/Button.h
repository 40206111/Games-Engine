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
	ControlType controller = ControlType::None;
	int button = -1;

	// CONSTRUCTORS //
	Button(int but, ControlType cont) { controller = cont; button = but; }
	Button() {}
	~Button() = default;

	// METHODS //
	friend std::ostream& operator<<(std::ostream& stream, const Button& b);
	virtual void Update(const double &dt, int controlerId);
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
	AnologueButton(sf::Joystick::Axis ax, int dir) { direction = dir; axis = ax;};
	AnologueButton(sf::Joystick::Axis ax, int dir, float dz) { direction = dir; axis = ax; deadZone = dz; };
	AnologueButton(sf::Joystick::Axis ax) { axis = ax;};
	AnologueButton(sf::Joystick::Axis ax, float dz) { axis = ax; deadZone = dz; };
	~AnologueButton() = default;

	// METHODS //
	friend std::ostream& operator<<(std::ostream& stream, const Button& b);
	void Update(const double &dt, int controlerId) override;
	float GetAnalogueButtonValue() override { return (value * direction > 0)? value : 0; }
private:
	float value = 0.0f;
};