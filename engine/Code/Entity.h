#pragma once
#include "Component.h"
#include "Maths.h"
#include <vector>
#include <memory>

class Entity
{
protected:
	std::vector<std::shared_ptr<Component>> components;
	sf::Vector2f pos;
	float rotation;
	bool isAlive;
	bool isVisible;
	bool toBeDeleted;
public:
	Entity();
	virtual ~Entity();
	virtual void Update();
	virtual void Render();
};