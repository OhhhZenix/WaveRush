#pragma once

#include <raylib.h>

#include "WaveRush/Scene/SceneManager.hpp"
#include "WaveRush/WidgetManager.hpp"

namespace WaveRush {

class MainMenuScene: public Scene {
  public:
    MainMenuScene(Game& game);
    auto Update(Game& game) -> void override;
    auto Render() -> void override;

  private:
    WidgetManager widget_manager_;
};

} // namespace WaveRush
