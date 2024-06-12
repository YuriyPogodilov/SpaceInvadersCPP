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

	bool isFPSLocked{true};
	const float FPS_LOCK{60.f};
	const uint32_t FRAME_TARGET_TIME{ static_cast<uint32_t>(1000.f / FPS_LOCK)};
	uint32_t previousFrameTime{0};
	float deltaTime{0.f};

	SDL_Window* window{nullptr};
	SDL_Renderer* renderer{nullptr};

	int windowWidth{1920};
	int windowHeight{1080};
};
