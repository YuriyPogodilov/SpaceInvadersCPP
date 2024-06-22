#include "InputComponent.h"
#include "../InputHandlerSystem.h"

InputComponent::InputComponent() {
	InputHandlerSystem::GetInstance().AddListener(this);
}

InputComponent::~InputComponent() {
	InputHandlerSystem::GetInstance().RemoveListener(this);
}

bool InputComponent::KeyDown(SDL_Keycode keyCode) {
	if (KeyDownHandler) {
		return KeyDownHandler(keyCode);
	}
	return false;
}

bool InputComponent::KeyUp(SDL_Keycode keyCode) {
	if (KeyUpHandler) {
		return KeyUpHandler(keyCode);
	}
	return false;
}
