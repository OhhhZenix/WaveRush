#include "Game.h"

#include <SDL3/SDL_init.h>
#include <glad/glad.h>

#include <glm/glm.hpp>

#include "WaveRush/Core/Arena.h"
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
  wr_renderer_init(&game->renderer);

  return SDL_APP_CONTINUE;
}

SDL_AppResult wr_game_iterate(wr_game* game) {
  wr_arena_reset(&game->frame_allocator);
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  wr_renderer_draw_rect(&game->renderer, glm::vec2(-0.5f, -0.5f),
                        glm::vec2(1.0f, 1.0f),
                        glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
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
  wr_renderer_cleanup(&game->renderer);
  SDL_GL_DestroyContext(game->gl);
  SDL_DestroyWindow(game->window);
  SDL_Quit();
  wr_arena_cleanup(&game->frame_allocator);
  wr_arena_cleanup(&game->main_allocator);
}
