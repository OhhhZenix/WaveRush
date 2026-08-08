#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL_main.h>

#include "WaveRush/Core/Game.h"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
  wr_game* game = (wr_game*)malloc(sizeof(wr_game));

  if (game == nullptr) {
    return SDL_APP_FAILURE;
  }

  *appstate = game;

  return wr_game_init(game);
}

SDL_AppResult SDL_AppIterate(void* appstate) {
  wr_game* game = (wr_game*)appstate;
  return wr_game_iterate(game);
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
  wr_game* game = (wr_game*)appstate;
  return wr_game_event(game, event);
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
  if (appstate != nullptr) {
    wr_game* game = (wr_game*)appstate;
    wr_game_cleanup(game);
    free(game);
  }
}
