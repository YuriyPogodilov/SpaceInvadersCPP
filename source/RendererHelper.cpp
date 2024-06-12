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
