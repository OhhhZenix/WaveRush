#pragma once

#include "WaveRush/Widget.hpp"
#include "raylib.h"

namespace WaveRush {

class Button: public Widget {
  public:
    Button(
        int x = 0,
        int y = 0,
        int width = 120,
        int height = 60,
        Color color = WHITE,
        Color hoverColor = LIGHTGRAY
    );
    bool IsHovered();
    bool IsLeftClicked();
    bool IsRightClicked();
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;
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
