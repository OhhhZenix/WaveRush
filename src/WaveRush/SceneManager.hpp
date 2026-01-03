#pragma once

#include <memory>
#include <stack>

namespace WaveRush {

class Scene;
class Game;

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
