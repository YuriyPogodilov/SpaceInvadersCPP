#pragma once

#include "GameComponent.h"
#include <SDL.h>
#include <functional>

class InputComponent : public IGameComponent {
public:
	InputComponent();
	~InputComponent() override;

	virtual bool KeyDown(SDL_Keycode keycode) final;
	virtual bool KeyUp(SDL_Keycode keycode) final;

protected:
	std::function<bool(SDL_Keycode keycode)> KeyDownHandler{nullptr};
	std::function<bool(SDL_Keycode keycode)> KeyUpHandler{nullptr};
};
