#include "Game.h"
#include <iostream>
#include "RendererHelper.h"

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

	float w = static_cast<float>(windowWidth);
	float h = static_cast<float>(windowHeight);

	RendererHelper::DrawPoint(renderer,{ w / 2.f, 200.f }, Color(0xff0000ff));
	RendererHelper::DrawLine(renderer,
							 { 0.f, 0.f },
							 { w, h },
							 Color(0x00ff00ff));
	RendererHelper::DrawRect(renderer,
							 { w / 4.f, h / 4.f },
							 { w * 3.f / 4.f, h * 3.f / 4.f },
							 Color(0x0000ffff));

	RendererHelper::DrawCircle(renderer, { w / 2.f, 200.f }, 100.f, Color(0xffff00ff));

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
}
