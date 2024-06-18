#include "SpaceShip.h"
#include "RendererHelper.h"

SpaceShip::SpaceShip() : GameObject("SpaceShip") {
	size = { 100.f, 100.f };
	bShowOutline = true;
}

void SpaceShip::Update(float deltaTime) {
	GameObject::Update(deltaTime);
}

void SpaceShip::Draw(SDL_Renderer *renderer) {
	GameObject::Draw(renderer);
}
