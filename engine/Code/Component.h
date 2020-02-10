#pragma once
#include "Entity.h"
#include <memory>
#include <SFML/Graphics.hpp>


class Component
{
protected:
	Entity *const parent;
	explicit Component(Entity *const p);

public:
	Component() = delete;
	virtual ~Component();
	virtual void Update(double deltaTime) = 0;
	virtual void Render() = 0;
};

class ShapeComponent : public Component
{
protected:
	std::shared_ptr<sf::Shape> shape;
public:
	ShapeComponent() = delete;
	explicit ShapeComponent(Entity *p);

	void Update(double deltaTime) override;
	void Render() override;

	sf::Shape &getShape() const;

	template <typename T, typename... Targs>
	void setShape(Targs... params) 
	{
		shape.reset(new T(params...));
	}
};