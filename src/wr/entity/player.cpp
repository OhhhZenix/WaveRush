#include "wr/entity/player.h"
#include <raylib.h>

void wr_player_init(Player *self, float x, float y) {
  self->x = x;
  self->y = y;
  self->width = 32;
  self->height = 32;
}

void wr_player_move(Player *self) {
  const float speed = 2.0f;

  if (IsKeyDown(KEY_W)) {
    self->y -= speed;
  }

  if (IsKeyDown(KEY_S)) {
    self->y += speed;
  }

  if (IsKeyDown(KEY_A)) {
    self->x -= speed;
  }

  if (IsKeyDown(KEY_D)) {
    self->x += speed;
  }
}

void wr_player_draw(Player *self) {
  DrawRectangle(self->x, self->y, self->width, self->height, BLUE);
}