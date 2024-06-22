#include "SpaceShip.h"
#include "RendererHelper.h"

SpaceShip::SpaceShip() : GameObject("SpaceShip"), InputComponent() {
	size = { 100.f, 100.f };
	bShowOutline = true;

	KeyDownHandler = [this](SDL_Keycode keycode)-> bool {
		switch (keycode) {
			case SDLK_a:
				velocity = Vector2::LEFT;
				break;
			case SDLK_d:
				velocity = Vector2::RIGHT;
				break;
			default: break;
		}
		return false;
	};

	KeyUpHandler = [this](SDL_Keycode keycode) -> bool {
		if (keycode == SDLK_a ||
			keycode == SDLK_d)
		{
			velocity = Vector2::ZERO;
		}
		return false;
	};
}

void SpaceShip::Update(float deltaTime) {
	GameObject::Update(deltaTime);

	if (fabsf(velocity.x) < std::numeric_limits<float>::epsilon())
	{
		return;
	}

	position += velocity * speed * deltaTime;
}

void SpaceShip::Draw(SDL_Renderer *renderer) {
	GameObject::Draw(renderer);
}
