#pragma once

#include <SDL3/SDL.h>
#include <glm/glm.hpp>

struct RectangleShape {
	SDL_Color Color = { 0, 0, 0, 255 };
	glm::vec2 Size = glm::vec2(0, 0);
	SDL_Color OutlineColor = { 0, 0, 0, 255 };
	int32_t OutlineThickness = 0;
};