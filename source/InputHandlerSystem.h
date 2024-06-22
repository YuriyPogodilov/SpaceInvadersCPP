#pragma once

#include <list>
#include <memory>
#include <SDL_keycode.h>

class InputComponent;

class InputHandlerSystem {
	InputHandlerSystem() = default;
	~InputHandlerSystem() = default;

public:
	static InputHandlerSystem& GetInstance();
	static void Shutdown();

	void ProcessInput(uint32_t type, SDL_Keycode keycode);

	void AddListener(InputComponent* listener);
	void RemoveListener(InputComponent* listener);

protected:
	std::list<InputComponent*> InputListeners;

	static InputHandlerSystem* instance;
};
