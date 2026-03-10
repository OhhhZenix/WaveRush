#pragma once

#include "WaveRush/Core/Window.hpp"
#include "WaveRush/Entity/EntityManager.hpp"
#include "WaveRush/SceneManager.hpp"

namespace WaveRush {

class Game {
  public:
    ~Game() = default;
    auto GetWindow() -> Window&;
    auto GetSceneManager() -> SceneManager&;
    auto GetEntityManager() -> EntityManager&;
    auto Run() -> void;

  private:
    Window window_;
    SceneManager scene_manager_;
    EntityManager entity_manager_ {1'000};
};

} // namespace WaveRush
