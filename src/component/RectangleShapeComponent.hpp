#pragma  once

#include <glm/glm.hpp>
#include <SDL.h>

struct RectangleShapeComponent
{
	SDL_Color Color = { 0, 0, 0, 255 };
	glm::vec2 Size = glm::vec2();
	SDL_Color OutlineColor = { 0, 0, 0, 255 };
	int32_t OutlineThickness = 0;
};