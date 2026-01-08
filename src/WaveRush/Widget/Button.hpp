#pragma once

#include <raylib.h>

#include <functional>
#include <string>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class Button: public Widget {
  public:
    using Callback = std::function<void(Button&, Game&)>;

    auto IsHovered() const -> bool;
    auto IsLeftClicked() const -> bool;
    auto IsRightClicked() const -> bool;

    auto GetX() const -> int;
    auto SetX(int x) -> void;

    auto GetY() const -> int;
    auto SetY(int y) -> void;

    auto GetWidth() const -> int;
    auto SetWidth(int width) -> void;

    auto GetHeight() const -> int;
    auto SetHeight(int height) -> void;

    auto SetOnClick(Callback on_click) -> void;
    auto SetText(std::string text) -> void;
    auto SetFontSize(int font_size) -> void;

    auto Update(Game& game) -> void override;
    auto Render() -> void override;

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
    std::string text = "";
    int font_size = 12;
};

} // namespace WaveRush
