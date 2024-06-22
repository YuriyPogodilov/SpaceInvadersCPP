#include "InputHandlerSystem.h"
#include <SDL.h>
#include "components/InputComponent.h"

InputHandlerSystem* InputHandlerSystem::instance = nullptr;

void InputHandlerSystem::ProcessInput(uint32_t type, SDL_Keycode keycode) {
	auto processKeyEvent = [type, keycode](InputComponent* listener) {
		if (listener == nullptr) {
			return false;
		}
		if (type == SDL_KEYDOWN) {
			return listener->KeyDown(keycode);
		} else if (type == SDL_KEYUP) {
			return listener->KeyUp(keycode);
		}
		return false;
	};

	for (auto& listener : InputListeners) {
		if (processKeyEvent(listener)) {
			return;
		}
	}
}

void InputHandlerSystem::AddListener(InputComponent* listener) {
	InputListeners.push_back(listener);
}

void InputHandlerSystem::RemoveListener(InputComponent* listener) {
	InputListeners.remove(listener);
}

void InputHandlerSystem::Shutdown() {
	delete instance;
	instance = nullptr;
}

InputHandlerSystem &InputHandlerSystem::GetInstance() {
	if (instance == nullptr) {
		instance = new InputHandlerSystem();
	}
	return *instance;
}
