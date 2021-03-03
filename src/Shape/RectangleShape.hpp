#pragma once

#include "Core/PCH.hpp"
#include "Math/Vec2.hpp"

struct RectangleShape {
    SDL_Color Color = {0, 0, 0, 255};
    Vec2f Size = Vec2f(0, 0);
    SDL_Color OutlineColor = {0, 0, 0, 255};
    int32_t OutlineThickness = 0;
};