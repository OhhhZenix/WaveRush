#pragma once

#include "WaveRush/Core/Window.hpp"
#include "WaveRush/SceneManager.hpp"

namespace WaveRush {

class Game {
  public:
    ~Game() = default;
    auto GetWindow() -> Window&;
    auto GetSceneManager() -> SceneManager&;
    auto Run() -> void;

  private:
    Window m_window;
    SceneManager m_scene_manager;
};

} // namespace WaveRush
