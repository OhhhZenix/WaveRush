#pragma once

#include <memory>
#include <stack>

namespace WaveRush {

class Scene;

class Game {
  public:
    Game();
    ~Game();
    void GotoPreviousScene();
    void GotoNextScene(Scene* scene);
    bool IsRunning();
    void SetRunning(bool value);
    void Run();

  private:
    bool running = false;
    std::stack<std::unique_ptr<Scene>> scene;
};

} // namespace WaveRush
