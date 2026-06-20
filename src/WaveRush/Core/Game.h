#pragma once

#include <SDL3/SDL.h>

#include "WaveRush/Entity/World.h"

namespace wr {

struct Game {
 public:
  Game();
  ~Game();
  Game(const Game&) = delete;             // copy constructor
  Game& operator=(const Game&) = delete;  // copy assignment operator
  Game(Game&&) = delete;                  // move constructor
  Game& operator=(Game&&) = delete;       // move assignment operator

  auto run() -> void;

 private:
  wr_world world_;
  SDL_Window* window_;
  SDL_GPUDevice* gpu_;
  bool running_;
};

}  // namespace wr