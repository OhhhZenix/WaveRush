#include "WaveRush/Vec2f.h"

void vec2f_add(Vec2f* a, Vec2f* b) {
    a->x += b->x;
    a->y += b->y;
}