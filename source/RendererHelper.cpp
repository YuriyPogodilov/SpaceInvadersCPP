#include <vector>
#include "RendererHelper.h"

void RendererHelper::DrawPoint(SDL_Renderer* renderer, Point point, Color color) {
	SDL_Color oldColor;
	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, static_cast<int>(point.x), static_cast<int>(point.y));
	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

void RendererHelper::DrawLine(SDL_Renderer* renderer, Point point1, Point point2, Color color) {
	SDL_Color oldColor;
	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer, static_cast<int>(point1.x), static_cast<int>(point1.y), static_cast<int>(point2.x), static_cast<int>(point2.y));
	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

void RendererHelper::DrawRect(SDL_Renderer* renderer, Point leftTop, Point rightBottom, Color color) {
	SDL_Color oldColor;
	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
	SDL_FRect rect;
	rect.x = leftTop.x;
	rect.y = leftTop.y;
	rect.w = rightBottom.x - leftTop.x;
	rect.h = rightBottom.y - leftTop.y;
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRectF(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

void RendererHelper::DrawCircle(SDL_Renderer *renderer, Point center, int radius, Color color) {
	SDL_Color oldColor;
	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	auto drawCircle = [renderer](int xc, int yc, int x, int y) {
		SDL_RenderDrawPoint(renderer, xc+x, yc+y);
		SDL_RenderDrawPoint(renderer, xc-x, yc+y);
		SDL_RenderDrawPoint(renderer, xc+x, yc-y);
		SDL_RenderDrawPoint(renderer, xc-x, yc-y);
		SDL_RenderDrawPoint(renderer, xc+y, yc+x);
		SDL_RenderDrawPoint(renderer, xc-y, yc+x);
		SDL_RenderDrawPoint(renderer, xc+y, yc-x);
		SDL_RenderDrawPoint(renderer, xc-y, yc-x);
	};

	int x = 0, y = radius;
	int d = 3 - 2 * radius;
	drawCircle(center.x, center.y, x, y);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(center.x, center.y, x, y);
	}

	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}
