#include "Renederer.h"
#include <queue>


using namespace std;
using namespace sf;

static queue<const Drawable *> sprites;
static RenderWindow *renderWindow;

void Renderer::Initilise(sf::RenderWindow &rw)
{
	renderWindow = &rw;
}

sf::RenderWindow & Renderer::GetWindow()
{
	return *renderWindow;
}

void Renderer::Shutdown()
{
	while (!sprites.empty)
	{
		sprites.pop();
	}
}

void Renderer::Update(const double &){}

void Renderer::Queue(const sf::Drawable * sprite)
{
	sprites.push(sprite);
}

void Renderer::Render()
{
	if (renderWindow == nullptr)
	{
		throw("No render window set");
	}

	while (!sprites.empty)
	{
		renderWindow->draw(*sprites.front());
		sprites.pop();
	}

}
