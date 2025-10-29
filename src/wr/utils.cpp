#include "wr/utils.h"

float
clampf (float value, float min, float max)
{
  if (value < min)
    return min;
  if (value > max)
    return max;
  return value;
}

bool
wr_collision_rect_circle (float rx, float ry, float rw, float rh, float cx,
                          float cy, float r)
{
  float closestX = clampf (cx, rx, rx + rw);
  float closestY = clampf (cy, ry, ry + rh);

  float dx = cx - closestX;
  float dy = cy - closestY;

  return (dx * dx + dy * dy) <= (r * r);
}