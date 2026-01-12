#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

auto Label::SetText(std::string text) -> void {
    m_text = text;
}

auto Label::SetFontSize(int font_size) -> void {
    m_font_size = font_size;
}

auto Label::SetColor(Color color) -> void {
    m_color = color;
}

auto Label::GetX() const -> int {
    return m_x;
}

auto Label::SetX(int x) -> void {
    m_x = x;
}

auto Label::GetY() const -> int {
    return m_y;
}

auto Label::SetY(int y) -> void {
    m_y = y;
}

auto Label::Update(Game& game) -> void {}

auto Label::Render() -> void {
    if (m_text.empty())
        return;

    DrawText(m_text.c_str(), m_x, m_y, m_font_size, m_color);
}

} // namespace WaveRush
