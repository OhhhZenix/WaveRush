#include "wr/utils.h"

float wr_clampf(float value, float min, float max) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

bool wr_collision_rect_circle(
    float rect_x,
    float rect_y,
    float rect_width,
    float rect_height,
    float circle_x,
    float circle_y,
    float circle_radius
) {
    float closest_x = wr_clampf(circle_x, rect_x, rect_x + rect_width);
    float closest_y = wr_clampf(circle_y, rect_y, rect_y + rect_height);

    float dx = circle_x - closest_x;
    float dy = circle_y - closest_y;

    return (dx * dx + dy * dy) <= (circle_radius * circle_radius);
}