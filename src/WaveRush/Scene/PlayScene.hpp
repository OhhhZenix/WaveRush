#pragma once

#include "WaveRush/Entity/BasicEnemy.hpp"
#include "WaveRush/Entity/Player.hpp"
#include <vector>

struct PlayScene {
	Player player;
	std::vector<BasicEnemy> basic_enemies;
};

void play_scene_init(PlayScene* self);
void play_scene_update(PlayScene* self);
void play_scene_render(PlayScene* self);