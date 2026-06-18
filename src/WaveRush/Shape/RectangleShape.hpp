#pragma once

#include "WaveRush/Core/PCH.hpp"

struct RectangleShape {
	SDL_Color Color = { 0, 0, 0, 255 };
	glm::vec2 Size = glm::vec2(0, 0);
	SDL_Color OutlineColor = { 0, 0, 0, 255 };
	int32_t OutlineThickness = 0;
};