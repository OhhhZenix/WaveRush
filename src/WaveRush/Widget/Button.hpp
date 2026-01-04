#pragma once

#include <raylib.h>

#include <functional>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class Button: public Widget {
  public:
    using Callback = std::function<void(Button&, Game&)>;

    bool IsHovered();
    bool IsLeftClicked();
    bool IsRightClicked();

    int GetX() const;
    void SetX(int x);

    int GetY() const;
    void SetY(int y);

    int GetWidth() const;
    void SetWidth(int width);

    int GetHeight() const;
    void SetHeight(int height);

    void SetOnClick(Callback on_click);

    void Update(Game& game) override;
    void Render() override;

  private:
    Rectangle bounds = {
        .x = 0,
        .y = 0,
        .width = 24,
        .height = 24,
    };
    Color color = WHITE;
    Color hover_color = LIGHTGRAY;
    Callback on_click = {};
};

} // namespace WaveRush
