#pragma once

#include "WaveRush/SceneManager.hpp"

namespace WaveRush {

class Scene;

class Game {
  public:
    SceneManager& GetSceneManager();
    void Close();
    void Run();

  private:
    bool should_close = false;
    SceneManager scene_manager;
};

} // namespace WaveRush
