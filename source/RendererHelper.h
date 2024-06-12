#pragma once

#include "SDL.h"
#include "Vector.h"

class RendererHelper {
public:
	static void DrawPoint(SDL_Renderer* renderer, Point point, SDL_Color color);
	static void DrawLine(SDL_Renderer* renderer, Point point1, Point point2, SDL_Color color);
	static void DrawRect(SDL_Renderer* renderer, Point leftTop, Point rightBottom, SDL_Color color);
};
