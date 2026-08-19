#pragma once

#include <SDL3/SDL.h>

namespace wr {

class App {
 public:
  App() = default;
  ~App();
  App(const App&) = delete;
  App& operator=(const App&) = delete;
  App(App&&) = delete;
  App& operator=(App&&) = delete;
  SDL_AppResult init();
  SDL_AppResult iterate();
  SDL_AppResult event(SDL_Event* event);

 private:
  SDL_Window* window_;
  SDL_GPUDevice* gpu_;
};

};  // namespace wr