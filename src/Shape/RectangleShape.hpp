#pragma once

#include "Core/PCH.hpp"
#include "Math/Vec2.hpp"

struct RectangleShape {
	SDL_Color Color = { 0, 0, 0, 255 };
	Vec2<float> Size = Vec2<float>(0, 0);
	SDL_Color OutlineColor = { 0, 0, 0, 255 };
	int32_t OutlineThickness = 0;
};