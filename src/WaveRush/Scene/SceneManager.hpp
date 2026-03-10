#pragma once

#include <memory>
#include <stack>

namespace WaveRush {

class Game;

class Scene {
  public:
    virtual ~Scene() = default;
    virtual auto Update(Game& game) -> void = 0;
    virtual auto Render() -> void = 0;
};

class SceneManager {
  public:
    auto HasScenes() const -> bool;
    auto GetCurrentScene() -> Scene&;
    auto GotoPreviousScene() -> void;
    auto GotoNextScene(Scene* scene) -> void;
    auto Update(Game& game) -> void;
    auto Render() -> void;

  private:
    std::stack<std::unique_ptr<Scene>> scenes_;
};

} // namespace WaveRush
