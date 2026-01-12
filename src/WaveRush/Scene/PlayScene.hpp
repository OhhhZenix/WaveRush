#pragma once

#include "WaveRush/EntityManager.hpp"
#include "WaveRush/Scene.hpp"
#include "WaveRush/WidgetManager.hpp"

namespace WaveRush {

class PlayScene: public Scene {
  public:
    PlayScene();
    auto Update(Game& game) -> void override;
    auto Render() -> void override;

  private:
    EntityManager m_entity_manager;
    WidgetManager m_widget_manager;
    bool m_paused = false;
};

} // namespace WaveRush
