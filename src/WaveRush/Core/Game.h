#pragma once

#include <SDL3/SDL.h>

#include "WaveRush/Entity/World.h"

struct wr_game {
  wr_world world;
  wr_arena arena;

  SDL_Window* window;
  SDL_GPUDevice* gpu;
  SDL_GPUBuffer* vertex_buffer;
  SDL_GPUTransferBuffer* transfer_buffer;
  SDL_GPUGraphicsPipeline* graphics_pipeline;

  bool running;
};

void wr_game_init(wr_game* game);
void wr_game_cleanup(wr_game* game);
void wr_game_run(wr_game* game);
