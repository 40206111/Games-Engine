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
		return sqrt(length2(v));
	}

	//return the squared length of a vector
	template <typename T> double length2(const sf::Vector2<T> &v)
	{
		return v.x * v.x + v.y * v.y;
	}

	//Normalize vector
	template <typename T> sf::Vector2<T> normalize(const sf::Vector2<T> &v)
	{
		sf::Vector2 vector;
		double l = length(v);	//find length

		if (l != 0)	//avoid dividing by 0
		{
			v.x /= l;
			v.y /= l;
		}

		return vector;
	}

	//
}
