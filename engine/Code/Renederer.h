#pragma once
#include <SFML/Graphics.hpp>

namespace Renderer
{
	void Initilise(sf::RenderWindow &);
	sf::RenderWindow &GetWindow();

	void Shutdown();
	void Update(const double &);
	void Queue(const sf::Drawable *sprite);
	void Render();
};