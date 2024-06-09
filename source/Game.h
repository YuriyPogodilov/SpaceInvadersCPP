#pragma once

#include <SDL.h>
#include <string>

class Game {
public:
	explicit Game(std::string_view title);
	~Game() = default;

	bool Init();
	void Loop();
	void Shutdown();

	[[nodiscard]] bool isRunning() const;

private:
	void ProcessInput();
	void Draw();
	void Update();

private:
	std::string gameTitle;
	bool bIsRunning{false};

	SDL_Window* window{nullptr};
	SDL_Renderer* renderer{nullptr};

	int windowWidth{1920};
	int windowHeight{1080};
};
