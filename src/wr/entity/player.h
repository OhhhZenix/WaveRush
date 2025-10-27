#pragma once

struct Player
{
  float x;
  float y;
  float width;
  float height;
};

void wr_player_init (Player *self, float x, float y);
void wr_player_move (Player *self);
void wr_player_draw (Player *self);