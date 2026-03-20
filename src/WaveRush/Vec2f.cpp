#include "WaveRush/Vec2f.h"

Vec2f vec2f_add(Vec2f* a, Vec2f* b) {
    return Vec2f {
        .x = a->x + b->x,
        .y = a->y + b->y,
    };
}