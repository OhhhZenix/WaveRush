#pragma once

#include <raylib.h>

#include <vector>

#include "WaveRush/Scene.hpp"
#include "WaveRush/WidgetManager.hpp"

namespace WaveRush {

class MainMenuScene: public Scene {
  public:
    MainMenuScene();
    void Update(Game& game) override;
    void Render() override;

  private:
    struct Rect {
        float x;
        float y;
        float w;
        float h;
        Color color;
        float vel_x;
        float vel_y;
    };

    std::vector<Rect> rects;
    WidgetManager widget_manager;
};

} // namespace WaveRush
