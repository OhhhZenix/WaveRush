#include "App.h"

#include <SDL3/SDL.h>
#include <SDL3_shadercross/SDL_shadercross.h>

#include <glm/glm.hpp>

namespace wr {

App::~App() {
  SDL_ReleaseWindowFromGPUDevice(gpu_, window_);
  SDL_DestroyGPUDevice(gpu_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

SDL_AppResult App::init() {
  if (SDL_Init(SDL_INIT_VIDEO) == false) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  window_ = SDL_CreateWindow("WaveRush", 640, 360, SDL_WINDOW_OPENGL);

  if (window_ == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  gpu_ = SDL_CreateGPUDevice(SDL_ShaderCross_GetSPIRVShaderFormats(), false,
                             nullptr);

  if (gpu_ == nullptr) {
    SDL_Log("Failed to create GPU device: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  if (SDL_ClaimWindowForGPUDevice(gpu_, window_) == false) {
    SDL_Log("Failed to claim window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_Log("%s", SDL_GetGPUDeviceDriver(gpu_));

  return SDL_APP_CONTINUE;
}

SDL_AppResult App::iterate() { return SDL_APP_CONTINUE; }

SDL_AppResult App::event(SDL_Event* event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }

  return SDL_APP_CONTINUE;
}

}  // namespace wr