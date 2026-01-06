#pragma once

#include <raylib.h>

#include "WaveRush/EntityManager.hpp"
#include "WaveRush/Scene.hpp"
#include "WaveRush/WidgetManager.hpp"

namespace WaveRush {

class MainMenuScene: public Scene {
  public:
    MainMenuScene();
    void Update(Game& game) override;
    void Render() override;

  private:
    EntityManager entity_manager;
    WidgetManager widget_manager;
};

} // namespace WaveRush
