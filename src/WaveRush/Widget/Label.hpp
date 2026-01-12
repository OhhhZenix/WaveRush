#pragma once

#include <raylib.h>

#include <string>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class Label: public Widget {
  public:
    auto SetText(std::string text) -> void;
    auto SetFontSize(int font_size) -> void;
    auto SetColor(Color color) -> void;

    auto GetX() const -> int;
    auto SetX(int x) -> void;

    auto GetY() const -> int;
    auto SetY(int y) -> void;

    auto Update(Game& game) -> void override;
    auto Render() -> void override;

  private:
    std::string m_text = "";
    int m_font_size = 12;
    Color m_color = BLACK;
    int m_x = 0;
    int m_y = 0;
};

} // namespace WaveRush
