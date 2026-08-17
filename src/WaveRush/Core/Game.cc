#include "Game.h"

#include <SDL3/SDL_init.h>
#include <glad/glad.h>

#include <cmath>
#include <glm/glm.hpp>

#include "WaveRush/Core/Arena.h"
#include "WaveRush/Core/Shader.h"
#include "WaveRush/Entity/World.h"

SDL_AppResult wr_game_init(wr_game* game) {
  wr_arena_init(&game->main_allocator, 1024 * 1024);
  wr_arena_init(&game->frame_allocator, 1024 * 1024);

  if (SDL_Init(SDL_INIT_VIDEO) == false) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  game->window = SDL_CreateWindow("WaveRush", 640, 360, SDL_WINDOW_OPENGL);

  if (game->window == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  game->gl = SDL_GL_CreateContext(game->window);

  if (game->gl == nullptr) {
    SDL_Log("Failed to create OpenGL context: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    SDL_Log("Failed to initialize Glad: No GL driver has been loaded");
    return SDL_APP_FAILURE;
  }

  SDL_Log("OpenGL version: %s", glGetString(GL_VERSION));

  wr_world_init(&game->world, &game->main_allocator, 1024);

  wr_shader_from_file(&game->shader, &game->frame_allocator,
                      "assets/shaders/default.vert",
                      "assets/shaders/default.frag");
  wr_shader_bind(&game->shader);

  // Initialize triangle vertices
  float vertices[] = {
      -0.5f, -0.5f, 0.0f,  // bottom left
      0.5f,  -0.5f, 0.0f,  // bottom right
      0.0f,  0.5f,  0.0f   // top
  };

  wr_vertex_array_init(&game->vertex_array);
  wr_vertex_buffer_init(&game->vertex_buffer, vertices, sizeof(vertices),
                        GL_STATIC_DRAW);

  wr_vertex_array_link_attribute(&game->vertex_array, &game->vertex_buffer, 0,
                                 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

  game->elapsed_time = 0.0f;

  return SDL_APP_CONTINUE;
}

SDL_AppResult wr_game_iterate(wr_game* game) {
  wr_arena_reset(&game->frame_allocator);
  game->elapsed_time += 0.016f;  // ~60 FPS

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Animate color over time
  float red = (std::sin(game->elapsed_time * 0.5f) + 1.0f) / 2.0f;
  float green = (std::sin(game->elapsed_time * 0.5f + 2.094f) + 1.0f) /
                2.0f;  // 2π/3 phase offset
  float blue = (std::sin(game->elapsed_time * 0.5f + 4.189f) + 1.0f) /
               2.0f;  // 4π/3 phase offset

  // wr_shader_bind(&game->shader);
  wr_shader_set_float4(&game->shader, "ourColor",
                       glm::vec4(red, green, blue, 1.0f));

  wr_vertex_array_bind(&game->vertex_array);
  glDrawArrays(GL_TRIANGLES, 0, 3);

  SDL_GL_SwapWindow(game->window);
  return SDL_APP_CONTINUE;
}

SDL_AppResult wr_game_event(wr_game* game, SDL_Event* event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }

  return SDL_APP_CONTINUE;
}

void wr_game_cleanup(wr_game* game) {
  wr_vertex_buffer_cleanup(&game->vertex_buffer);
  wr_vertex_array_cleanup(&game->vertex_array);
  SDL_GL_DestroyContext(game->gl);
  SDL_DestroyWindow(game->window);
  SDL_Quit();
  wr_arena_cleanup(&game->frame_allocator);
  wr_arena_cleanup(&game->main_allocator);
}
