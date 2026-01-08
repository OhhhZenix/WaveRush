#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

auto Label::SetText(std::string text) -> void {
    this->text = text;
}

auto Label::SetFontSize(int font_size) -> void {
    this->font_size = font_size;
}

auto Label::SetColor(Color color) -> void {
    this->color = color;
}

auto Label::GetX() const -> int {
    return this->x;
}

auto Label::SetX(int x) -> void {
    this->x = x;
}

auto Label::GetY() const -> int {
    return this->y;
}

auto Label::SetY(int y) -> void {
    this->y = y;
}

auto Label::Update(Game& game) -> void {}

auto Label::Render() -> void {
    if (this->text.empty())
        return;

    DrawText(text.c_str(), this->x, this->y, this->font_size, this->color);
}

} // namespace WaveRush
