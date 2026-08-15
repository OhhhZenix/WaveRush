#pragma once

#include <SDL3/SDL.h>

#include "WaveRush/Entity/World.h"

struct wr_game {
  wr_world world;
  wr_arena main_allocator;
  wr_arena frame_allocator;

  SDL_Window* window;
  SDL_GLContext gl;
};

SDL_AppResult wr_game_init(wr_game* game);
SDL_AppResult wr_game_iterate(wr_game* game);
SDL_AppResult wr_game_event(wr_game* game, SDL_Event* event);
void wr_game_cleanup(wr_game* game);
