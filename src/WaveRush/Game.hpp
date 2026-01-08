#pragma once

#include "WaveRush/SceneManager.hpp"

namespace WaveRush {

class Game {
  public:
    ~Game() = default;
    auto GetSceneManager() -> SceneManager&;
    auto Close() -> void;
    auto Run() -> void;

  private:
    bool should_close = false;
    SceneManager scene_manager;
};

} // namespace WaveRush
