#include "Component.h"
#include "Renederer.h"

using namespace std;
using namespace sf;

ShapeComponent::ShapeComponent(Entity * p) : Component(p), shape(make_shared<CircleShape>()) {}

void ShapeComponent::Update(double deltaTime)
{
	shape->setPosition(parent->GetPosition());
}

void ShapeComponent::Render()
{
	Renderer::Queue(shape.get());
}

sf::Shape & ShapeComponent::getShape() const
{
	return *shape;
}

Component::Component(Entity * const p) : parent(p){}

Component::~Component()
{
}
