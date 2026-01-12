#pragma once

#include <memory>
#include <stack>

#include "WaveRush/Scene.hpp"

namespace WaveRush {

class SceneManager {
  public:
    auto HasScenes() const -> bool;
    auto GetCurrentScene() -> Scene&;
    auto GotoPreviousScene() -> void;
    auto GotoNextScene(Scene* scene) -> void;
    auto Update(Game& game) -> void;
    auto Render() -> void;

  private:
    std::stack<std::unique_ptr<Scene>> m_scenes;
};

} // namespace WaveRush
