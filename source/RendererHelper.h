#pragma once

#include "SDL.h"
#include "Vector.h"
#include "Color.h"

class RendererHelper {
public:
	static void DrawPoint(SDL_Renderer* renderer, Point point, Color color);
	static void DrawLine(SDL_Renderer* renderer, Point point1, Point point2, Color color);
	static void DrawRect(SDL_Renderer* renderer, Point leftTop, Point rightBottom, Color color);
};
