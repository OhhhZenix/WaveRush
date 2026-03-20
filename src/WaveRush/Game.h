#pragma once

#define GAME_WIDTH 640
#define GAME_HEIGHT 360

struct EntityManager;
struct Arena;

struct Game {
    EntityManager* entity_manager;
};

void wr_game_run(void);