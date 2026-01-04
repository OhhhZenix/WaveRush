#pragma once

#include <raylib.h>

#include <functional>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class Button: public Widget {
  public:
    using Callback = std::function<void(Button&, Game&)>;

    Button(
        int x = 0,
        int y = 0,
        int width = 120,
        int height = 60,
        Color color = WHITE,
        Color hoverColor = LIGHTGRAY,
        Callback on_click = [](Button&, Game&) {}
    );
    bool IsHovered();
    bool IsLeftClicked();
    bool IsRightClicked();
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;
    void SetX(int x);
    void SetY(int y);
    void SetWidth(int width);
    void SetHeight(int height);
    void Update(Game& game) override;
    void Render() override;

  private:
    Rectangle bounds;
    Color color;
    Color hover_color;
    Callback on_click;
};

} // namespace WaveRush
