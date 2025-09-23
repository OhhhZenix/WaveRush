#include "WaveRush/Scene/PlayScene.hpp"

void play_scene_init(PlayScene* self) {
	self->wave = 1;

	player_init(&self->player);

	self->basic_enemies.clear();
	self->basic_enemies.push_back({});
	for (auto& enemy : self->basic_enemies) {
		basic_enemy_init(&enemy);
	}
}

void play_scene_update(PlayScene* self) {
	player_update(&self->player);

	for (auto& enemy : self->basic_enemies) {
		basic_enemy_update(&enemy);
	}
}

void play_scene_render(PlayScene* self) {
	player_render(&self->player);

	for (auto& enemy : self->basic_enemies) {
		basic_enemy_render(&enemy);
	}
}