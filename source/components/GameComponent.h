#pragma once

#include <memory>

class GameObject;

class IGameComponent {
public:
	IGameComponent() = default;
	virtual ~IGameComponent() = default;
};
