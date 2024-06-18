#include "Game.h"
#include "GameScene.h"

Game::Game(std::string_view title) :
	gameTitle(title)
{
}

bool Game::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
		return false;
	}

	SDL_DisplayMode DisplayMode;
	SDL_GetCurrentDisplayMode(0, &DisplayMode);
	windowWidth = DisplayMode.w;
	windowHeight = DisplayMode.h;

	window = SDL_CreateWindow(
			gameTitle.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			windowWidth,
			windowHeight,
			SDL_WINDOW_BORDERLESS
	);
	if (!window) {
		fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

	bIsRunning = true;

	// Create game
	scene = std::make_shared<GameScene>("mapScene");
	scene->Init();
	scene->PrintHierarchy();

	return true;
}

void Game::Loop() {
	ProcessInput();
	Update();
	Draw();
}

void Game::Shutdown() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Game::isRunning() const {
	return bIsRunning;
}

void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				bIsRunning = false;
				break;
			case SDL_KEYDOWN: {
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						bIsRunning = false;
						break;
				}
			}
		}
	}
}

void Game::Draw() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	scene->Draw(renderer);

	SDL_RenderPresent(renderer);
}

void Game::Update() {
	if (isFPSLocked) {
		uint32_t time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - previousFrameTime);
		if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
			SDL_Delay(time_to_wait);
		}
	}

	deltaTime = static_cast<float>(SDL_GetTicks() - previousFrameTime) / 1000.f;
	previousFrameTime = SDL_GetTicks();

	scene->Update(deltaTime);
}

void Game::Stop() {
	bIsRunning = false;
}
