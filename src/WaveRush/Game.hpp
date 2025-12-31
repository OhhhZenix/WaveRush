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
    void Close();
    void Run();

  private:
    bool should_close = false;
    std::stack<std::unique_ptr<Scene>> scene;
};

} // namespace WaveRush
