#pragma once

#include "WaveRush/Core/Types.hpp"
#include "WaveRush/Entity/BasicEnemy.hpp"
#include "WaveRush/Entity/Player.hpp"
#include <vector>

struct PlayScene {
	u32 wave;
	Player player;
	std::vector<BasicEnemy> basic_enemies;
};

void play_scene_init(PlayScene* self);
void play_scene_update(PlayScene* self);
void play_scene_render(PlayScene* self);