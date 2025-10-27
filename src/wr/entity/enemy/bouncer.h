#pragma once

struct Bouncer
{
  float x;
  float y;
  float radius;
  float speed_x;
  float speed_y;
};

void wr_bouncer_init (Bouncer *self, float x, float y);
void wr_bouncer_update (Bouncer *self);
void wr_bouncer_draw (Bouncer *self);