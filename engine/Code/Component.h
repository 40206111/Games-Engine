#pragma once
#include "Entity.h"


class Component
{
protected:
	Entity *const Parent;
	explicit Component(Entity *const p);

public:
	Component() = delete;
	virtual ~Component();
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
};