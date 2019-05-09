#pragma once
#include <SFML/System.hpp>
#include <cmath>

namespace math
{
	//vecture2ul definition
	typedef sf::Vector2<size_t> Vector2ul;

	//return the length of a vector
	template <typename T> double length(const sf::Vector2<T> &v)
	{
		return sqrt(v.x * v.x + v.y + v.y);
	}



}
