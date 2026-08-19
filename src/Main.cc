#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL_main.h>

#include "WaveRush/App.h"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
  wr::App* App = new wr::App();

  if (App == nullptr) {
    return SDL_APP_FAILURE;
  }

  *appstate = App;

  return App->init();
}

SDL_AppResult SDL_AppIterate(void* appstate) {
  wr::App* App = (wr::App*)appstate;
  return App->iterate();
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
  wr::App* App = (wr::App*)appstate;
  return App->event(event);
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
  if (appstate != nullptr) {
    wr::App* App = (wr::App*)appstate;
    delete App;
  }
}
