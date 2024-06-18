#pragma once

#include "SDL.h"
#include "Vector.h"
#include "Color.h"

class RendererHelper {
public:
	static void DrawPoint(SDL_Renderer* renderer, Point point, Color color = Color::White);
	static void DrawLine(SDL_Renderer* renderer, Point point1, Point point2, Color color = Color::White);
	static void DrawRect(SDL_Renderer* renderer, Point leftTop, Point rightBottom, Color color = Color::White);

	/**
	* @brief Draw Circle using Bresenham’s circle drawing algorithm
	*/
	static void DrawCircle(SDL_Renderer* renderer, Point center, int radius, Color color = Color::White);
};
