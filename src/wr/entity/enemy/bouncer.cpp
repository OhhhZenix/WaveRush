#include "wr/entity/enemy/bouncer.h"
#include "wr/constants.h"
#include <raylib.h>

void wr_bouncer_init(Bouncer *self, float x, float y) {
  self->x = x;
  self->y = y;
  self->radius = 16.0f;
  self->speed_x = 2.0f;
  self->speed_y = 2.0f;
}

void wr_bouncer_update(Bouncer *self) {
  self->x += self->speed_x;
  self->y += self->speed_y;

  if (self->x <= self->radius || self->x >= GAME_WIDTH - self->radius) {
    self->speed_x = -self->speed_x;
  }

  if (self->y <= self->radius || self->y >= GAME_HEIGHT - self->radius) {
    self->speed_y = -self->speed_y;
  }
}

void wr_bouncer_draw(Bouncer *self) {
  DrawCircle(self->x, self->y, self->radius, GREEN);
}
