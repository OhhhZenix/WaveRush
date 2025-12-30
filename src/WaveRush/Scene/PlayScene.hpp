#pragma once

#include "WaveRush/Scene.hpp"

namespace WaveRush {

class PlayScene: public Scene {
  public:
    PlayScene();
    void Update(Game& game) override;
    void Render() override;

  private:
};

} // namespace WaveRush
