#pragma once
#include "Maths.h"
#include <vector>
#include <memory>

class Component;

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
	virtual void Update(double deltaTime);
	virtual void Render();

	void SetPosition(const sf::Vector2f &pos);
	sf::Vector2f GetPosition() { return pos; }

	template <typename T, typename... Targs>
	std::shared_ptr<T> AddComponent(Targs... params)
	{
		static_assert(std::is_base_of<Component, T>::value, "Type given must inherit from Component");
		std::shared_ptr<T> componentToAdd(std::make_shared<T>(this, params...));
		components.push_back(componentToAdd);
		return componentToAdd;
	}
};