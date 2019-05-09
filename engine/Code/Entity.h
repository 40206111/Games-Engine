#pragma once
#include "Component.h"
#include <vector>
#include <memory>

class Entity
{
protected:
	std::vector<std::shared_ptr<Component>> components;
};