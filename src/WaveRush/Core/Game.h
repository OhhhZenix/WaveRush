#pragma once

#include <SDL3/SDL.h>

#include "WaveRush/Core/IndexBuffer.h"
#include "WaveRush/Core/Shader.h"
#include "WaveRush/Core/VertexArray.h"
#include "WaveRush/Core/VertexBuffer.h"
#include "WaveRush/Entity/World.h"

struct wr_game {
  wr_world world;
  wr_arena main_allocator;
  wr_arena frame_allocator;

  SDL_Window* window;
  SDL_GLContext gl;

  wr_shader shader;
  wr_vertex_array vertex_array;
  wr_vertex_buffer vertex_buffer;
  wr_index_buffer index_buffer;

  float elapsed_time;
};

SDL_AppResult wr_game_init(wr_game* game);
SDL_AppResult wr_game_iterate(wr_game* game);
SDL_AppResult wr_game_event(wr_game* game, SDL_Event* event);
void wr_game_cleanup(wr_game* game);
