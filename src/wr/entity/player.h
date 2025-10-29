#pragma once

struct wr_player
{
  float x;
  float y;
  float width;
  float height;
};

void wr_player_init (wr_player *self, float x, float y);
void wr_player_move (wr_player *self);
void wr_player_draw (wr_player *self);