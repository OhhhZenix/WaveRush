#pragma once

#include <functional>

#include "WaveRush/Widget.hpp"
#include "raylib.h"

namespace WaveRush {

class Button: public Widget {
  public:
    Button(
        int x = 0,
        int y = 0,
        int width = 120,
        int height = 120,
        Color color = WHITE,
        Color hoverColor = GRAY
    );
    bool IsHovered();
    void OnClick(int button, std::function<void()> action);
    void OnClickAny(int buttons[], std::function<void()> action);
    void Render() override;

  private:
    float x;
    float y;
    float width;
    float height;
    Color color;
    Color hoverColor;
};

} // namespace WaveRush
