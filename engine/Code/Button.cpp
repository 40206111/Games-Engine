#include "Button.h"

std::ostream & operator<<(std::ostream & stream, const Button & b)
{
	// TODO: make this output correctly
	return stream << "temp";
}

void Button::Update()
{
}

bool Button::GetButtonDown()
{
	return false;
}

bool Button::GetButtonHeld()
{
	return false;
}

bool Button::GetButtonReleased()
{
	return false;
}
