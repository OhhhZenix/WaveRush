#pragma once

float wr_clampf(float value, float min, float max);

bool wr_collision_rect_circle(
    float rect_x,
    float rect_y,
    float rect_width,
    float rect_height,
    float cirle_x,
    float circle_y,
    float circle_radius
);