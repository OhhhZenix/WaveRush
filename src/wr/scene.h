#pragma once

#include "wr/array_list.h"
#include "wr/entity.h"

enum wr_scene {
    WR_SCENE_MENU = 0,
    WR_SCENE_PLAY = 1,
    WR_SCENE_COUNT,
};

struct wr_menu_scene {};

struct wr_play_scene {
    wr_player player;
    wr_array_list bouncers;
};

void wr_play_scene_init(wr_play_scene* self);

void wr_play_scene_update(wr_play_scene* self, wr_scene* current_scene);

void wr_play_scene_draw(wr_play_scene* self);
