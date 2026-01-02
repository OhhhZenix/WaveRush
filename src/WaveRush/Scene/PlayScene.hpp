#pragma once

#include "WaveRush/EntityManager.hpp"
#include "WaveRush/Scene.hpp"

namespace WaveRush {

class PlayScene: public Scene {
  public:
    PlayScene();
    void Update(Game& game) override;
    void Render() override;

  private:
    EntityManager entity_manager;
};

} // namespace WaveRush
