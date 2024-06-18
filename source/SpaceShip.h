#pragma once
#include "GameObject.h"

class SpaceShip : public GameObject {
public:
	SpaceShip();

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

protected:
	float speed{ 100.f };
};
