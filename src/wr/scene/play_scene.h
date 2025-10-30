#pragma once

#include "wr/core/array_list.h"
#include "wr/entity/player.h"

struct wr_play_scene {
    wr_player player;
    wr_array_list bouncers;
};

void wr_play_scene_init(wr_play_scene* self);

void wr_play_scene_update(wr_play_scene* self);

void wr_play_scene_draw(wr_play_scene* self);