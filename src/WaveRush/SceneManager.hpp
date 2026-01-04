#pragma once

#include <memory>
#include <stack>

#include "WaveRush/Scene.hpp"

namespace WaveRush {

class SceneManager {
  public:
    bool HasScenes();
    Scene& GetCurrentScene();
    void GotoPreviousScene();
    void GotoNextScene(Scene* scene);
    void Update(Game& game);
    void Render();

  private:
    std::stack<std::unique_ptr<Scene>> scenes;
};

} // namespace WaveRush
