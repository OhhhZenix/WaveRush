#pragma once

#include "WaveRush/EntityManager.hpp"
#include "WaveRush/Scene.hpp"
#include "WaveRush/WidgetManager.hpp"

namespace WaveRush {

class PlayScene: public Scene {
  public:
    PlayScene();
    void Update(Game& game) override;
    void Render() override;

  private:
    EntityManager entity_manager;
    WidgetManager widget_manager;
    bool paused = false;
};

} // namespace WaveRush
