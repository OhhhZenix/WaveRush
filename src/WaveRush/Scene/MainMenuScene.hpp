#pragma once

#include <raylib.h>

#include "WaveRush/EntityManager.hpp"
#include "WaveRush/Scene.hpp"
#include "WaveRush/WidgetManager.hpp"

namespace WaveRush {

class MainMenuScene: public Scene {
  public:
    MainMenuScene();
    auto Update(Game& game) -> void override;
    auto Render() -> void override;

  private:
    EntityManager entity_manager_;
    WidgetManager widget_manager_;
};

} // namespace WaveRush
