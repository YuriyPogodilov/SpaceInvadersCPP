#pragma once
#include "GameObject.h"
#include "components/InputComponent.h"

class SpaceShip : public GameObject, InputComponent {
public:
	SpaceShip();

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

protected:
	float speed{ 300.f };
	Vector2 velocity { Vector2::ZERO };
};
