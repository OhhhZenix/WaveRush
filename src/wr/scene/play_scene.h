#pragma once

#include "wr/core/array_list.h"
#include "wr/entity/player.h"

typedef struct play_scene PlayScene;

struct play_scene {
  Player player;
  ArrayList bouncers;
};

void wr_play_scene_init(PlayScene *self);
void wr_play_scene_update(PlayScene *self);
void wr_play_scene_draw(PlayScene *self);