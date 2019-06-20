#include "Button.h"

std::ostream & operator<<(std::ostream & stream, const Button & b)
{
	// TODO: make this output correctly
	return stream << "temp";
}

void Button::Update(const double &dt)
{

	//Reset button states
	if (buttonState.test(ButtonDown))
	{
		buttonState.reset(ButtonDown);
	}
	if (buttonState.test(ButtonReleased))
	{
		buttonState.reset(ButtonReleased);
	}
	
	//check if button has been pressed
	if ((controller == Controller && sf::Joystick::isButtonPressed(controlerId, button)) ||
		(controller == Keyboard && sf::Keyboard::isKeyPressed((sf::Keyboard::Key)button)) ||
		(controller == Mouse && sf::Mouse::isButtonPressed((sf::Mouse::Button)button)))
	{
		//set button states
		if (!buttonState.test(ButtonHeld))
		{
			buttonState.set(ButtonDown);
			buttonState.set(ButtonHeld);
		}
		heldTime += (float)dt;
	}
	else if (buttonState.test(ButtonHeld))
	{
		//button has been released
		buttonState.reset(ButtonHeld);
		buttonState.set(ButtonReleased);
		heldTime = 0;
	}
}
